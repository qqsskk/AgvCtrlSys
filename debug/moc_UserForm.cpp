/****************************************************************************
** Meta object code from reading C++ file 'UserForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../UserForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UserForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UserForm_t {
    QByteArrayData data[14];
    char stringdata0[327];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserForm_t qt_meta_stringdata_UserForm = {
    {
QT_MOC_LITERAL(0, 0, 8), // "UserForm"
QT_MOC_LITERAL(1, 9, 33), // "on_pushButtonChangePasswd_cli..."
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 36), // "on_pushButtonChangePwdCancel_..."
QT_MOC_LITERAL(4, 81, 32), // "on_pushButtonChangePwdOk_clicked"
QT_MOC_LITERAL(5, 114, 31), // "on_pushButtonLogoutUser_clicked"
QT_MOC_LITERAL(6, 146, 20), // "onBtnOkClickedLogout"
QT_MOC_LITERAL(7, 167, 24), // "onBtnCancelClickedLogout"
QT_MOC_LITERAL(8, 192, 17), // "onClickedUserList"
QT_MOC_LITERAL(9, 210, 11), // "QModelIndex"
QT_MOC_LITERAL(10, 222, 28), // "on_pushButtonUserAdd_clicked"
QT_MOC_LITERAL(11, 251, 31), // "on_pushButtonUserChange_clicked"
QT_MOC_LITERAL(12, 283, 28), // "on_pushButtonUserDel_clicked"
QT_MOC_LITERAL(13, 312, 14) // "onExitProgress"

    },
    "UserForm\0on_pushButtonChangePasswd_clicked\0"
    "\0on_pushButtonChangePwdCancel_clicked\0"
    "on_pushButtonChangePwdOk_clicked\0"
    "on_pushButtonLogoutUser_clicked\0"
    "onBtnOkClickedLogout\0onBtnCancelClickedLogout\0"
    "onClickedUserList\0QModelIndex\0"
    "on_pushButtonUserAdd_clicked\0"
    "on_pushButtonUserChange_clicked\0"
    "on_pushButtonUserDel_clicked\0"
    "onExitProgress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    1,   75,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    0,   80,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UserForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UserForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButtonChangePasswd_clicked(); break;
        case 1: _t->on_pushButtonChangePwdCancel_clicked(); break;
        case 2: _t->on_pushButtonChangePwdOk_clicked(); break;
        case 3: _t->on_pushButtonLogoutUser_clicked(); break;
        case 4: _t->onBtnOkClickedLogout(); break;
        case 5: _t->onBtnCancelClickedLogout(); break;
        case 6: _t->onClickedUserList((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_pushButtonUserAdd_clicked(); break;
        case 8: _t->on_pushButtonUserChange_clicked(); break;
        case 9: _t->on_pushButtonUserDel_clicked(); break;
        case 10: _t->onExitProgress(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UserForm::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_UserForm.data,
    qt_meta_data_UserForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UserForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int UserForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
