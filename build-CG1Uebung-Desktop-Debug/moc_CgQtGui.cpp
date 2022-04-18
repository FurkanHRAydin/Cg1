/****************************************************************************
** Meta object code from reading C++ file 'CgQtGui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Schreibtisch/Uni/Cg1/CG1Uebung/CgQtViewer/CgQtGui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CgQtGui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CgQtGui_t {
    QByteArrayData data[19];
    char stringdata0[342];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CgQtGui_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CgQtGui_t qt_meta_stringdata_CgQtGui = {
    {
QT_MOC_LITERAL(0, 0, 7), // "CgQtGui"
QT_MOC_LITERAL(1, 8, 10), // "mouseEvent"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 12), // "QMouseEvent*"
QT_MOC_LITERAL(4, 33, 5), // "event"
QT_MOC_LITERAL(5, 39, 15), // "viewportChanged"
QT_MOC_LITERAL(6, 55, 20), // "slotTrackballChanged"
QT_MOC_LITERAL(7, 76, 21), // "slotMySpinBox1Changed"
QT_MOC_LITERAL(8, 98, 21), // "slotMySpinBox2Changed"
QT_MOC_LITERAL(9, 120, 21), // "slotMySpinBox3Changed"
QT_MOC_LITERAL(10, 142, 21), // "slotMySpinBox4Changed"
QT_MOC_LITERAL(11, 164, 21), // "slotMySpinBox5Changed"
QT_MOC_LITERAL(12, 186, 22), // "slotMyCheckBox1Changed"
QT_MOC_LITERAL(13, 209, 20), // "slotMyButton1Pressed"
QT_MOC_LITERAL(14, 230, 20), // "slotMyButton2Pressed"
QT_MOC_LITERAL(15, 251, 20), // "slotMyButton3Pressed"
QT_MOC_LITERAL(16, 272, 20), // "slotMyButton4Pressed"
QT_MOC_LITERAL(17, 293, 31), // "slotButtonGroupSelectionChanged"
QT_MOC_LITERAL(18, 325, 16) // "slotLoadMeshFile"

    },
    "CgQtGui\0mouseEvent\0\0QMouseEvent*\0event\0"
    "viewportChanged\0slotTrackballChanged\0"
    "slotMySpinBox1Changed\0slotMySpinBox2Changed\0"
    "slotMySpinBox3Changed\0slotMySpinBox4Changed\0"
    "slotMySpinBox5Changed\0slotMyCheckBox1Changed\0"
    "slotMyButton1Pressed\0slotMyButton2Pressed\0"
    "slotMyButton3Pressed\0slotMyButton4Pressed\0"
    "slotButtonGroupSelectionChanged\0"
    "slotLoadMeshFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CgQtGui[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x08 /* Private */,
       5,    2,   92,    2, 0x08 /* Private */,
       6,    0,   97,    2, 0x08 /* Private */,
       7,    0,   98,    2, 0x08 /* Private */,
       8,    0,   99,    2, 0x08 /* Private */,
       9,    0,  100,    2, 0x08 /* Private */,
      10,    0,  101,    2, 0x08 /* Private */,
      11,    0,  102,    2, 0x08 /* Private */,
      12,    0,  103,    2, 0x08 /* Private */,
      13,    0,  104,    2, 0x08 /* Private */,
      14,    0,  105,    2, 0x08 /* Private */,
      15,    0,  106,    2, 0x08 /* Private */,
      16,    0,  107,    2, 0x08 /* Private */,
      17,    0,  108,    2, 0x08 /* Private */,
      18,    0,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CgQtGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CgQtGui *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mouseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->viewportChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->slotTrackballChanged(); break;
        case 3: _t->slotMySpinBox1Changed(); break;
        case 4: _t->slotMySpinBox2Changed(); break;
        case 5: _t->slotMySpinBox3Changed(); break;
        case 6: _t->slotMySpinBox4Changed(); break;
        case 7: _t->slotMySpinBox5Changed(); break;
        case 8: _t->slotMyCheckBox1Changed(); break;
        case 9: _t->slotMyButton1Pressed(); break;
        case 10: _t->slotMyButton2Pressed(); break;
        case 11: _t->slotMyButton3Pressed(); break;
        case 12: _t->slotMyButton4Pressed(); break;
        case 13: _t->slotButtonGroupSelectionChanged(); break;
        case 14: _t->slotLoadMeshFile(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CgQtGui::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_CgQtGui.data,
    qt_meta_data_CgQtGui,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CgQtGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CgQtGui::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CgQtGui.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "CgObservable"))
        return static_cast< CgObservable*>(this);
    return QWidget::qt_metacast(_clname);
}

int CgQtGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
