/****************************************************************************
** Meta object code from reading C++ file 'notificationviewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../phonesimulator/notificationviewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notificationviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NotificationViewer_t {
    QByteArrayData data[7];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NotificationViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NotificationViewer_t qt_meta_stringdata_NotificationViewer = {
    {
QT_MOC_LITERAL(0, 0, 18), // "NotificationViewer"
QT_MOC_LITERAL(1, 19, 9), // "replySent"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "showKeyboard"
QT_MOC_LITERAL(4, 43, 16), // "slotKeyboardDone"
QT_MOC_LITERAL(5, 60, 13), // "keyboardInput"
QT_MOC_LITERAL(6, 74, 12) // "emitReplySig"

    },
    "NotificationViewer\0replySent\0\0"
    "showKeyboard\0slotKeyboardDone\0"
    "keyboardInput\0emitReplySig"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NotificationViewer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    0,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   38,    2, 0x0a /* Public */,
       6,    0,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,

       0        // eod
};

void NotificationViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NotificationViewer *_t = static_cast<NotificationViewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->replySent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->showKeyboard(); break;
        case 2: _t->slotKeyboardDone((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->emitReplySig(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NotificationViewer::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NotificationViewer::replySent)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (NotificationViewer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NotificationViewer::showKeyboard)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject NotificationViewer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NotificationViewer.data,
      qt_meta_data_NotificationViewer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NotificationViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NotificationViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NotificationViewer.stringdata0))
        return static_cast<void*>(const_cast< NotificationViewer*>(this));
    return QWidget::qt_metacast(_clname);
}

int NotificationViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void NotificationViewer::replySent(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NotificationViewer::showKeyboard()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
