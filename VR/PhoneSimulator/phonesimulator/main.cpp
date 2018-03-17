#include "mainscreen.h"
#include "vrcontroller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainScreen *mainWidget = new MainScreen;

    vrController::SharedInstance()->Init();

    vrController::SharedInstance()->SetWidget( mainWidget );

    //default method by QT, not implemented in steamVR overlay
    //w.show();

    return a.exec();
}
