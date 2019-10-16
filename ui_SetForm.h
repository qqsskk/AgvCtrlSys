/********************************************************************************
** Form generated from reading UI file 'SetForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETFORM_H
#define UI_SETFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "LineEditEx.h"

QT_BEGIN_NAMESPACE

class Ui_SetForm
{
public:
    QLabel *labelTitle;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    LineEditEx *lineEditSerName;
    LineEditEx *lineEditDbName;
    LineEditEx *lineEditLoginName;
    LineEditEx *lineEditLoginPwd;

    void setupUi(QWidget *SetForm)
    {
        if (SetForm->objectName().isEmpty())
            SetForm->setObjectName(QString::fromUtf8("SetForm"));
        SetForm->resize(450, 300);
        labelTitle = new QLabel(SetForm);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setGeometry(QRect(40, 20, 71, 21));
        labelTitle->setAutoFillBackground(false);
        label_2 = new QLabel(SetForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 76, 71, 21));
        label_3 = new QLabel(SetForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 129, 71, 21));
        label_4 = new QLabel(SetForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 181, 71, 21));
        label_5 = new QLabel(SetForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 234, 71, 21));
        lineEditSerName = new LineEditEx(SetForm);
        lineEditSerName->setObjectName(QString::fromUtf8("lineEditSerName"));
        lineEditSerName->setGeometry(QRect(170, 70, 191, 31));
        lineEditDbName = new LineEditEx(SetForm);
        lineEditDbName->setObjectName(QString::fromUtf8("lineEditDbName"));
        lineEditDbName->setGeometry(QRect(170, 124, 191, 31));
        lineEditLoginName = new LineEditEx(SetForm);
        lineEditLoginName->setObjectName(QString::fromUtf8("lineEditLoginName"));
        lineEditLoginName->setGeometry(QRect(170, 176, 191, 31));
        lineEditLoginPwd = new LineEditEx(SetForm);
        lineEditLoginPwd->setObjectName(QString::fromUtf8("lineEditLoginPwd"));
        lineEditLoginPwd->setGeometry(QRect(170, 229, 191, 31));

        retranslateUi(SetForm);

        QMetaObject::connectSlotsByName(SetForm);
    } // setupUi

    void retranslateUi(QWidget *SetForm)
    {
        SetForm->setWindowTitle(QApplication::translate("SetForm", "Form", nullptr));
        labelTitle->setText(QApplication::translate("SetForm", "\346\234\215\345\212\241\345\231\250\351\205\215\347\275\256", nullptr));
        label_2->setText(QApplication::translate("SetForm", "\346\234\215\345\212\241\345\231\250\345\220\215\347\247\260\357\274\232", nullptr));
        label_3->setText(QApplication::translate("SetForm", "\346\225\260\346\215\256\345\272\223\345\220\215\357\274\232", nullptr));
        label_4->setText(QApplication::translate("SetForm", "\347\231\273\345\275\225\345\220\215\357\274\232", nullptr));
        label_5->setText(QApplication::translate("SetForm", "\345\257\206\347\240\201\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetForm: public Ui_SetForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETFORM_H
