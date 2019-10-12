/********************************************************************************
** Form generated from reading UI file 'UserForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERFORM_H
#define UI_USERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserForm
{
public:
    QRadioButton *radioButton;

    void setupUi(QWidget *UserForm)
    {
        if (UserForm->objectName().isEmpty())
            UserForm->setObjectName(QString::fromUtf8("UserForm"));
        UserForm->resize(400, 300);
        radioButton = new QRadioButton(UserForm);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(140, 150, 91, 18));

        retranslateUi(UserForm);

        QMetaObject::connectSlotsByName(UserForm);
    } // setupUi

    void retranslateUi(QWidget *UserForm)
    {
        UserForm->setWindowTitle(QApplication::translate("UserForm", "Form", nullptr));
        radioButton->setText(QApplication::translate("UserForm", "RadioButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserForm: public Ui_UserForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERFORM_H
