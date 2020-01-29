/****************************************************************************
** Meta object code from reading C++ file 'plants.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PLantsVsZombies/plants.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plants.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Plants_t {
    QByteArrayData data[6];
    char stringdata0[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Plants_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Plants_t qt_meta_stringdata_Plants = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Plants"
QT_MOC_LITERAL(1, 7, 12), // "placePostion"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 1), // "x"
QT_MOC_LITERAL(4, 23, 1), // "y"
QT_MOC_LITERAL(5, 25, 11) // "cancelPlace"

    },
    "Plants\0placePostion\0\0x\0y\0cancelPlace"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Plants[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       5,    0,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,

       0        // eod
};

void Plants::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Plants *_t = static_cast<Plants *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->placePostion((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->cancelPlace(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Plants::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Plants::placePostion)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Plants::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Plants::cancelPlace)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Plants::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Plants.data,
      qt_meta_data_Plants,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Plants::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Plants::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Plants.stringdata0))
        return static_cast<void*>(const_cast< Plants*>(this));
    return QWidget::qt_metacast(_clname);
}

int Plants::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Plants::placePostion(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Plants::cancelPlace()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_PeaShooter_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PeaShooter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PeaShooter_t qt_meta_stringdata_PeaShooter = {
    {
QT_MOC_LITERAL(0, 0, 10) // "PeaShooter"

    },
    "PeaShooter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PeaShooter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void PeaShooter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject PeaShooter::staticMetaObject = {
    { &Plants::staticMetaObject, qt_meta_stringdata_PeaShooter.data,
      qt_meta_data_PeaShooter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PeaShooter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PeaShooter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PeaShooter.stringdata0))
        return static_cast<void*>(const_cast< PeaShooter*>(this));
    return Plants::qt_metacast(_clname);
}

int PeaShooter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Plants::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_WallNut_t {
    QByteArrayData data[1];
    char stringdata0[8];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WallNut_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WallNut_t qt_meta_stringdata_WallNut = {
    {
QT_MOC_LITERAL(0, 0, 7) // "WallNut"

    },
    "WallNut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WallNut[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void WallNut::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject WallNut::staticMetaObject = {
    { &Plants::staticMetaObject, qt_meta_stringdata_WallNut.data,
      qt_meta_data_WallNut,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WallNut::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WallNut::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WallNut.stringdata0))
        return static_cast<void*>(const_cast< WallNut*>(this));
    return Plants::qt_metacast(_clname);
}

int WallNut::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Plants::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_SunFlower_t {
    QByteArrayData data[1];
    char stringdata0[10];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SunFlower_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SunFlower_t qt_meta_stringdata_SunFlower = {
    {
QT_MOC_LITERAL(0, 0, 9) // "SunFlower"

    },
    "SunFlower"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SunFlower[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void SunFlower::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject SunFlower::staticMetaObject = {
    { &Plants::staticMetaObject, qt_meta_stringdata_SunFlower.data,
      qt_meta_data_SunFlower,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SunFlower::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SunFlower::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SunFlower.stringdata0))
        return static_cast<void*>(const_cast< SunFlower*>(this));
    return Plants::qt_metacast(_clname);
}

int SunFlower::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Plants::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_CherryBomb_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CherryBomb_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CherryBomb_t qt_meta_stringdata_CherryBomb = {
    {
QT_MOC_LITERAL(0, 0, 10) // "CherryBomb"

    },
    "CherryBomb"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CherryBomb[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void CherryBomb::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject CherryBomb::staticMetaObject = {
    { &Plants::staticMetaObject, qt_meta_stringdata_CherryBomb.data,
      qt_meta_data_CherryBomb,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CherryBomb::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CherryBomb::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CherryBomb.stringdata0))
        return static_cast<void*>(const_cast< CherryBomb*>(this));
    return Plants::qt_metacast(_clname);
}

int CherryBomb::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Plants::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Squash_t {
    QByteArrayData data[1];
    char stringdata0[7];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Squash_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Squash_t qt_meta_stringdata_Squash = {
    {
QT_MOC_LITERAL(0, 0, 6) // "Squash"

    },
    "Squash"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Squash[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void Squash::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Squash::staticMetaObject = {
    { &Plants::staticMetaObject, qt_meta_stringdata_Squash.data,
      qt_meta_data_Squash,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Squash::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Squash::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Squash.stringdata0))
        return static_cast<void*>(const_cast< Squash*>(this));
    return Plants::qt_metacast(_clname);
}

int Squash::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Plants::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_PotatoMine_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PotatoMine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PotatoMine_t qt_meta_stringdata_PotatoMine = {
    {
QT_MOC_LITERAL(0, 0, 10) // "PotatoMine"

    },
    "PotatoMine"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PotatoMine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void PotatoMine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject PotatoMine::staticMetaObject = {
    { &Plants::staticMetaObject, qt_meta_stringdata_PotatoMine.data,
      qt_meta_data_PotatoMine,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PotatoMine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PotatoMine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PotatoMine.stringdata0))
        return static_cast<void*>(const_cast< PotatoMine*>(this));
    return Plants::qt_metacast(_clname);
}

int PotatoMine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Plants::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_SnowPea_t {
    QByteArrayData data[1];
    char stringdata0[8];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SnowPea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SnowPea_t qt_meta_stringdata_SnowPea = {
    {
QT_MOC_LITERAL(0, 0, 7) // "SnowPea"

    },
    "SnowPea"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SnowPea[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void SnowPea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject SnowPea::staticMetaObject = {
    { &Plants::staticMetaObject, qt_meta_stringdata_SnowPea.data,
      qt_meta_data_SnowPea,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SnowPea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SnowPea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SnowPea.stringdata0))
        return static_cast<void*>(const_cast< SnowPea*>(this));
    return Plants::qt_metacast(_clname);
}

int SnowPea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Plants::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Chomper_t {
    QByteArrayData data[1];
    char stringdata0[8];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Chomper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Chomper_t qt_meta_stringdata_Chomper = {
    {
QT_MOC_LITERAL(0, 0, 7) // "Chomper"

    },
    "Chomper"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Chomper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void Chomper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Chomper::staticMetaObject = {
    { &Plants::staticMetaObject, qt_meta_stringdata_Chomper.data,
      qt_meta_data_Chomper,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Chomper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Chomper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Chomper.stringdata0))
        return static_cast<void*>(const_cast< Chomper*>(this));
    return Plants::qt_metacast(_clname);
}

int Chomper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Plants::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_RepeaterPea_t {
    QByteArrayData data[1];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RepeaterPea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RepeaterPea_t qt_meta_stringdata_RepeaterPea = {
    {
QT_MOC_LITERAL(0, 0, 11) // "RepeaterPea"

    },
    "RepeaterPea"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RepeaterPea[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void RepeaterPea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject RepeaterPea::staticMetaObject = {
    { &PeaShooter::staticMetaObject, qt_meta_stringdata_RepeaterPea.data,
      qt_meta_data_RepeaterPea,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RepeaterPea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RepeaterPea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RepeaterPea.stringdata0))
        return static_cast<void*>(const_cast< RepeaterPea*>(this));
    return PeaShooter::qt_metacast(_clname);
}

int RepeaterPea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PeaShooter::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
