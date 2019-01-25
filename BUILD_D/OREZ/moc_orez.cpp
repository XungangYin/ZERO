/****************************************************************************
** Meta object code from reading C++ file 'orez.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OREZ/orez.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'orez.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OREZ_t {
    QByteArrayData data[13];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OREZ_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OREZ_t qt_meta_stringdata_OREZ = {
    {
QT_MOC_LITERAL(0, 0, 4), // "OREZ"
QT_MOC_LITERAL(1, 5, 21), // "on_action_3_triggered"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 19), // "on_action_triggered"
QT_MOC_LITERAL(4, 48, 21), // "on_action_5_triggered"
QT_MOC_LITERAL(5, 70, 29), // "on_normal_action_19_triggered"
QT_MOC_LITERAL(6, 100, 22), // "on_action_12_triggered"
QT_MOC_LITERAL(7, 123, 7), // "checked"
QT_MOC_LITERAL(8, 131, 22), // "on_action_10_triggered"
QT_MOC_LITERAL(9, 154, 20), // "on_action1_triggered"
QT_MOC_LITERAL(10, 175, 12), // "widgetChange"
QT_MOC_LITERAL(11, 188, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(12, 205, 5) // "state"

    },
    "OREZ\0on_action_3_triggered\0\0"
    "on_action_triggered\0on_action_5_triggered\0"
    "on_normal_action_19_triggered\0"
    "on_action_12_triggered\0checked\0"
    "on_action_10_triggered\0on_action1_triggered\0"
    "widgetChange\0QTreeWidgetItem*\0state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OREZ[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    1,   58,    2, 0x08 /* Private */,
       8,    1,   61,    2, 0x08 /* Private */,
       9,    1,   64,    2, 0x08 /* Private */,
      10,    1,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void OREZ::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OREZ *_t = static_cast<OREZ *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_action_3_triggered(); break;
        case 1: _t->on_action_triggered(); break;
        case 2: _t->on_action_5_triggered(); break;
        case 3: _t->on_normal_action_19_triggered(); break;
        case 4: _t->on_action_12_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_action_10_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_action1_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->widgetChange((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject OREZ::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_OREZ.data,
      qt_meta_data_OREZ,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OREZ::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OREZ::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OREZ.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int OREZ::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
