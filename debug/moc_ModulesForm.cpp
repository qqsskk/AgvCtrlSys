/****************************************************************************
** Meta object code from reading C++ file 'ModulesForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ModulesForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModulesForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModulesForm_t {
    QByteArrayData data[16];
    char stringdata0[274];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModulesForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModulesForm_t qt_meta_stringdata_ModulesForm = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ModulesForm"
QT_MOC_LITERAL(1, 12, 12), // "callerEnable"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 2), // "id"
QT_MOC_LITERAL(4, 29, 6), // "enable"
QT_MOC_LITERAL(5, 36, 27), // "on_tableViewAgvType_clicked"
QT_MOC_LITERAL(6, 64, 11), // "QModelIndex"
QT_MOC_LITERAL(7, 76, 5), // "index"
QT_MOC_LITERAL(8, 82, 31), // "on_tableViewWorkStation_clicked"
QT_MOC_LITERAL(9, 114, 32), // "on_tableViewResetStation_clicked"
QT_MOC_LITERAL(10, 147, 27), // "on_tableViewCharger_clicked"
QT_MOC_LITERAL(11, 175, 30), // "on_tableViewResetQueue_clicked"
QT_MOC_LITERAL(12, 206, 27), // "on_tableViewTraffic_clicked"
QT_MOC_LITERAL(13, 234, 14), // "onStateChanged"
QT_MOC_LITERAL(14, 249, 5), // "state"
QT_MOC_LITERAL(15, 255, 18) // "onUpdateCallerData"

    },
    "ModulesForm\0callerEnable\0\0id\0enable\0"
    "on_tableViewAgvType_clicked\0QModelIndex\0"
    "index\0on_tableViewWorkStation_clicked\0"
    "on_tableViewResetStation_clicked\0"
    "on_tableViewCharger_clicked\0"
    "on_tableViewResetQueue_clicked\0"
    "on_tableViewTraffic_clicked\0onStateChanged\0"
    "state\0onUpdateCallerData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModulesForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   64,    2, 0x08 /* Private */,
       8,    1,   67,    2, 0x08 /* Private */,
       9,    1,   70,    2, 0x08 /* Private */,
      10,    1,   73,    2, 0x08 /* Private */,
      11,    1,   76,    2, 0x08 /* Private */,
      12,    1,   79,    2, 0x08 /* Private */,
      13,    1,   82,    2, 0x08 /* Private */,
      15,    0,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,

       0        // eod
};

void ModulesForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ModulesForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->callerEnable((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->on_tableViewAgvType_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_tableViewWorkStation_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_tableViewResetStation_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->on_tableViewCharger_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_tableViewResetQueue_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_tableViewTraffic_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->onStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->onUpdateCallerData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ModulesForm::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModulesForm::callerEnable)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ModulesForm::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ModulesForm.data,
    qt_meta_data_ModulesForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ModulesForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModulesForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModulesForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ModulesForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ModulesForm::callerEnable(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
