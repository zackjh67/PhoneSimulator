/********************************************************************************
** Form generated from reading UI file 'mainscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCREEN_H
#define UI_MAINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScreen
{
public:
    QLabel *label;
    QStackedWidget *stackedWidget;
    QWidget *page_7;
    QVBoxLayout *verticalLayout_2;
    QListWidget *notificationListWidget;
    QWidget *page_8;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *backButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *keyboardButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *sendButton;

    void setupUi(QWidget *MainScreen)
    {
        if (MainScreen->objectName().isEmpty())
            MainScreen->setObjectName(QStringLiteral("MainScreen"));
        MainScreen->resize(459, 537);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainScreen->sizePolicy().hasHeightForWidth());
        MainScreen->setSizePolicy(sizePolicy);
        MainScreen->setAutoFillBackground(false);
        MainScreen->setStyleSheet(QLatin1String("#MainScreen, QStackedWidget, QListWidget {\n"
"	 background-color:rgb(77, 77, 77);\n"
"}\n"
"#label {\n"
"	color:white;\n"
"	background-color: rgb(255, 85, 0);\n"
"}\n"
"/*QPushButton#sendButton {\n"
"    background-color: red;\n"
"	border-radius:40%;\n"
"	padding:10px;\n"
"	background-clip:content;\n"
"	border-style:outset;\n"
"	border-width: 3px;\n"
"    border-color: white;\n"
"}*/\n"
"QPushButton {\n"
"	height:300px;\n"
"	width: 300px;\n"
"    background-color:white;\n"
"    border: 40px solid transparent;\n"
"    border-radius: 50px;\n"
"    border-style: outset;\n"
"\n"
"    padding: 5px;\n"
"    }\n"
"QPushButton:pressed {\n"
"\n"
"    }\n"
"/*\n"
"QPushButton#sendButton:pressed {\n"
"    background-color:rgb(180, 60, 0);\n"
"}\n"
"QPushButton#sendButton:hover {\n"
"    border-color:white;\n"
"}*/\n"
""));
        label = new QLabel(MainScreen);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(0, 0, 459, 40));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(459, 40));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label->setFrameShape(QFrame::NoFrame);
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        stackedWidget = new QStackedWidget(MainScreen);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 40, 461, 501));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        verticalLayout_2 = new QVBoxLayout(page_7);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        notificationListWidget = new QListWidget(page_7);
        notificationListWidget->setObjectName(QStringLiteral("notificationListWidget"));
        notificationListWidget->setMinimumSize(QSize(423, 0));
        notificationListWidget->setAutoFillBackground(false);
        notificationListWidget->setStyleSheet(QLatin1String("QListView::item {\n"
"	margin:2px;\n"
"	background-color:rgb(70, 70, 70);\n"
"\n"
"}\n"
"QListView::item:hover {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:2, fx:0.5, fy:0.5, stop:0 rgba(255, 129, 0, 223), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));\n"
"\n"
"}\n"
"\n"
""));
        notificationListWidget->setFrameShape(QFrame::NoFrame);
        notificationListWidget->setFrameShadow(QFrame::Plain);
        notificationListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        notificationListWidget->setProperty("showDropIndicator", QVariant(false));
        notificationListWidget->setSelectionMode(QAbstractItemView::NoSelection);
        notificationListWidget->setProperty("isWrapping", QVariant(false));
        notificationListWidget->setResizeMode(QListView::Fixed);
        notificationListWidget->setLayoutMode(QListView::SinglePass);
        notificationListWidget->setWordWrap(false);
        notificationListWidget->setSelectionRectVisible(false);

        verticalLayout_2->addWidget(notificationListWidget);

        stackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName(QStringLiteral("page_8"));
        stackedWidget->addWidget(page_8);
        horizontalLayoutWidget = new QWidget(MainScreen);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(-1, 420, 461, 121));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(27, 0, 27, 10);
        backButton = new QPushButton(horizontalLayoutWidget);
        backButton->setObjectName(QStringLiteral("backButton"));
        sizePolicy1.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy1);
        backButton->setMinimumSize(QSize(100, 100));
        backButton->setMaximumSize(QSize(100, 100));
        backButton->setBaseSize(QSize(100, 100));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        backButton->setFont(font1);
        backButton->setMouseTracking(true);
        backButton->setFocusPolicy(Qt::WheelFocus);
        backButton->setLayoutDirection(Qt::LeftToRight);
        backButton->setAutoFillBackground(false);
        backButton->setStyleSheet(QStringLiteral(""));
        backButton->setIconSize(QSize(100, 100));
        backButton->setAutoDefault(false);
        backButton->setFlat(false);

        horizontalLayout->addWidget(backButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        keyboardButton = new QPushButton(horizontalLayoutWidget);
        keyboardButton->setObjectName(QStringLiteral("keyboardButton"));
        sizePolicy1.setHeightForWidth(keyboardButton->sizePolicy().hasHeightForWidth());
        keyboardButton->setSizePolicy(sizePolicy1);
        keyboardButton->setMinimumSize(QSize(100, 100));
        keyboardButton->setMaximumSize(QSize(100, 100));
        keyboardButton->setBaseSize(QSize(100, 100));
        keyboardButton->setFont(font1);
        keyboardButton->setMouseTracking(true);
        keyboardButton->setFocusPolicy(Qt::WheelFocus);
        keyboardButton->setLayoutDirection(Qt::LeftToRight);
        keyboardButton->setAutoFillBackground(false);
        keyboardButton->setStyleSheet(QStringLiteral(""));
        keyboardButton->setIconSize(QSize(100, 100));
        keyboardButton->setAutoDefault(false);
        keyboardButton->setFlat(false);

        horizontalLayout->addWidget(keyboardButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sendButton = new QPushButton(horizontalLayoutWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sizePolicy1.setHeightForWidth(sendButton->sizePolicy().hasHeightForWidth());
        sendButton->setSizePolicy(sizePolicy1);
        sendButton->setMinimumSize(QSize(100, 100));
        sendButton->setMaximumSize(QSize(100, 100));
        sendButton->setBaseSize(QSize(100, 100));
        sendButton->setFont(font1);
        sendButton->setMouseTracking(true);
        sendButton->setFocusPolicy(Qt::WheelFocus);
        sendButton->setLayoutDirection(Qt::LeftToRight);
        sendButton->setAutoFillBackground(false);
        sendButton->setStyleSheet(QStringLiteral(""));
        sendButton->setIconSize(QSize(100, 100));
        sendButton->setAutoDefault(false);
        sendButton->setFlat(false);

        horizontalLayout->addWidget(sendButton);


        retranslateUi(MainScreen);

        QMetaObject::connectSlotsByName(MainScreen);
    } // setupUi

    void retranslateUi(QWidget *MainScreen)
    {
        MainScreen->setWindowTitle(QApplication::translate("MainScreen", "Phone Simulator", Q_NULLPTR));
        label->setText(QApplication::translate("MainScreen", "Phone Simulator", Q_NULLPTR));
        backButton->setText(QString());
        keyboardButton->setText(QString());
        sendButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainScreen: public Ui_MainScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
