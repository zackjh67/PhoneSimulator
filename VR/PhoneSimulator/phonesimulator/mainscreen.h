#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>

#include <QString>
#include <QJsonObject>
#include <unordered_map>
#include <QListWidgetItem>
#include "notificationviewer.h"

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

    NotificationViewer* viewer;

public slots:
    //method to perform when notification has been posted
    void onNotifPosted(QJsonObject notification);



    void toggleViews(QString replyMessage);

private slots:

    void on_sendButton_clicked();

    void on_notificationListWidget_itemClicked(QListWidgetItem *item);


    void on_sendButton_pressed();

    void on_sendButton_released();

    void on_keyboardButton_pressed();

    void on_keyboardButton_released();

    void on_backButton_pressed();

    void on_backButton_released();

    void on_keyboardButton_clicked();

    void on_backButton_clicked();

    void createNewMessage();

signals:

        void sig_send_reply(QJsonObject reply);
        void sendReply(QJsonObject reply);
        void showKeyboard();
        void sendClickSig();

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
    const QString TICKER_KEY = "nTicker";

    //0 for new, 1 for send
    int iconState;

    QIcon* newIcon;
    QIcon* sendIcon;
    QIcon* keyboardIcon;
    QIcon* backIcon;
    QIcon* newIconPressed;
    QIcon* sendIconPressed;
    QIcon* keyboardIconPressed;
    QIcon* backIconPressed;
    QIcon* messageIcon;
};

#endif // MAINSCREEN_H
