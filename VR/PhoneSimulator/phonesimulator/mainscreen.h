#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>

namespace Ui {
class MainScreen;
}

class MainScreen : public QWidget
{
    Q_OBJECT

public:
    explicit MainScreen(QWidget *parent = 0);
    ~MainScreen();

private slots:
    void on_pushButton_clicked();

    void on_sendButton_clicked();

    void on_label_2_linkActivated(const QString &link);

private:
    Ui::MainScreen *ui;
};

#endif // MAINSCREEN_H
