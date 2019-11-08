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
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "LineEditEx.h"
#include "PushButtonEx.h"

QT_BEGIN_NAMESPACE

class Ui_LoginForm
{
public:
    QLabel *label_2;
    LineEditEx *lineEdit_userName;
    LineEditEx *lineEdit_passwd;
    QLabel *label;
    PushButtonEx *pushButton_exit;
    PushButtonEx *pushButton_login;
    QPushButton *pushButtonTitle;
    QToolButton *toolButtonSet;
    QToolButton *toolButtonEye;

    void setupUi(QWidget *LoginForm)
    {
        if (LoginForm->objectName().isEmpty())
            LoginForm->setObjectName(QString::fromUtf8("LoginForm"));
        LoginForm->resize(450, 300);
        label_2 = new QLabel(LoginForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 138, 54, 16));
        lineEdit_userName = new LineEditEx(LoginForm);
        lineEdit_userName->setObjectName(QString::fromUtf8("lineEdit_userName"));
        lineEdit_userName->setGeometry(QRect(150, 130, 191, 31));
        lineEdit_passwd = new LineEditEx(LoginForm);
        lineEdit_passwd->setObjectName(QString::fromUtf8("lineEdit_passwd"));
        lineEdit_passwd->setGeometry(QRect(150, 180, 191, 31));
        lineEdit_passwd->setEchoMode(QLineEdit::Password);
        label = new QLabel(LoginForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 188, 54, 16));
        pushButton_exit = new PushButtonEx(LoginForm);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(90, 240, 101, 31));
        pushButton_login = new PushButtonEx(LoginForm);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setGeometry(QRect(240, 240, 101, 31));
        pushButtonTitle = new QPushButton(LoginForm);
        pushButtonTitle->setObjectName(QString::fromUtf8("pushButtonTitle"));
        pushButtonTitle->setGeometry(QRect(0, 0, 451, 91));
        toolButtonSet = new QToolButton(LoginForm);
        toolButtonSet->setObjectName(QString::fromUtf8("toolButtonSet"));
        toolButtonSet->setGeometry(QRect(416, 92, 32, 32));
        toolButtonEye = new QToolButton(LoginForm);
        toolButtonEye->setObjectName(QString::fromUtf8("toolButtonEye"));
        toolButtonEye->setGeometry(QRect(352, 185, 21, 21));
        toolButtonEye->setCheckable(true);
        toolButtonEye->setChecked(false);
        QWidget::setTabOrder(lineEdit_userName, lineEdit_passwd);
        QWidget::setTabOrder(lineEdit_passwd, pushButton_exit);
        QWidget::setTabOrder(pushButton_exit, pushButton_login);
        QWidget::setTabOrder(pushButton_login, toolButtonSet);
        QWidget::setTabOrder(toolButtonSet, pushButtonTitle);

        retranslateUi(LoginForm);

        QMetaObject::connectSlotsByName(LoginForm);
    } // setupUi

    void retranslateUi(QWidget *LoginForm)
    {
        LoginForm->setWindowTitle(QApplication::translate("LoginForm", "Form", nullptr));
        label_2->setText(QApplication::translate("LoginForm", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label->setText(QApplication::translate("LoginForm", "\345\257\206  \347\240\201\357\274\232", nullptr));
        pushButton_exit->setText(QApplication::translate("LoginForm", "\351\200\200\345\207\272", nullptr));
        pushButton_login->setText(QApplication::translate("LoginForm", "\347\231\273\345\275\225", nullptr));
        pushButtonTitle->setText(QApplication::translate("LoginForm", "PushButton", nullptr));
        toolButtonSet->setText(QString());
        toolButtonEye->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
