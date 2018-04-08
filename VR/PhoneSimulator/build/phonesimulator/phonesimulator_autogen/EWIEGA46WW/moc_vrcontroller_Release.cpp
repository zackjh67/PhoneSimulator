/****************************************************************************
** Meta object code from reading C++ file 'vrcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../phonesimulator/vrcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vrcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_vrController_t {
    QByteArrayData data[10];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vrController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vrController_t qt_meta_stringdata_vrController = {
    {
QT_MOC_LITERAL(0, 0, 12), // "vrController"
QT_MOC_LITERAL(1, 13, 15), // "SigKeyboardDone"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 13), // "keyboardInput"
QT_MOC_LITERAL(4, 44, 14), // "OnSceneChanged"
QT_MOC_LITERAL(5, 59, 13), // "QList<QRectF>"
QT_MOC_LITERAL(6, 73, 19), // "OnTimeoutPumpEvents"
QT_MOC_LITERAL(7, 93, 12), // "showKeyboard"
QT_MOC_LITERAL(8, 106, 16), // "showNotification"
QT_MOC_LITERAL(9, 123, 16) // "notificationText"

    },
    "vrController\0SigKeyboardDone\0\0"
    "keyboardInput\0OnSceneChanged\0QList<QRectF>\0"
    "OnTimeoutPumpEvents\0showKeyboard\0"
    "showNotification\0notificationText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vrController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   42,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x0a /* Public */,
       7,    0,   46,    2, 0x0a /* Public */,
       8,    1,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void vrController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        vrController *_t = static_cast<vrController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SigKeyboardDone((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->OnSceneChanged((*reinterpret_cast< const QList<QRectF>(*)>(_a[1]))); break;
        case 2: _t->OnTimeoutPumpEvents(); break;
        case 3: _t->showKeyboard(); break;
        case 4: _t->showNotification((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QRectF> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (vrController::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vrController::SigKeyboardDone)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject vrController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_vrController.data,
      qt_meta_data_vrController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *vrController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vrController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_vrController.stringdata0))
        return static_cast<void*>(const_cast< vrController*>(this));
    return QObject::qt_metacast(_clname);
}

int vrController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void vrController::SigKeyboardDone(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
