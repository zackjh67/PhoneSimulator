#include "mainscreen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainScreen w;
    //default method by QT, not implemented in steamVR overlay
    //w.show();

    return a.exec();
}
