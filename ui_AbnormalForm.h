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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AbnormalForm
{
public:
    QGroupBox *groupBox;

    void setupUi(QWidget *AbnormalForm)
    {
        if (AbnormalForm->objectName().isEmpty())
            AbnormalForm->setObjectName(QString::fromUtf8("AbnormalForm"));
        AbnormalForm->resize(400, 300);
        groupBox = new QGroupBox(AbnormalForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(100, 170, 120, 80));

        retranslateUi(AbnormalForm);

        QMetaObject::connectSlotsByName(AbnormalForm);
    } // setupUi

    void retranslateUi(QWidget *AbnormalForm)
    {
        AbnormalForm->setWindowTitle(QApplication::translate("AbnormalForm", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("AbnormalForm", "GroupBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AbnormalForm: public Ui_AbnormalForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABNORMALFORM_H
