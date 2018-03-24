#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>

#include "notificationgetter.h"
#include <QString>

/*
 * Main QWidget.
 * @author Zachary Hern
 * @version 3/18/17
 */
namespace Ui {
class MainScreen;
}

class MainScreen : public QWidget
{
    Q_OBJECT

public:
    explicit MainScreen(QWidget *parent = 0);
    ~MainScreen();
    NotificationGetter *notificationGetter;

public slots:
    //method to perform when notification has been posted
    void onNotifPosted(QString notification);

    //input coming from keyboard
    void SlotKeyboardDone(QString keyboardInput);

private slots:

    void on_sendButton_clicked();

    void on_notificationListWidget_itemClicked(QListWidgetItem *item);

signals:
        void showKeyboard();

private:
    Ui::MainScreen *ui;
};

#endif // MAINSCREEN_H
