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
    QByteArrayData data[9];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainScreen_t qt_meta_stringdata_MainScreen = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainScreen"
QT_MOC_LITERAL(1, 11, 13), // "onNotifPosted"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "notification"
QT_MOC_LITERAL(4, 39, 24), // "on_connectButton_clicked"
QT_MOC_LITERAL(5, 64, 21), // "on_sendButton_clicked"
QT_MOC_LITERAL(6, 86, 37), // "on_notificationListWidget_ite..."
QT_MOC_LITERAL(7, 124, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(8, 141, 4) // "item"

    },
    "MainScreen\0onNotifPosted\0\0notification\0"
    "on_connectButton_clicked\0on_sendButton_clicked\0"
    "on_notificationListWidget_itemClicked\0"
    "QListWidgetItem*\0item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    0,   37,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    1,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void MainScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainScreen *_t = static_cast<MainScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onNotifPosted((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_connectButton_clicked(); break;
        case 2: _t->on_sendButton_clicked(); break;
        case 3: _t->on_notificationListWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE