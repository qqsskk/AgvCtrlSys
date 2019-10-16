/********************************************************************************
** Form generated from reading UI file 'HistoryForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYFORM_H
#define UI_HISTORYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "TableViewEx.h"

QT_BEGIN_NAMESPACE

class Ui_HistoryForm
{
public:
    QGridLayout *gridLayout;
    TableViewEx *tableView;

    void setupUi(QWidget *HistoryForm)
    {
        if (HistoryForm->objectName().isEmpty())
            HistoryForm->setObjectName(QString::fromUtf8("HistoryForm"));
        HistoryForm->resize(355, 295);
        gridLayout = new QGridLayout(HistoryForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new TableViewEx(HistoryForm);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        retranslateUi(HistoryForm);

        QMetaObject::connectSlotsByName(HistoryForm);
    } // setupUi

    void retranslateUi(QWidget *HistoryForm)
    {
        HistoryForm->setWindowTitle(QApplication::translate("HistoryForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistoryForm: public Ui_HistoryForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYFORM_H
