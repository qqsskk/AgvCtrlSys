/********************************************************************************
** Form generated from reading UI file 'LoginSetForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINSETFORM_H
#define UI_LOGINSETFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "LineEditEx.h"
#include "PushButtonEx.h"

QT_BEGIN_NAMESPACE

class Ui_LoginSetForm
{
public:
    QLabel *label_2;
    LineEditEx *lineEditSerName;
    QLabel *label_3;
    LineEditEx *lineEditDbName;
    LineEditEx *lineEditLoginPwd;
    LineEditEx *lineEditLoginName;
    QLabel *label_4;
    QLabel *label_5;
    PushButtonEx *pushButtonCancel;
    PushButtonEx *pushButtonOk;
    QPushButton *pushButtonTitle;

    void setupUi(QWidget *LoginSetForm)
    {
        if (LoginSetForm->objectName().isEmpty())
            LoginSetForm->setObjectName(QString::fromUtf8("LoginSetForm"));
        LoginSetForm->resize(450, 300);
        label_2 = new QLabel(LoginSetForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 82, 71, 21));
        lineEditSerName = new LineEditEx(LoginSetForm);
        lineEditSerName->setObjectName(QString::fromUtf8("lineEditSerName"));
        lineEditSerName->setGeometry(QRect(170, 76, 191, 31));
        label_3 = new QLabel(LoginSetForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 121, 71, 21));
        lineEditDbName = new LineEditEx(LoginSetForm);
        lineEditDbName->setObjectName(QString::fromUtf8("lineEditDbName"));
        lineEditDbName->setGeometry(QRect(170, 116, 191, 31));
        lineEditLoginPwd = new LineEditEx(LoginSetForm);
        lineEditLoginPwd->setObjectName(QString::fromUtf8("lineEditLoginPwd"));
        lineEditLoginPwd->setGeometry(QRect(170, 200, 191, 31));
        lineEditLoginName = new LineEditEx(LoginSetForm);
        lineEditLoginName->setObjectName(QString::fromUtf8("lineEditLoginName"));
        lineEditLoginName->setGeometry(QRect(170, 157, 191, 31));
        label_4 = new QLabel(LoginSetForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 162, 71, 21));
        label_5 = new QLabel(LoginSetForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 205, 71, 21));
        pushButtonCancel = new PushButtonEx(LoginSetForm);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(90, 250, 81, 31));
        pushButtonOk = new PushButtonEx(LoginSetForm);
        pushButtonOk->setObjectName(QString::fromUtf8("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(280, 250, 81, 31));
        pushButtonTitle = new QPushButton(LoginSetForm);
        pushButtonTitle->setObjectName(QString::fromUtf8("pushButtonTitle"));
        pushButtonTitle->setGeometry(QRect(0, 0, 451, 51));
        pushButtonTitle->setAcceptDrops(true);

        retranslateUi(LoginSetForm);

        QMetaObject::connectSlotsByName(LoginSetForm);
    } // setupUi

    void retranslateUi(QWidget *LoginSetForm)
    {
        LoginSetForm->setWindowTitle(QApplication::translate("LoginSetForm", "Form", nullptr));
        label_2->setText(QApplication::translate("LoginSetForm", "\346\234\215\345\212\241\345\231\250\345\220\215\347\247\260\357\274\232", nullptr));
        label_3->setText(QApplication::translate("LoginSetForm", "\346\225\260\346\215\256\345\272\223\345\220\215\357\274\232", nullptr));
        label_4->setText(QApplication::translate("LoginSetForm", "\347\231\273\345\275\225\345\220\215\357\274\232", nullptr));
        label_5->setText(QApplication::translate("LoginSetForm", "\345\257\206\347\240\201\357\274\232", nullptr));
        pushButtonCancel->setText(QApplication::translate("LoginSetForm", "\345\217\226\346\266\210", nullptr));
        pushButtonOk->setText(QApplication::translate("LoginSetForm", "\347\241\256\345\256\232", nullptr));
        pushButtonTitle->setText(QApplication::translate("LoginSetForm", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginSetForm: public Ui_LoginSetForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINSETFORM_H
