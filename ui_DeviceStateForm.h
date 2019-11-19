/********************************************************************************
** Form generated from reading UI file 'DeviceStateForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICESTATEFORM_H
#define UI_DEVICESTATEFORM_H

#include <GroupBoxEx.h>
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
    GroupBoxEx *groupBox_1;
    QGridLayout *gridLayout_10;
    TableViewEx *tableViewAgv;
    GroupBoxEx *groupBox_2;
    QGridLayout *gridLayout_11;
    TableViewEx *tableViewCaller;

    void setupUi(QWidget *DeviceStateForm)
    {
        if (DeviceStateForm->objectName().isEmpty())
            DeviceStateForm->setObjectName(QString::fromUtf8("DeviceStateForm"));
        DeviceStateForm->resize(633, 486);
        gridLayout = new QGridLayout(DeviceStateForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_1 = new GroupBoxEx(DeviceStateForm);
        groupBox_1->setObjectName(QString::fromUtf8("groupBox_1"));
        groupBox_1->setMinimumSize(QSize(0, 0));
        gridLayout_10 = new QGridLayout(groupBox_1);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(-1, 45, -1, -1);
        tableViewAgv = new TableViewEx(groupBox_1);
        tableViewAgv->setObjectName(QString::fromUtf8("tableViewAgv"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableViewAgv->sizePolicy().hasHeightForWidth());
        tableViewAgv->setSizePolicy(sizePolicy);
        tableViewAgv->setMinimumSize(QSize(0, 0));

        gridLayout_10->addWidget(tableViewAgv, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_1, 0, 0, 1, 1);

        groupBox_2 = new GroupBoxEx(DeviceStateForm);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 0));
        gridLayout_11 = new QGridLayout(groupBox_2);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(-1, 45, -1, -1);
        tableViewCaller = new TableViewEx(groupBox_2);
        tableViewCaller->setObjectName(QString::fromUtf8("tableViewCaller"));
        sizePolicy.setHeightForWidth(tableViewCaller->sizePolicy().hasHeightForWidth());
        tableViewCaller->setSizePolicy(sizePolicy);
        tableViewCaller->setMinimumSize(QSize(0, 0));

        gridLayout_11->addWidget(tableViewCaller, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);


        retranslateUi(DeviceStateForm);

        QMetaObject::connectSlotsByName(DeviceStateForm);
    } // setupUi

    void retranslateUi(QWidget *DeviceStateForm)
    {
        DeviceStateForm->setWindowTitle(QApplication::translate("DeviceStateForm", "Form", nullptr));
        groupBox_1->setTitle(QString());
        groupBox_2->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class DeviceStateForm: public Ui_DeviceStateForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICESTATEFORM_H
