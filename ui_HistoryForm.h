/********************************************************************************
** Form generated from reading UI file 'HistoryForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYFORM_H
#define UI_HISTORYFORM_H

#include <ComboBoxEx.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistoryForm
{
public:
    ComboBoxEx *comboBox;
    ComboBoxEx *comboBox_2;
    ComboBoxEx *comboBox_3;

    void setupUi(QWidget *HistoryForm)
    {
        if (HistoryForm->objectName().isEmpty())
            HistoryForm->setObjectName(QString::fromUtf8("HistoryForm"));
        HistoryForm->resize(400, 300);
        comboBox = new ComboBoxEx(HistoryForm);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(90, 70, 241, 31));
        comboBox_2 = new ComboBoxEx(HistoryForm);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setEnabled(false);
        comboBox_2->setGeometry(QRect(90, 180, 161, 22));
        comboBox_3 = new ComboBoxEx(HistoryForm);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setEnabled(true);
        comboBox_3->setGeometry(QRect(90, 150, 161, 22));

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
