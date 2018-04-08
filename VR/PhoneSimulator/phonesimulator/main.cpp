
#include "mainscreen.h"
#include "vrcontroller.h"
#include <QApplication>
#include <iostream>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainScreen *mainWidget = new MainScreen;

    //initialize controller
    vrController::SharedInstance()->Init();
    //set widget to use for screen
    vrController::SharedInstance()->SetWidget( mainWidget );

    //setup signal event handlers
    //QObject::connect(vrController::SharedInstance(), SLOT(showKeyboard()), mainWidget, SIGNAL(showKeyboard()));

    vrController::SharedInstance()->SetupSignals();

    return a.exec();
}
