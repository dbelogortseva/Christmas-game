/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[38];
    char stringdata0[220];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 7), // "exitApp"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 12), // "startingGame"
QT_MOC_LITERAL(33, 11), // "OnTimerJump"
QT_MOC_LITERAL(45, 12), // "OnTimerRoofs"
QT_MOC_LITERAL(58, 10), // "paintEvent"
QT_MOC_LITERAL(69, 12), // "QPaintEvent*"
QT_MOC_LITERAL(82, 13), // "keyPressEvent"
QT_MOC_LITERAL(96, 10), // "QKeyEvent*"
QT_MOC_LITERAL(107, 15), // "mousePressEvent"
QT_MOC_LITERAL(123, 12), // "QMouseEvent*"
QT_MOC_LITERAL(136, 5), // "event"
QT_MOC_LITERAL(142, 16), // "checkCollisionUp"
QT_MOC_LITERAL(159, 18), // "checkCollisionLeft"
QT_MOC_LITERAL(178, 12), // "checkCollect"
QT_MOC_LITERAL(191, 8), // "gameStop"
QT_MOC_LITERAL(200, 4), // "exit"
QT_MOC_LITERAL(205, 14) // "returnGameMenu"

    },
    "MainWindow\0exitApp\0\0startingGame\0"
    "OnTimerJump\0OnTimerRoofs\0paintEvent\0"
    "QPaintEvent*\0keyPressEvent\0QKeyEvent*\0"
    "mousePressEvent\0QMouseEvent*\0event\0"
    "checkCollisionUp\0checkCollisionLeft\0"
    "checkCollect\0gameStop\0exit\0returnGameMenu"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   93,    2, 0x0a,    1 /* Public */,
       4,    0,   94,    2, 0x0a,    2 /* Public */,
       5,    0,   95,    2, 0x0a,    3 /* Public */,
       6,    1,   96,    2, 0x0a,    4 /* Public */,
       8,    1,   99,    2, 0x0a,    6 /* Public */,
      10,    1,  102,    2, 0x0a,    8 /* Public */,
      13,    0,  105,    2, 0x0a,   10 /* Public */,
      14,    0,  106,    2, 0x0a,   11 /* Public */,
      15,    0,  107,    2, 0x0a,   12 /* Public */,
      16,    0,  108,    2, 0x0a,   13 /* Public */,
      17,    0,  109,    2, 0x0a,   14 /* Public */,
      18,    0,  110,    2, 0x0a,   15 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->exitApp(); break;
        case 1: _t->startingGame(); break;
        case 2: _t->OnTimerJump(); break;
        case 3: _t->OnTimerRoofs(); break;
        case 4: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 5: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 6: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->checkCollisionUp(); break;
        case 8: _t->checkCollisionLeft(); break;
        case 9: _t->checkCollect(); break;
        case 10: _t->gameStop(); break;
        case 11: _t->exit(); break;
        case 12: _t->returnGameMenu(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::exitApp)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPaintEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QKeyEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::exitApp()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
