/****************************************************************************
** Meta object code from reading C++ file 'MapForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MapForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MapForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MapForm_t {
    QByteArrayData data[16];
    char stringdata0[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MapForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MapForm_t qt_meta_stringdata_MapForm = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MapForm"
QT_MOC_LITERAL(1, 8, 20), // "onUpdateMapMenuEvent"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 14), // "onBtnOkClicked"
QT_MOC_LITERAL(4, 45, 18), // "onBtnCancelClicked"
QT_MOC_LITERAL(5, 64, 14), // "onCursorChange"
QT_MOC_LITERAL(6, 79, 9), // "onShowAgv"
QT_MOC_LITERAL(7, 89, 4), // "unNo"
QT_MOC_LITERAL(8, 94, 7), // "strType"
QT_MOC_LITERAL(9, 102, 7), // "strMove"
QT_MOC_LITERAL(10, 110, 9), // "unCurMark"
QT_MOC_LITERAL(11, 120, 4), // "bRun"
QT_MOC_LITERAL(12, 125, 6), // "bUnVol"
QT_MOC_LITERAL(13, 132, 4), // "bObs"
QT_MOC_LITERAL(14, 137, 6), // "bError"
QT_MOC_LITERAL(15, 144, 9) // "onHideAgv"

    },
    "MapForm\0onUpdateMapMenuEvent\0\0"
    "onBtnOkClicked\0onBtnCancelClicked\0"
    "onCursorChange\0onShowAgv\0unNo\0strType\0"
    "strMove\0unCurMark\0bRun\0bUnVol\0bObs\0"
    "bError\0onHideAgv"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MapForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    8,   48,    2, 0x0a /* Public */,
      15,    1,   65,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::UInt, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,    7,    8,    9,   10,   11,   12,   13,   14,
    QMetaType::Void, QMetaType::UInt,    7,

       0        // eod
};

void MapForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MapForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onUpdateMapMenuEvent(); break;
        case 1: _t->onBtnOkClicked(); break;
        case 2: _t->onBtnCancelClicked(); break;
        case 3: _t->onCursorChange(); break;
        case 4: _t->onShowAgv((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< quint32(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])),(*reinterpret_cast< bool(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8]))); break;
        case 5: _t->onHideAgv((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MapForm::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_MapForm.data,
    qt_meta_data_MapForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MapForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MapForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MapForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MapForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
