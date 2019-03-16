/****************************************************************************
** Meta object code from reading C++ file 'SearchWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CanopyGUI/SearchWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SearchWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SearchWindow_t {
    QByteArrayData data[13];
    char stringdata0[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SearchWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SearchWindow_t qt_meta_stringdata_SearchWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SearchWindow"
QT_MOC_LITERAL(1, 13, 13), // "removeKeyword"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 4), // "word"
QT_MOC_LITERAL(4, 33, 21), // "on_backButton_clicked"
QT_MOC_LITERAL(5, 55, 23), // "on_searchButton_clicked"
QT_MOC_LITERAL(6, 79, 25), // "on_doSearchButton_clicked"
QT_MOC_LITERAL(7, 105, 19), // "on_inButton_clicked"
QT_MOC_LITERAL(8, 125, 20), // "on_outButton_clicked"
QT_MOC_LITERAL(9, 146, 22), // "on_closeButton_clicked"
QT_MOC_LITERAL(10, 169, 27), // "on_addKeywordButton_clicked"
QT_MOC_LITERAL(11, 197, 29), // "on_wordFreqFilter_textChanged"
QT_MOC_LITERAL(12, 227, 4) // "arg1"

    },
    "SearchWindow\0removeKeyword\0\0word\0"
    "on_backButton_clicked\0on_searchButton_clicked\0"
    "on_doSearchButton_clicked\0on_inButton_clicked\0"
    "on_outButton_clicked\0on_closeButton_clicked\0"
    "on_addKeywordButton_clicked\0"
    "on_wordFreqFilter_textChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SearchWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       4,    0,   62,    2, 0x08 /* Private */,
       5,    0,   63,    2, 0x08 /* Private */,
       6,    0,   64,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    1,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,

       0        // eod
};

void SearchWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SearchWindow *_t = static_cast<SearchWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->removeKeyword((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_backButton_clicked(); break;
        case 2: _t->on_searchButton_clicked(); break;
        case 3: _t->on_doSearchButton_clicked(); break;
        case 4: _t->on_inButton_clicked(); break;
        case 5: _t->on_outButton_clicked(); break;
        case 6: _t->on_closeButton_clicked(); break;
        case 7: _t->on_addKeywordButton_clicked(); break;
        case 8: _t->on_wordFreqFilter_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SearchWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SearchWindow.data,
      qt_meta_data_SearchWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SearchWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SearchWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SearchWindow.stringdata0))
        return static_cast<void*>(const_cast< SearchWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SearchWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
