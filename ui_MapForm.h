/********************************************************************************
** Form generated from reading UI file 'MapForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPFORM_H
#define UI_MAPFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "PushButtonEx.h"

QT_BEGIN_NAMESPACE

class Ui_MapForm
{
public:
    PushButtonEx *test_2;

    void setupUi(QWidget *MapForm)
    {
        if (MapForm->objectName().isEmpty())
            MapForm->setObjectName(QString::fromUtf8("MapForm"));
        MapForm->resize(400, 300);
        test_2 = new PushButtonEx(MapForm);
        test_2->setObjectName(QString::fromUtf8("test_2"));
        test_2->setGeometry(QRect(9, 9, 111, 41));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(test_2->sizePolicy().hasHeightForWidth());
        test_2->setSizePolicy(sizePolicy);

        retranslateUi(MapForm);

        QMetaObject::connectSlotsByName(MapForm);
    } // setupUi

    void retranslateUi(QWidget *MapForm)
    {
        MapForm->setWindowTitle(QApplication::translate("MapForm", "Form", nullptr));
        test_2->setText(QApplication::translate("MapForm", "\346\265\213\350\257\225\346\214\211\351\222\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MapForm: public Ui_MapForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPFORM_H
