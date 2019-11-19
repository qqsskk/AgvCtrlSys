/****************************************************************************
** Meta object code from reading C++ file 'ConfigForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ConfigForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ConfigForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConfigForm_t {
    QByteArrayData data[12];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConfigForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConfigForm_t qt_meta_stringdata_ConfigForm = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ConfigForm"
QT_MOC_LITERAL(1, 11, 26), // "on_pushButtonSetDb_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 27), // "on_pushButtonSetNet_clicked"
QT_MOC_LITERAL(4, 67, 22), // "onNetServerStateChange"
QT_MOC_LITERAL(5, 90, 6), // "isLink"
QT_MOC_LITERAL(6, 97, 23), // "onSerialPortStateChange"
QT_MOC_LITERAL(7, 121, 6), // "isOpen"
QT_MOC_LITERAL(8, 128, 27), // "on_pushButtonSetCom_clicked"
QT_MOC_LITERAL(9, 156, 37), // "on_comboBoxComName_currentTex..."
QT_MOC_LITERAL(10, 194, 4), // "arg1"
QT_MOC_LITERAL(11, 199, 28) // "on_pushButtonRefresh_clicked"

    },
    "ConfigForm\0on_pushButtonSetDb_clicked\0"
    "\0on_pushButtonSetNet_clicked\0"
    "onNetServerStateChange\0isLink\0"
    "onSerialPortStateChange\0isOpen\0"
    "on_pushButtonSetCom_clicked\0"
    "on_comboBoxComName_currentTextChanged\0"
    "arg1\0on_pushButtonRefresh_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConfigForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    1,   51,    2, 0x08 /* Private */,
       6,    1,   54,    2, 0x08 /* Private */,
       8,    0,   57,    2, 0x08 /* Private */,
       9,    1,   58,    2, 0x08 /* Private */,
      11,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,

       0        // eod
};

void ConfigForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConfigForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButtonSetDb_clicked(); break;
        case 1: _t->on_pushButtonSetNet_clicked(); break;
        case 2: _t->onNetServerStateChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onSerialPortStateChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_pushButtonSetCom_clicked(); break;
        case 5: _t->on_comboBoxComName_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_pushButtonRefresh_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ConfigForm::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ConfigForm.data,
    qt_meta_data_ConfigForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ConfigForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfigForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ConfigForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
