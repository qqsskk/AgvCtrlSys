/****************************************************************************
** Meta object code from reading C++ file 'ButtonEx.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ButtonEx.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ButtonEx.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ButtonEx_t {
    QByteArrayData data[24];
    char stringdata0[322];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ButtonEx_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ButtonEx_t qt_meta_stringdata_ButtonEx = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ButtonEx"
QT_MOC_LITERAL(1, 9, 13), // "buttonPressed"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "clicked"
QT_MOC_LITERAL(4, 32, 7), // "setText"
QT_MOC_LITERAL(5, 40, 4), // "text"
QT_MOC_LITERAL(6, 45, 12), // "setTextColor"
QT_MOC_LITERAL(7, 58, 9), // "textColor"
QT_MOC_LITERAL(8, 68, 22), // "setBorderOutColorStart"
QT_MOC_LITERAL(9, 91, 19), // "borderOutColorStart"
QT_MOC_LITERAL(10, 111, 20), // "setBorderOutColorEnd"
QT_MOC_LITERAL(11, 132, 17), // "borderOutColorEnd"
QT_MOC_LITERAL(12, 150, 21), // "setBorderInColorStart"
QT_MOC_LITERAL(13, 172, 18), // "borderInColorStart"
QT_MOC_LITERAL(14, 191, 19), // "setBorderInColorEnd"
QT_MOC_LITERAL(15, 211, 16), // "borderInColorEnd"
QT_MOC_LITERAL(16, 228, 10), // "setBgColor"
QT_MOC_LITERAL(17, 239, 7), // "bgColor"
QT_MOC_LITERAL(18, 247, 10), // "setCanMove"
QT_MOC_LITERAL(19, 258, 7), // "canMove"
QT_MOC_LITERAL(20, 266, 14), // "setShowOverlay"
QT_MOC_LITERAL(21, 281, 11), // "showOverlay"
QT_MOC_LITERAL(22, 293, 15), // "setOverlayColor"
QT_MOC_LITERAL(23, 309, 12) // "overlayColor"

    },
    "ButtonEx\0buttonPressed\0\0clicked\0setText\0"
    "text\0setTextColor\0textColor\0"
    "setBorderOutColorStart\0borderOutColorStart\0"
    "setBorderOutColorEnd\0borderOutColorEnd\0"
    "setBorderInColorStart\0borderInColorStart\0"
    "setBorderInColorEnd\0borderInColorEnd\0"
    "setBgColor\0bgColor\0setCanMove\0canMove\0"
    "setShowOverlay\0showOverlay\0setOverlayColor\0"
    "overlayColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ButtonEx[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
      10,  102, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   72,    2, 0x0a /* Public */,
       6,    1,   75,    2, 0x0a /* Public */,
       8,    1,   78,    2, 0x0a /* Public */,
      10,    1,   81,    2, 0x0a /* Public */,
      12,    1,   84,    2, 0x0a /* Public */,
      14,    1,   87,    2, 0x0a /* Public */,
      16,    1,   90,    2, 0x0a /* Public */,
      18,    1,   93,    2, 0x0a /* Public */,
      20,    1,   96,    2, 0x0a /* Public */,
      22,    1,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QColor,    7,
    QMetaType::Void, QMetaType::QColor,    9,
    QMetaType::Void, QMetaType::QColor,   11,
    QMetaType::Void, QMetaType::QColor,   13,
    QMetaType::Void, QMetaType::QColor,   15,
    QMetaType::Void, QMetaType::QColor,   17,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::QColor,   23,

 // properties: name, type, flags
       5, QMetaType::QString, 0x00095103,
       7, QMetaType::QColor, 0x00095103,
       9, QMetaType::QColor, 0x00095103,
      11, QMetaType::QColor, 0x00095103,
      13, QMetaType::QColor, 0x00095103,
      15, QMetaType::QColor, 0x00095103,
      17, QMetaType::QColor, 0x00095103,
      19, QMetaType::Bool, 0x00095103,
      21, QMetaType::Bool, 0x00095103,
      23, QMetaType::QColor, 0x00095103,

       0        // eod
};

void ButtonEx::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ButtonEx *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->buttonPressed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->setText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setTextColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 3: _t->setBorderOutColorStart((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 4: _t->setBorderOutColorEnd((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 5: _t->setBorderInColorStart((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 6: _t->setBorderInColorEnd((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 7: _t->setBgColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 8: _t->setCanMove((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->setShowOverlay((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->setOverlayColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ButtonEx::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ButtonEx::buttonPressed)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ButtonEx *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getText(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = _t->getTextColor(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = _t->getBorderOutColorStart(); break;
        case 3: *reinterpret_cast< QColor*>(_v) = _t->getBorderOutColorEnd(); break;
        case 4: *reinterpret_cast< QColor*>(_v) = _t->getBorderInColorStart(); break;
        case 5: *reinterpret_cast< QColor*>(_v) = _t->getBorderInColorEnd(); break;
        case 6: *reinterpret_cast< QColor*>(_v) = _t->getBgColor(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->getCanMove(); break;
        case 8: *reinterpret_cast< bool*>(_v) = _t->getShowOverlay(); break;
        case 9: *reinterpret_cast< QColor*>(_v) = _t->getOverlayColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ButtonEx *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setText(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setTextColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: _t->setBorderOutColorStart(*reinterpret_cast< QColor*>(_v)); break;
        case 3: _t->setBorderOutColorEnd(*reinterpret_cast< QColor*>(_v)); break;
        case 4: _t->setBorderInColorStart(*reinterpret_cast< QColor*>(_v)); break;
        case 5: _t->setBorderInColorEnd(*reinterpret_cast< QColor*>(_v)); break;
        case 6: _t->setBgColor(*reinterpret_cast< QColor*>(_v)); break;
        case 7: _t->setCanMove(*reinterpret_cast< bool*>(_v)); break;
        case 8: _t->setShowOverlay(*reinterpret_cast< bool*>(_v)); break;
        case 9: _t->setOverlayColor(*reinterpret_cast< QColor*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ButtonEx::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ButtonEx.data,
    qt_meta_data_ButtonEx,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ButtonEx::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ButtonEx::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ButtonEx.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ButtonEx::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ButtonEx::buttonPressed(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
