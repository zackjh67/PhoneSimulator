
#include "mainscreen.h"
#include "vrcontroller.h"
#include <QApplication>
#include <iostream>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainScreen *mainWidget = new MainScreen;

    vrController::SharedInstance()->Init();

    vrController::SharedInstance()->SetWidget( mainWidget );

    return a.exec();
    //cout << "FUCK";
}
