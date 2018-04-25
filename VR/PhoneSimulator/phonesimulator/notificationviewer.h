#ifndef NOTIFICATIONVIEWER_H
#define NOTIFICATIONVIEWER_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class NotificationViewer;
}

class NotificationViewer : public QWidget
{
    Q_OBJECT

public:
    explicit NotificationViewer(QWidget *parent = 0);
    ~NotificationViewer();
    Ui::NotificationViewer *ui;

    void setContact(QString contact);

    void setMessage(QString message);

private slots:


public slots:
    //input coming from keyboard
    void slotKeyboardDone(QString keyboardInput);
    void emitReplySig();

private:


signals:
    void replySent(QString);
    void showKeyboard();
};

#endif // NOTIFICATIONVIEWER_H
