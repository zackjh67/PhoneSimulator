/****************************************************************************
** Meta object code from reading C++ file 'mainscreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../phonesimulator/mainscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainScreen_t {
    QByteArrayData data[24];
    char stringdata0[411];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainScreen_t qt_meta_stringdata_MainScreen = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainScreen"
QT_MOC_LITERAL(1, 11, 14), // "sig_send_reply"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "reply"
QT_MOC_LITERAL(4, 33, 9), // "sendReply"
QT_MOC_LITERAL(5, 43, 12), // "showKeyboard"
QT_MOC_LITERAL(6, 56, 12), // "sendClickSig"
QT_MOC_LITERAL(7, 69, 13), // "onNotifPosted"
QT_MOC_LITERAL(8, 83, 12), // "notification"
QT_MOC_LITERAL(9, 96, 11), // "toggleViews"
QT_MOC_LITERAL(10, 108, 12), // "replyMessage"
QT_MOC_LITERAL(11, 121, 21), // "on_sendButton_clicked"
QT_MOC_LITERAL(12, 143, 37), // "on_notificationListWidget_ite..."
QT_MOC_LITERAL(13, 181, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(14, 198, 4), // "item"
QT_MOC_LITERAL(15, 203, 21), // "on_sendButton_pressed"
QT_MOC_LITERAL(16, 225, 22), // "on_sendButton_released"
QT_MOC_LITERAL(17, 248, 25), // "on_keyboardButton_pressed"
QT_MOC_LITERAL(18, 274, 26), // "on_keyboardButton_released"
QT_MOC_LITERAL(19, 301, 21), // "on_backButton_pressed"
QT_MOC_LITERAL(20, 323, 22), // "on_backButton_released"
QT_MOC_LITERAL(21, 346, 25), // "on_keyboardButton_clicked"
QT_MOC_LITERAL(22, 372, 21), // "on_backButton_clicked"
QT_MOC_LITERAL(23, 394, 16) // "createNewMessage"

    },
    "MainScreen\0sig_send_reply\0\0reply\0"
    "sendReply\0showKeyboard\0sendClickSig\0"
    "onNotifPosted\0notification\0toggleViews\0"
    "replyMessage\0on_sendButton_clicked\0"
    "on_notificationListWidget_itemClicked\0"
    "QListWidgetItem*\0item\0on_sendButton_pressed\0"
    "on_sendButton_released\0on_keyboardButton_pressed\0"
    "on_keyboardButton_released\0"
    "on_backButton_pressed\0on_backButton_released\0"
    "on_keyboardButton_clicked\0"
    "on_backButton_clicked\0createNewMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    1,  102,    2, 0x06 /* Public */,
       5,    0,  105,    2, 0x06 /* Public */,
       6,    0,  106,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,  107,    2, 0x0a /* Public */,
       9,    1,  110,    2, 0x0a /* Public */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    1,  114,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,
      20,    0,  122,    2, 0x08 /* Private */,
      21,    0,  123,    2, 0x08 /* Private */,
      22,    0,  124,    2, 0x08 /* Private */,
      23,    0,  125,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QJsonObject,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainScreen *_t = static_cast<MainScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_send_reply((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 1: _t->sendReply((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 2: _t->showKeyboard(); break;
        case 3: _t->sendClickSig(); break;
        case 4: _t->onNotifPosted((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 5: _t->toggleViews((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->on_sendButton_clicked(); break;
        case 7: _t->on_notificationListWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->on_sendButton_pressed(); break;
        case 9: _t->on_sendButton_released(); break;
        case 10: _t->on_keyboardButton_pressed(); break;
        case 11: _t->on_keyboardButton_released(); break;
        case 12: _t->on_backButton_pressed(); break;
        case 13: _t->on_backButton_released(); break;
        case 14: _t->on_keyboardButton_clicked(); break;
        case 15: _t->on_backButton_clicked(); break;
        case 16: _t->createNewMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainScreen::*_t)(QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainScreen::sig_send_reply)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainScreen::*_t)(QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainScreen::sendReply)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainScreen::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainScreen::showKeyboard)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainScreen::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainScreen::sendClickSig)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject MainScreen::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainScreen.data,
      qt_meta_data_MainScreen,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainScreen.stringdata0))
        return static_cast<void*>(const_cast< MainScreen*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MainScreen::sig_send_reply(QJsonObject _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainScreen::sendReply(QJsonObject _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainScreen::showKeyboard()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MainScreen::sendClickSig()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
