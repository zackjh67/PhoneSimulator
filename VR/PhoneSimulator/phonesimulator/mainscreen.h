#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>

#include <QString>
#include <QJsonObject>
#include <unordered_map>
#include <QListWidgetItem>

/*
 * Main QWidget.
 * @author Zachary Hern
 * @version 3/18/17
 */



/* unordered map of QListWidgetItems */
//typedef std::unordered_map< QString, QListWidgetItem*> notif_list;

namespace Ui {
class MainScreen;
}

class MainScreen : public QWidget
{
    Q_OBJECT

public:
    explicit MainScreen(QWidget *parent = 0);
    ~MainScreen();

public slots:
    //method to perform when notification has been posted
    void onNotifPosted(QJsonObject notification);

    //input coming from keyboard
    void slotKeyboardDone(QString keyboardInput);

private slots:

    void on_sendButton_clicked();

    void on_notificationListWidget_itemClicked(QListWidgetItem *item);



signals:
        void showKeyboard();
        void sig_send_reply(QJsonObject reply);
        void sendReply(QJsonObject reply);

private:
    Ui::MainScreen *ui;
    /* list of all notifications */
    //    notif_list notifications;
    /* current notification selected */
    QListWidgetItem* currentNotif;

    /* current keyboard text */
    QString currentText;

    //JSON keys
    const QString ID_KEY = "notif_id";
    const QString GROUP_KEY = "group_id";
    const QString MESSAGE_KEY = "message";
};

#endif // MAINSCREEN_H
