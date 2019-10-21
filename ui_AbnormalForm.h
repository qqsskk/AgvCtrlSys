/********************************************************************************
** Form generated from reading UI file 'AbnormalForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABNORMALFORM_H
#define UI_ABNORMALFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "TableViewEx.h"

QT_BEGIN_NAMESPACE

class Ui_AbnormalForm
{
public:
    QGridLayout *gridLayout;
    TableViewEx *tableView;

    void setupUi(QWidget *AbnormalForm)
    {
        if (AbnormalForm->objectName().isEmpty())
            AbnormalForm->setObjectName(QString::fromUtf8("AbnormalForm"));
        AbnormalForm->resize(751, 433);
        gridLayout = new QGridLayout(AbnormalForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new TableViewEx(AbnormalForm);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        retranslateUi(AbnormalForm);

        QMetaObject::connectSlotsByName(AbnormalForm);
    } // setupUi

    void retranslateUi(QWidget *AbnormalForm)
    {
        AbnormalForm->setWindowTitle(QApplication::translate("AbnormalForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AbnormalForm: public Ui_AbnormalForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABNORMALFORM_H
