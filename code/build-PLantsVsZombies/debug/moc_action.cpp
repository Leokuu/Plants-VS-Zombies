/****************************************************************************
** Meta object code from reading C++ file 'action.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PLantsVsZombies/action.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'action.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Action_t {
    QByteArrayData data[6];
    char stringdata0[47];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Action_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Action_t qt_meta_stringdata_Action = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Action"
QT_MOC_LITERAL(1, 7, 10), // "moveFinish"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "FinishPlace"
QT_MOC_LITERAL(4, 31, 10), // "DonotPlace"
QT_MOC_LITERAL(5, 42, 4) // "move"

    },
    "Action\0moveFinish\0\0FinishPlace\0"
    "DonotPlace\0move"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Action[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,
       4,    0,   38,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Action::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Action *_t = static_cast<Action *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->moveFinish(); break;
        case 1: _t->FinishPlace((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->DonotPlace(); break;
        case 3: _t->move(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Action::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Action::moveFinish)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Action::*_t)(QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Action::FinishPlace)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Action::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Action::DonotPlace)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Action::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Action.data,
      qt_meta_data_Action,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Action::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Action::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Action.stringdata0))
        return static_cast<void*>(const_cast< Action*>(this));
    return QWidget::qt_metacast(_clname);
}

int Action::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Action::moveFinish()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Action::FinishPlace(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Action::DonotPlace()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
