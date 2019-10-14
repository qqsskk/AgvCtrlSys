/********************************************************************************
** Form generated from reading UI file 'LoginForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "LineEditEx.h"
#include "PushButtonEx.h"

QT_BEGIN_NAMESPACE

class Ui_LoginForm
{
public:
    QLabel *label_username;
    LineEditEx *lineEdit_userName;
    LineEditEx *lineEdit_passwd;
    QLabel *label_passwd;
    PushButtonEx *pushButton_exit;
    PushButtonEx *pushButton_login;
    QPushButton *pushButtonTitle;

    void setupUi(QWidget *LoginForm)
    {
        if (LoginForm->objectName().isEmpty())
            LoginForm->setObjectName(QString::fromUtf8("LoginForm"));
        LoginForm->resize(450, 300);
        label_username = new QLabel(LoginForm);
        label_username->setObjectName(QString::fromUtf8("label_username"));
        label_username->setGeometry(QRect(90, 140, 54, 12));
        lineEdit_userName = new LineEditEx(LoginForm);
        lineEdit_userName->setObjectName(QString::fromUtf8("lineEdit_userName"));
        lineEdit_userName->setGeometry(QRect(150, 130, 191, 31));
        lineEdit_passwd = new LineEditEx(LoginForm);
        lineEdit_passwd->setObjectName(QString::fromUtf8("lineEdit_passwd"));
        lineEdit_passwd->setGeometry(QRect(150, 180, 191, 31));
        lineEdit_passwd->setEchoMode(QLineEdit::Password);
        label_passwd = new QLabel(LoginForm);
        label_passwd->setObjectName(QString::fromUtf8("label_passwd"));
        label_passwd->setGeometry(QRect(90, 190, 54, 12));
        pushButton_exit = new PushButtonEx(LoginForm);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(90, 240, 101, 31));
        pushButton_login = new PushButtonEx(LoginForm);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setGeometry(QRect(240, 240, 101, 31));
        pushButtonTitle = new QPushButton(LoginForm);
        pushButtonTitle->setObjectName(QString::fromUtf8("pushButtonTitle"));
        pushButtonTitle->setGeometry(QRect(0, 0, 451, 91));

        retranslateUi(LoginForm);

        QMetaObject::connectSlotsByName(LoginForm);
    } // setupUi

    void retranslateUi(QWidget *LoginForm)
    {
        LoginForm->setWindowTitle(QApplication::translate("LoginForm", "Form", nullptr));
        label_username->setText(QApplication::translate("LoginForm", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_passwd->setText(QApplication::translate("LoginForm", "\345\257\206  \347\240\201\357\274\232", nullptr));
        pushButton_exit->setText(QApplication::translate("LoginForm", "\351\200\200\345\207\272", nullptr));
        pushButton_login->setText(QApplication::translate("LoginForm", "\347\231\273\345\275\225", nullptr));
        pushButtonTitle->setText(QApplication::translate("LoginForm", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
