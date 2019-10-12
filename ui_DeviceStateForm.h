/********************************************************************************
** Form generated from reading UI file 'DeviceStateForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICESTATEFORM_H
#define UI_DEVICESTATEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "TableViewEx.h"

QT_BEGIN_NAMESPACE

class Ui_DeviceStateForm
{
public:
    QGridLayout *gridLayout;
    TableViewEx *tableView;

    void setupUi(QWidget *DeviceStateForm)
    {
        if (DeviceStateForm->objectName().isEmpty())
            DeviceStateForm->setObjectName(QString::fromUtf8("DeviceStateForm"));
        DeviceStateForm->resize(562, 425);
        gridLayout = new QGridLayout(DeviceStateForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new TableViewEx(DeviceStateForm);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        retranslateUi(DeviceStateForm);

        QMetaObject::connectSlotsByName(DeviceStateForm);
    } // setupUi

    void retranslateUi(QWidget *DeviceStateForm)
    {
        DeviceStateForm->setWindowTitle(QApplication::translate("DeviceStateForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviceStateForm: public Ui_DeviceStateForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICESTATEFORM_H
