
#include "mainscreen.h"
#include "vrcontroller.h"
#include <QApplication>
#include <iostream>
#include "notificationhandler.h"
#include "notificationviewer.h"
#include <QLayoutItem>
#include <QLayout>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainScreen *mainWidget = new MainScreen;


    //initialize controller
    vrController::SharedInstance()->Init();
    //set widget to use for screen
    vrController::SharedInstance()->SetWidget( mainWidget );
    //class that handles network input/output
    NotificationHandler* n = new NotificationHandler;
    //connect to server
    //n->connectToServer();

    //setup signal event handlers
    //signal then slot
    //signal to show keyboard upon entering text field
    QObject::connect( mainWidget, &MainScreen::showKeyboard, vrController::SharedInstance(), &vrController::showKeyboard );
    //signal to send keyboard input to textedit
    QObject::connect(vrController::SharedInstance(), &vrController::SigKeyboardDone, mainWidget->viewer, &NotificationViewer::slotKeyboardDone);
    //signal to send a reply to a message
    QObject::connect(mainWidget, &MainScreen::sendReply, n, &NotificationHandler::sendReply);
    //signal that notification has been posted
    QObject::connect(n, &NotificationHandler::sigNotifReceived, mainWidget, &MainScreen::onNotifPosted);
    //sent to the GUI and VR Controller
    QObject::connect(n, &NotificationHandler::sigNotifReceived, vrController::SharedInstance(), &vrController::onNotificationPosted);
    //switches to text view
    //QObject::connect()

    //testing
    //NotificationViewer *replyWidget = new NotificationViewer;
    //vrController::SharedInstance()->SetWidget( replyWidget );
    //qDebug() << "widget changed??";

   // QLayoutItem *previous = QLayout::replaceWidget(mainWidget, replyWidget);

    //vrController::SharedInstance()->SetupSignals();

    return a.exec();
}
