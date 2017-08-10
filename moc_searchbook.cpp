/****************************************************************************
** Meta object code from reading C++ file 'searchbook.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../assignmentGui/searchbook.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'searchbook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_searchbook_t {
    QByteArrayData data[14];
    char stringdata0[237];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_searchbook_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_searchbook_t qt_meta_stringdata_searchbook = {
    {
QT_MOC_LITERAL(0, 0, 10), // "searchbook"
QT_MOC_LITERAL(1, 11, 19), // "on_bookname_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "index"
QT_MOC_LITERAL(4, 38, 17), // "on_author_clicked"
QT_MOC_LITERAL(5, 56, 23), // "on_searchbutton_clicked"
QT_MOC_LITERAL(6, 80, 26), // "on_searchbox_returnPressed"
QT_MOC_LITERAL(7, 107, 16), // "on_Login_clicked"
QT_MOC_LITERAL(8, 124, 16), // "on_Logon_clicked"
QT_MOC_LITERAL(9, 141, 17), // "on_borrow_clicked"
QT_MOC_LITERAL(10, 159, 32), // "on_user_page_currentIndexChanged"
QT_MOC_LITERAL(11, 192, 15), // "on_year_clicked"
QT_MOC_LITERAL(12, 208, 23), // "on_spinBox_valueChanged"
QT_MOC_LITERAL(13, 232, 4) // "arg1"

    },
    "searchbook\0on_bookname_clicked\0\0index\0"
    "on_author_clicked\0on_searchbutton_clicked\0"
    "on_searchbox_returnPressed\0on_Login_clicked\0"
    "on_Logon_clicked\0on_borrow_clicked\0"
    "on_user_page_currentIndexChanged\0"
    "on_year_clicked\0on_spinBox_valueChanged\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_searchbook[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       4,    1,   67,    2, 0x08 /* Private */,
       5,    0,   70,    2, 0x08 /* Private */,
       6,    0,   71,    2, 0x08 /* Private */,
       7,    0,   72,    2, 0x08 /* Private */,
       8,    0,   73,    2, 0x08 /* Private */,
       9,    0,   74,    2, 0x08 /* Private */,
      10,    1,   75,    2, 0x08 /* Private */,
      11,    1,   78,    2, 0x08 /* Private */,
      12,    1,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void searchbook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        searchbook *_t = static_cast<searchbook *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_bookname_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_author_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_searchbutton_clicked(); break;
        case 3: _t->on_searchbox_returnPressed(); break;
        case 4: _t->on_Login_clicked(); break;
        case 5: _t->on_Logon_clicked(); break;
        case 6: _t->on_borrow_clicked(); break;
        case 7: _t->on_user_page_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_year_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->on_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject searchbook::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_searchbook.data,
      qt_meta_data_searchbook,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *searchbook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *searchbook::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_searchbook.stringdata0))
        return static_cast<void*>(const_cast< searchbook*>(this));
    return QWidget::qt_metacast(_clname);
}

int searchbook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
