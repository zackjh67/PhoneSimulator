#ifndef NOTIF_GETTER_H
#define NOTIF_GETTER_H

#include <QThread>

/*
 * Handler for QThread to watch for notifications and update GUI accordingly.
 * @author Zachary Hern
 * @version 3/18/17
 */
class NotificationGetter : public QThread
{
    Q_OBJECT
public:
    explicit NotificationGetter(QObject *parent = 0, bool b = false);
    void run();

    // if Stop = true, the thread will break
    // out of the loop, and will be disposed
    bool Stop;

signals:
    //sends signal to GUI that notification has been posted
    void notifPosted(QString);

public slots:

};

#endif // NOTIF_GETTER_H
