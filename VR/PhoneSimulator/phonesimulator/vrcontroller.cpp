#include "vrcontroller.h"
#include <QOpenGLFramebufferObjectFormat>
#include <QOpenGLPaintDevice>
#include <QPainter>
#include <QtWidgets/QWidget>
#include <QMouseEvent>
#include <QtWidgets/QGraphicsSceneMouseEvent>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsEllipseItem>
#include <QCursor>

using namespace vr;


vrController *s_pSharedVRController = NULL;

vrController *vrController::SharedInstance()
{
    if ( !s_pSharedVRController )
    {
        s_pSharedVRController = new vrController();
    }
    return s_pSharedVRController;
}



vrController::vrController()
    : BaseClass()
    , m_eLastHmdError( vr::VRInitError_None )
    , m_eCompositorError( vr::VRInitError_None )
    , m_eOverlayError( vr::VRInitError_None )
    , m_strVRDriver( "No Driver" )
    , m_strVRDisplay( "No Display" )
    , m_pOpenGLContext( NULL )
    , m_pScene( NULL )
    , m_pOffscreenSurface ( NULL )
    , m_pFbo( NULL )
    , m_pWidget( NULL )
    , m_pPumpEventsTimer( NULL )
    , m_lastMouseButtons( 0 )
    , m_ulOverlayHandle( vr::k_ulOverlayHandleInvalid )
    , m_bManualMouseHandling( false )
{
}



vrController::~vrController()
{
}


void vrController::showNotification(QString notificationText){

/* From header file */
    //virtual EVRNotificationError CreateNotification( VROverlayHandle_t ulOverlayHandle,
    //uint64_t ulUserValue,
    //EVRNotificationType type,
    //const char *pchText,
    //EVRNotificationStyle style,
    //const NotificationBitmap_t *pImage,
    /* out */ //VRNotificationId *pNotificationId ) = 0;


    //Create IVRNotifications object
    //TODO handle error parameter
    vr::IVRNotifications* notifs = (vr::IVRNotifications*)vr::VR_GetGenericInterface(vr::IVRNotifications_Version, NULL);

    //notification id assigned by the system
    vr::VRNotificationId notifId;

    //convert QString to const char*
    QByteArray ba = notificationText.toLatin1();
    const char *c_str2 = ba.data();

    //TODO (in polish GUI) create bitmap for notification
    notifs->CreateNotification(m_ulOverlayHandle, 69, vr::EVRNotificationType_Transient,
                               c_str2, vr::EVRNotificationStyle_None, NULL, &notifId);

}




void vrController:: showKeyboard(){
    //from header file
    /** Show the virtual keyboard to accept input **/
    //		virtual EVROverlayError ShowKeyboard( EGamepadTextInputMode eInputMode,
//    EGamepadTextInputLineMode eLineInputMode,
//            const char *pchDescription,
//            uint32_t unCharMax,
//            const char *pchExistingText,
//            bool bUseMinimalMode, uint64_t uUserValue ) = 0;
    //virtual EVROverlayError ShowKeyboardForOverlay( VROverlayHandle_t ulOverlayHandle,
    //                                                EGamepadTextInputMode eInputMode,
    //                                                EGamepadTextInputLineMode eLineInputMode,
    //                                                const char *pchDescription,
    //                                                uint32_t unCharMax,
    //                                                const char *pchExistingText,
    //                                                bool bUseMinimalMode,
    //                                                uint64_t uUserValue ) = 0;//possible flags about the user input?


    vr::VROverlay()->ShowKeyboardForOverlay(m_ulOverlayHandle,//handle to our overlay
                                            vr::k_EGamepadTextInputModeNormal,//normal, password, or submit
                                            vr::k_EGamepadTextInputLineModeMultipleLines,//single or multiple
                                            "Whats a pch description",//unsure still
                                            1024,//max number of chars
                                            "",//any text you would like to start already typed
                                            false,//minimal mode
                                            0);//possible user defined flags
}

void vrController::onNotificationPosted(QJsonObject notif)
{
    //check if overlay is in view or not
    if(!vr::VROverlay()->IsOverlayVisible(m_ulOverlayHandle)){
        //if not, show notification popup
        this->showNotification(notif["message"].toString());
    }
}




QString GetTrackedDeviceString( vr::IVRSystem *pHmd, vr::TrackedDeviceIndex_t unDevice, vr::TrackedDeviceProperty prop )
{
    char buf[128];
    vr::TrackedPropertyError err;
    pHmd->GetStringTrackedDeviceProperty( unDevice, prop, buf, sizeof( buf ), &err );
    if( err != vr::TrackedProp_Success )
    {
        return QString( "Error Getting String: " ) + pHmd->GetPropErrorNameFromEnum( err );
    }
    else
    {
        return buf;
    }
}



bool vrController::Init()
{
    bool bSuccess = true;

    m_strName = "Phone Simulator";

    QStringList arguments = qApp->arguments();

    int nNameArg = arguments.indexOf( "-name" );
    if( nNameArg != -1 && nNameArg + 2 <= arguments.size() )
    {
        m_strName = arguments.at( nNameArg + 1 );
    }

    QSurfaceFormat format;
    format.setMajorVersion( 4 );
    format.setMinorVersion( 1 );
    format.setProfile( QSurfaceFormat::CompatibilityProfile );

    m_pOpenGLContext = new QOpenGLContext();
    m_pOpenGLContext->setFormat( format );
    bSuccess = m_pOpenGLContext->create();
    if( !bSuccess )
        return false;

    // create an offscreen surface to attach the context and FBO to
    m_pOffscreenSurface = new QOffscreenSurface();
    m_pOffscreenSurface->create();
    m_pOpenGLContext->makeCurrent( m_pOffscreenSurface );

    m_pScene = new QGraphicsScene();
    connect( m_pScene, SIGNAL(changed(const QList<QRectF>&)), this, SLOT( OnSceneChanged(const QList<QRectF>&)) );

    // Loading the OpenVR Runtime
    bSuccess = ConnectToVRRuntime();

    bSuccess = bSuccess && vr::VRCompositor() != NULL;

    if( vr::VROverlay() )
    {
        std::string sKey = std::string( "sample." ) + m_strName.toStdString();
        vr::VROverlayError overlayError = vr::VROverlay()->CreateDashboardOverlay( sKey.c_str(), m_strName.toStdString().c_str(), &m_ulOverlayHandle, &m_ulOverlayThumbnailHandle );
        bSuccess = bSuccess && overlayError == vr::VROverlayError_None;
    }

    if( bSuccess )
    {
        vr::VROverlay()->SetOverlayWidthInMeters( m_ulOverlayHandle, 1.5f );
        vr::VROverlay()->SetOverlayInputMethod( m_ulOverlayHandle, vr::VROverlayInputMethod_Mouse );

        /** Sets the alpha of the overlay quad. Use 1.0 for 100 percent opacity to 0.0 for 0 percent opacity. */
        vr::VROverlay()->SetOverlayAlpha(m_ulOverlayHandle, 0.4f);

        m_pPumpEventsTimer = new QTimer( this );
        connect(m_pPumpEventsTimer, SIGNAL( timeout() ), this, SLOT( OnTimeoutPumpEvents() ) );
        m_pPumpEventsTimer->setInterval( 20 );
        m_pPumpEventsTimer->start();

    }

    return true;
}





void vrController::Shutdown()
{
    DisconnectFromVRRuntime();

    delete m_pScene;
    delete m_pFbo;
    delete m_pOffscreenSurface;

    if( m_pOpenGLContext )
    {
        delete m_pOpenGLContext;
        m_pOpenGLContext = NULL;
    }
}




void vrController::OnSceneChanged( const QList<QRectF>& )
{
    // skip rendering if the overlay isn't visible
    if( !vr::VROverlay() ||
        ( !vr::VROverlay()->IsOverlayVisible( m_ulOverlayHandle ) && !vr::VROverlay()->IsOverlayVisible( m_ulOverlayThumbnailHandle ) ) )
        return;

    m_pOpenGLContext->makeCurrent( m_pOffscreenSurface );
    m_pFbo->bind();

    QOpenGLPaintDevice device( m_pFbo->size() );
    QPainter painter( &device );

    m_pScene->render( &painter );

    m_pFbo->release();

    GLuint unTexture = m_pFbo->texture();
    if( unTexture != 0 )
    {
        vr::Texture_t texture = {(void*)(uintptr_t)unTexture, vr::TextureType_OpenGL, vr::ColorSpace_Auto };
        vr::VROverlay()->SetOverlayTexture( m_ulOverlayHandle, &texture );
    }
}




void vrController::OnTimeoutPumpEvents()
{
    if( !vr::VRSystem() )
        return;


    if( m_bManualMouseHandling )
    {
        // tell OpenVR to make some events for us
        for( vr::TrackedDeviceIndex_t unDeviceId = 1; unDeviceId < vr::k_unControllerStateAxisCount; unDeviceId++ )
        {
            if( vr::VROverlay()->HandleControllerOverlayInteractionAsMouse( m_ulOverlayHandle, unDeviceId ) )
            {
                break;
            }
        }
    }

    vr::VREvent_t vrEvent;
    while( vr::VROverlay()->PollNextOverlayEvent( m_ulOverlayHandle, &vrEvent, sizeof( vrEvent )  ) )
    {
        switch( vrEvent.eventType )
        {
        case vr::VREvent_MouseMove:
            {
                QPointF ptNewMouse( vrEvent.data.mouse.x, vrEvent.data.mouse.y );
                QPoint ptGlobal = ptNewMouse.toPoint();
                QGraphicsSceneMouseEvent mouseEvent( QEvent::GraphicsSceneMouseMove );
                mouseEvent.setWidget( NULL );
                mouseEvent.setPos( ptNewMouse );
                mouseEvent.setScenePos( ptGlobal );
                mouseEvent.setScreenPos( ptGlobal );
                mouseEvent.setLastPos( m_ptLastMouse );
                mouseEvent.setLastScenePos( m_pWidget->mapToGlobal( m_ptLastMouse.toPoint() ) );
                mouseEvent.setLastScreenPos( m_pWidget->mapToGlobal( m_ptLastMouse.toPoint() ) );
                mouseEvent.setButtons( m_lastMouseButtons );
                mouseEvent.setButton( Qt::NoButton );
                mouseEvent.setModifiers( 0 );
                mouseEvent.setAccepted( false );

                m_ptLastMouse = ptNewMouse;
                QApplication::sendEvent( m_pScene, &mouseEvent );

                OnSceneChanged( QList<QRectF>() );
            }
            break;

        case vr::VREvent_MouseButtonDown:
            {
                Qt::MouseButton button = vrEvent.data.mouse.button == vr::VRMouseButton_Right ? Qt::RightButton : Qt::LeftButton;

                m_lastMouseButtons |= button;

                QPoint ptGlobal = m_ptLastMouse.toPoint();
                QGraphicsSceneMouseEvent mouseEvent( QEvent::GraphicsSceneMousePress );
                mouseEvent.setWidget( NULL );
                mouseEvent.setPos( m_ptLastMouse );
                mouseEvent.setButtonDownPos( button, m_ptLastMouse );
                mouseEvent.setButtonDownScenePos( button, ptGlobal);
                mouseEvent.setButtonDownScreenPos( button, ptGlobal );
                mouseEvent.setScenePos( ptGlobal );
                mouseEvent.setScreenPos( ptGlobal );
                mouseEvent.setLastPos( m_ptLastMouse );
                mouseEvent.setLastScenePos( ptGlobal );
                mouseEvent.setLastScreenPos( ptGlobal );
                mouseEvent.setButtons( m_lastMouseButtons );
                mouseEvent.setButton( button );
                mouseEvent.setModifiers( 0 );
                mouseEvent.setAccepted( false );

                QApplication::sendEvent( m_pScene, &mouseEvent );
            }
            break;

        case vr::VREvent_MouseButtonUp:
            {
                Qt::MouseButton button = vrEvent.data.mouse.button == vr::VRMouseButton_Right ? Qt::RightButton : Qt::LeftButton;
                m_lastMouseButtons &= ~button;

                QPoint ptGlobal = m_ptLastMouse.toPoint();
                QGraphicsSceneMouseEvent mouseEvent( QEvent::GraphicsSceneMouseRelease );
                mouseEvent.setWidget( NULL );
                mouseEvent.setPos( m_ptLastMouse );
                mouseEvent.setScenePos( ptGlobal );
                mouseEvent.setScreenPos( ptGlobal );
                mouseEvent.setLastPos( m_ptLastMouse );
                mouseEvent.setLastScenePos( ptGlobal );
                mouseEvent.setLastScreenPos( ptGlobal );
                mouseEvent.setButtons( m_lastMouseButtons );
                mouseEvent.setButton( button );
                mouseEvent.setModifiers( 0 );
                mouseEvent.setAccepted( false );

                QApplication::sendEvent(  m_pScene, &mouseEvent );
            }
            break;

        case vr::VREvent_OverlayShown:
            {
                m_pWidget->repaint();
            }
            break;

        case vr::VREvent_Quit:
            QApplication::exit();
            break;

            //keyboard done button event
        case vr::VREvent_KeyboardDone: {
            char keyboardBuffer[1024];
            vr::VROverlay()->GetKeyboardText(keyboardBuffer, 1024);
            //emit keyBoardInputSignal(QString(keyboardBuffer), vrEvent.data.keyboard.uUserValue);
            emit SigKeyboardDone(QString(keyboardBuffer));
        }
        }
    }

    if( m_ulOverlayThumbnailHandle != vr::k_ulOverlayHandleInvalid )
    {


        while( vr::VROverlay()->PollNextOverlayEvent( m_ulOverlayThumbnailHandle, &vrEvent, sizeof( vrEvent)  ) )
        {
            switch( vrEvent.eventType )
            {
            case vr::VREvent_OverlayShown:
                {
                    m_pWidget->repaint();
                }
                break;
            }
        }
    }

}




void vrController::SetWidget( QWidget *pWidget )
{
    if( m_pScene )
    {
        // all of the mouse handling stuff requires that the widget be at 0,0
        pWidget->move( 0, 0 );
        m_pScene->addWidget( pWidget );
    }
    m_pWidget = pWidget;

    m_pFbo = new QOpenGLFramebufferObject( pWidget->width(), pWidget->height(), GL_TEXTURE_2D );

    if( vr::VROverlay() )
    {
        vr::HmdVector2_t vecWindowSize =
        {
            (float)pWidget->width(),
            (float)pWidget->height()
        };
        vr::VROverlay()->SetOverlayMouseScale( m_ulOverlayHandle, &vecWindowSize );
    }
}

void vrController::SetupSignals(){

}



bool vrController::ConnectToVRRuntime()
{
    m_eLastHmdError = vr::VRInitError_None;
    vr::IVRSystem *pVRSystem = vr::VR_Init( &m_eLastHmdError, vr::VRApplication_Overlay );

    if ( m_eLastHmdError != vr::VRInitError_None )
    {
        m_strVRDriver = "No Driver";
        m_strVRDisplay = "No Display";
        return false;
    }

    m_strVRDriver = GetTrackedDeviceString(pVRSystem, vr::k_unTrackedDeviceIndex_Hmd, vr::Prop_TrackingSystemName_String);
    m_strVRDisplay = GetTrackedDeviceString(pVRSystem, vr::k_unTrackedDeviceIndex_Hmd, vr::Prop_SerialNumber_String);

    return true;
}


void vrController::DisconnectFromVRRuntime()
{
    vr::VR_Shutdown();
}




QString vrController::GetVRDriverString()
{
    return m_strVRDriver;
}



QString vrController::GetVRDisplayString()
{
    return m_strVRDisplay;
}



bool vrController::BHMDAvailable()
{
    return vr::VRSystem() != NULL;
}



vr::HmdError vrController::GetLastHmdError()
{
    return m_eLastHmdError;
}


