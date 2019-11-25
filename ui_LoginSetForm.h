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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "ComboBoxEx.h"
#include "LabelEx.h"
#include "LineEditEx.h"
#include "PushButtonEx.h"

QT_BEGIN_NAMESPACE

class Ui_LoginSetForm
{
public:
    PushButtonEx *pushButtonCancel;
    PushButtonEx *pushButtonOk;
    QPushButton *pushButtonTitle;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    LineEditEx *lineEditLoginName;
    LineEditEx *lineEditLoginPwd;
    LineEditEx *lineEditDbName;
    QLabel *label_2;
    LineEditEx *lineEditSerName;
    QLabel *label_4;
    QToolButton *toolButtonEye;
    QLabel *label_3;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    LineEditEx *lineEditNetIP;
    LineEditEx *lineEditNetPort;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_8;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    LabelEx *label_9;
    ComboBoxEx *comboBoxComName;
    QSpacerItem *horizontalSpacer_6;
    LabelEx *label_10;
    LineEditEx *lineEditComNum;
    LabelEx *label_11;
    ComboBoxEx *comboBoxComBaud;
    QSpacerItem *horizontalSpacer_7;
    LabelEx *label_12;
    LabelEx *labelComDetails;

    void setupUi(QWidget *LoginSetForm)
    {
        if (LoginSetForm->objectName().isEmpty())
            LoginSetForm->setObjectName(QString::fromUtf8("LoginSetForm"));
        LoginSetForm->resize(620, 526);
        LoginSetForm->setLayoutDirection(Qt::LeftToRight);
        pushButtonCancel = new PushButtonEx(LoginSetForm);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(160, 480, 81, 31));
        pushButtonOk = new PushButtonEx(LoginSetForm);
        pushButtonOk->setObjectName(QString::fromUtf8("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(350, 480, 81, 31));
        pushButtonTitle = new QPushButton(LoginSetForm);
        pushButtonTitle->setObjectName(QString::fromUtf8("pushButtonTitle"));
        pushButtonTitle->setGeometry(QRect(0, 0, 621, 51));
        pushButtonTitle->setAcceptDrops(true);
        groupBox = new QGroupBox(LoginSetForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 70, 601, 130));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 20, -1, -1);
        lineEditLoginName = new LineEditEx(groupBox);
        lineEditLoginName->setObjectName(QString::fromUtf8("lineEditLoginName"));
        lineEditLoginName->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEditLoginName, 1, 1, 1, 1);

        lineEditLoginPwd = new LineEditEx(groupBox);
        lineEditLoginPwd->setObjectName(QString::fromUtf8("lineEditLoginPwd"));
        lineEditLoginPwd->setMinimumSize(QSize(0, 30));
        lineEditLoginPwd->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEditLoginPwd, 1, 4, 1, 1);

        lineEditDbName = new LineEditEx(groupBox);
        lineEditDbName->setObjectName(QString::fromUtf8("lineEditDbName"));
        lineEditDbName->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEditDbName, 0, 4, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEditSerName = new LineEditEx(groupBox);
        lineEditSerName->setObjectName(QString::fromUtf8("lineEditSerName"));
        lineEditSerName->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEditSerName, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        toolButtonEye = new QToolButton(groupBox);
        toolButtonEye->setObjectName(QString::fromUtf8("toolButtonEye"));
        toolButtonEye->setCheckable(true);
        toolButtonEye->setChecked(false);

        gridLayout->addWidget(toolButtonEye, 1, 5, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        groupBox_2 = new QGroupBox(LoginSetForm);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 220, 600, 90));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 20, -1, -1);
        lineEditNetIP = new LineEditEx(groupBox_2);
        lineEditNetIP->setObjectName(QString::fromUtf8("lineEditNetIP"));
        lineEditNetIP->setMinimumSize(QSize(0, 30));
        lineEditNetIP->setMaximumSize(QSize(180, 16777215));

        gridLayout_2->addWidget(lineEditNetIP, 0, 1, 1, 1);

        lineEditNetPort = new LineEditEx(groupBox_2);
        lineEditNetPort->setObjectName(QString::fromUtf8("lineEditNetPort"));
        lineEditNetPort->setMinimumSize(QSize(0, 30));
        lineEditNetPort->setMaximumSize(QSize(180, 16777215));

        gridLayout_2->addWidget(lineEditNetPort, 0, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(label_8, 0, 3, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(65, 16777215));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 5, 1, 1);

        groupBox_3 = new QGroupBox(LoginSetForm);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 330, 601, 130));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(-1, 20, -1, -1);
        label_9 = new LabelEx(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setMinimumSize(QSize(65, 0));

        gridLayout_3->addWidget(label_9, 0, 0, 1, 1);

        comboBoxComName = new ComboBoxEx(groupBox_3);
        comboBoxComName->setObjectName(QString::fromUtf8("comboBoxComName"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBoxComName->sizePolicy().hasHeightForWidth());
        comboBoxComName->setSizePolicy(sizePolicy1);
        comboBoxComName->setMinimumSize(QSize(150, 30));
        comboBoxComName->setMaximumSize(QSize(120, 16777215));

        gridLayout_3->addWidget(comboBoxComName, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 0, 2, 1, 1);

        label_10 = new LabelEx(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label_10, 0, 3, 1, 1);

        lineEditComNum = new LineEditEx(groupBox_3);
        lineEditComNum->setObjectName(QString::fromUtf8("lineEditComNum"));
        lineEditComNum->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEditComNum->sizePolicy().hasHeightForWidth());
        lineEditComNum->setSizePolicy(sizePolicy1);
        lineEditComNum->setMinimumSize(QSize(250, 30));
        lineEditComNum->setMaximumSize(QSize(120, 16777215));

        gridLayout_3->addWidget(lineEditComNum, 0, 4, 1, 1);

        label_11 = new LabelEx(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label_11, 1, 0, 1, 1);

        comboBoxComBaud = new ComboBoxEx(groupBox_3);
        comboBoxComBaud->setObjectName(QString::fromUtf8("comboBoxComBaud"));
        sizePolicy1.setHeightForWidth(comboBoxComBaud->sizePolicy().hasHeightForWidth());
        comboBoxComBaud->setSizePolicy(sizePolicy1);
        comboBoxComBaud->setMinimumSize(QSize(150, 30));
        comboBoxComBaud->setMaximumSize(QSize(120, 16777215));

        gridLayout_3->addWidget(comboBoxComBaud, 1, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_7, 1, 2, 1, 1);

        label_12 = new LabelEx(groupBox_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label_12, 1, 3, 1, 1);

        labelComDetails = new LabelEx(groupBox_3);
        labelComDetails->setObjectName(QString::fromUtf8("labelComDetails"));
        sizePolicy1.setHeightForWidth(labelComDetails->sizePolicy().hasHeightForWidth());
        labelComDetails->setSizePolicy(sizePolicy1);
        labelComDetails->setMinimumSize(QSize(250, 0));

        gridLayout_3->addWidget(labelComDetails, 1, 4, 1, 2);

        QWidget::setTabOrder(lineEditSerName, lineEditDbName);
        QWidget::setTabOrder(lineEditDbName, lineEditLoginName);
        QWidget::setTabOrder(lineEditLoginName, lineEditLoginPwd);
        QWidget::setTabOrder(lineEditLoginPwd, toolButtonEye);
        QWidget::setTabOrder(toolButtonEye, lineEditNetIP);
        QWidget::setTabOrder(lineEditNetIP, lineEditNetPort);
        QWidget::setTabOrder(lineEditNetPort, comboBoxComName);
        QWidget::setTabOrder(comboBoxComName, lineEditComNum);
        QWidget::setTabOrder(lineEditComNum, pushButtonCancel);
        QWidget::setTabOrder(pushButtonCancel, pushButtonOk);
        QWidget::setTabOrder(pushButtonOk, pushButtonTitle);

        retranslateUi(LoginSetForm);

        QMetaObject::connectSlotsByName(LoginSetForm);
    } // setupUi

    void retranslateUi(QWidget *LoginSetForm)
    {
        LoginSetForm->setWindowTitle(QApplication::translate("LoginSetForm", "Form", nullptr));
        pushButtonCancel->setText(QApplication::translate("LoginSetForm", "\345\217\226\346\266\210", nullptr));
        pushButtonOk->setText(QApplication::translate("LoginSetForm", "\347\241\256\345\256\232", nullptr));
        pushButtonTitle->setText(QApplication::translate("LoginSetForm", "PushButton", nullptr));
        groupBox->setTitle(QApplication::translate("LoginSetForm", "\346\225\260\346\215\256\345\272\223\346\234\215\345\212\241\345\231\250\345\217\202\346\225\260", nullptr));
        label_2->setText(QApplication::translate("LoginSetForm", "\346\234\215\345\212\241\345\231\250\345\220\215\347\247\260\357\274\232", nullptr));
        label_4->setText(QApplication::translate("LoginSetForm", "\347\231\273\345\275\225\345\220\215\357\274\232", nullptr));
        toolButtonEye->setText(QString());
        label_3->setText(QApplication::translate("LoginSetForm", "\346\225\260\346\215\256\345\272\223\345\220\215\357\274\232", nullptr));
        label_5->setText(QApplication::translate("LoginSetForm", "\345\257\206\347\240\201\357\274\232", nullptr));
        groupBox_2->setTitle(QApplication::translate("LoginSetForm", "\347\275\221\347\273\234\346\234\215\345\212\241\345\231\250\345\217\202\346\225\260", nullptr));
        label_8->setText(QApplication::translate("LoginSetForm", "\347\253\257\345\217\243\357\274\232 ", nullptr));
        label_6->setText(QApplication::translate("LoginSetForm", "IP\357\274\232            ", nullptr));
        groupBox_3->setTitle(QApplication::translate("LoginSetForm", "\344\270\262\345\217\243\345\217\202\346\225\260", nullptr));
        label_9->setText(QApplication::translate("LoginSetForm", "\344\270\262\345\217\243\345\220\215\357\274\232  ", nullptr));
        label_10->setText(QApplication::translate("LoginSetForm", " \345\272\217\345\210\227\345\217\267\357\274\232 ", nullptr));
        label_11->setText(QApplication::translate("LoginSetForm", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        label_12->setText(QApplication::translate("LoginSetForm", " \346\217\217\350\277\260\357\274\232", nullptr));
        labelComDetails->setText(QApplication::translate("LoginSetForm", "\344\270\262\345\217\243\346\217\217\350\277\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginSetForm: public Ui_LoginSetForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINSETFORM_H
