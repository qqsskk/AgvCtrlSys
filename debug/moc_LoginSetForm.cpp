/****************************************************************************
** Meta object code from reading C++ file 'LoginSetForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LoginSetForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LoginSetForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LoginSetForm_t {
    QByteArrayData data[8];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoginSetForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoginSetForm_t qt_meta_stringdata_LoginSetForm = {
    {
QT_MOC_LITERAL(0, 0, 12), // "LoginSetForm"
QT_MOC_LITERAL(1, 13, 13), // "setFormClosed"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 12), // "onEyeToggled"
QT_MOC_LITERAL(4, 41, 7), // "checked"
QT_MOC_LITERAL(5, 49, 27), // "on_pushButtonCancel_clicked"
QT_MOC_LITERAL(6, 77, 23), // "on_pushButtonOk_clicked"
QT_MOC_LITERAL(7, 101, 19) // "onCloseLoginSetForm"

    },
    "LoginSetForm\0setFormClosed\0\0onEyeToggled\0"
    "checked\0on_pushButtonCancel_clicked\0"
    "on_pushButtonOk_clicked\0onCloseLoginSetForm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoginSetForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   40,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LoginSetForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LoginSetForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setFormClosed(); break;
        case 1: _t->onEyeToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_pushButtonCancel_clicked(); break;
        case 3: _t->on_pushButtonOk_clicked(); break;
        case 4: _t->onCloseLoginSetForm(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LoginSetForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginSetForm::setFormClosed)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LoginSetForm::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_LoginSetForm.data,
    qt_meta_data_LoginSetForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LoginSetForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginSetForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LoginSetForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LoginSetForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void LoginSetForm::setFormClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
