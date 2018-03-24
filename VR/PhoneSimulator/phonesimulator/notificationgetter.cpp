#include "notificationgetter.h"
#include <QDebug>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>
#include <QStringList>

#include <iostream>
using namespace std;

/*
 * Handler for QThread to watch for notifications and update GUI accordingly.
 * @author Zachary Hern
 * @version 3/18/17
 */
NotificationGetter::NotificationGetter(QObject *parent, bool b) :
    QThread(parent), Stop(b)
{
}

/*
 * Run method for starting the thread.
 */
void NotificationGetter::run()
{
    //notification value iterator
    int i = 0;

    while(true)
    {
        QMutex mutex;
        // prevent other threads from changing the "Stop" value
        mutex.lock();
        if(this->Stop) break;
        mutex.unlock();

        //check for new notification
        //TODO find better way than hardcoding this path.
        QString path = "C:/Users/Zack/AppData/Local/Temp/PhoneSimulator/notification";
        QString num = QString::number(i);
        path.append(num);
        path.append(".txt");

        //full notification text
        QString finalString;

        QFileInfo check_file(path);
        // check if file exists and if yes: Is it really a file and no directory?
        if (check_file.exists() && check_file.isFile()) {

            //get file from path
            QFile file(path);

            //TODO error check later
            if(!file.open(QIODevice::ReadOnly)) {
                //QMessageBox::information(0, "error", file.errorString());
            }

            QTextStream in(&file);

            while(!in.atEnd()) {
                QString line = in.readLine();
                //QStringList fields = line.split(",");
                //model->appendRow(fields);
                finalString.append(line);
            }

            file.close();

            //increment to wait for next notification
            i++;

            // send signal to update GUI
            emit notifPosted(finalString);
        }//otherwise keep looping
    }
}
