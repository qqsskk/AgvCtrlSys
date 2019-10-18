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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "ComboBoxEx.h"
#include "GroupBoxEx.h"
#include "LabelEx.h"
#include "LineEditEx.h"
#include "PushButtonEx.h"
#include "TableViewEx.h"

QT_BEGIN_NAMESPACE

class Ui_UserForm
{
public:
    QGridLayout *gridLayout_3;
    GroupBoxEx *groupBoxPasswdChange;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_6;
    LineEditEx *lineEditPwdMakesure;
    LineEditEx *lineEditPwdOld;
    LabelEx *label_11;
    LabelEx *label_12;
    LineEditEx *lineEditPwdNew;
    LabelEx *label_13;
    PushButtonEx *pushButtonChangePwdCancel;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    PushButtonEx *pushButtonChangePwdOk;
    QSpacerItem *verticalSpacer;
    GroupBoxEx *groupBox;
    QGridLayout *gridLayout;
    PushButtonEx *pushButtonLogoutUser;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_10;
    LabelEx *label_8;
    LabelEx *labelUserName;
    LabelEx *labelLevel;
    LabelEx *label_10;
    QSpacerItem *horizontalSpacer_3;
    PushButtonEx *pushButtonChangePasswd;
    QSpacerItem *horizontalSpacer_11;
    GroupBoxEx *groupBoxUserChange;
    QGridLayout *gridLayout_4;
    LabelEx *label_14;
    QSpacerItem *horizontalSpacer_7;
    TableViewEx *tableViewUserInfo;
    LineEditEx *lineEditUserName;
    LineEditEx *lineEditUserPasswd;
    QSpacerItem *horizontalSpacer_8;
    LabelEx *label_15;
    ComboBoxEx *comboBoxLevel;
    PushButtonEx *pushButtonUserAdd;
    PushButtonEx *pushButtonUserChange;
    LabelEx *label_16;
    PushButtonEx *pushButtonUserDel;
    QSpacerItem *horizontalSpacer_9;

    void setupUi(QWidget *UserForm)
    {
        if (UserForm->objectName().isEmpty())
            UserForm->setObjectName(QString::fromUtf8("UserForm"));
        UserForm->resize(1060, 639);
        gridLayout_3 = new QGridLayout(UserForm);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBoxPasswdChange = new GroupBoxEx(UserForm);
        groupBoxPasswdChange->setObjectName(QString::fromUtf8("groupBoxPasswdChange"));
        groupBoxPasswdChange->setMinimumSize(QSize(0, 150));
        gridLayout_2 = new QGridLayout(groupBoxPasswdChange);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(20, 50, 20, -1);
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 0, 8, 1, 1);

        lineEditPwdMakesure = new LineEditEx(groupBoxPasswdChange);
        lineEditPwdMakesure->setObjectName(QString::fromUtf8("lineEditPwdMakesure"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditPwdMakesure->sizePolicy().hasHeightForWidth());
        lineEditPwdMakesure->setSizePolicy(sizePolicy);
        lineEditPwdMakesure->setMinimumSize(QSize(150, 30));
        lineEditPwdMakesure->setEchoMode(QLineEdit::Password);
        lineEditPwdMakesure->setReadOnly(false);

        gridLayout_2->addWidget(lineEditPwdMakesure, 0, 7, 1, 1);

        lineEditPwdOld = new LineEditEx(groupBoxPasswdChange);
        lineEditPwdOld->setObjectName(QString::fromUtf8("lineEditPwdOld"));
        sizePolicy.setHeightForWidth(lineEditPwdOld->sizePolicy().hasHeightForWidth());
        lineEditPwdOld->setSizePolicy(sizePolicy);
        lineEditPwdOld->setMinimumSize(QSize(150, 30));
        lineEditPwdOld->setEchoMode(QLineEdit::Password);
        lineEditPwdOld->setReadOnly(false);

        gridLayout_2->addWidget(lineEditPwdOld, 0, 1, 1, 1);

        label_11 = new LabelEx(groupBoxPasswdChange);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setMinimumSize(QSize(60, 0));
        label_11->setMaximumSize(QSize(60, 16777215));

        gridLayout_2->addWidget(label_11, 0, 0, 1, 1);

        label_12 = new LabelEx(groupBoxPasswdChange);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_12->setMinimumSize(QSize(60, 0));
        label_12->setMaximumSize(QSize(60, 16777215));

        gridLayout_2->addWidget(label_12, 0, 3, 1, 1);

        lineEditPwdNew = new LineEditEx(groupBoxPasswdChange);
        lineEditPwdNew->setObjectName(QString::fromUtf8("lineEditPwdNew"));
        sizePolicy.setHeightForWidth(lineEditPwdNew->sizePolicy().hasHeightForWidth());
        lineEditPwdNew->setSizePolicy(sizePolicy);
        lineEditPwdNew->setMinimumSize(QSize(150, 30));
        lineEditPwdNew->setEchoMode(QLineEdit::Password);
        lineEditPwdNew->setReadOnly(false);

        gridLayout_2->addWidget(lineEditPwdNew, 0, 4, 1, 1);

        label_13 = new LabelEx(groupBoxPasswdChange);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);
        label_13->setMinimumSize(QSize(60, 0));
        label_13->setMaximumSize(QSize(60, 16777215));

        gridLayout_2->addWidget(label_13, 0, 6, 1, 1);

        pushButtonChangePwdCancel = new PushButtonEx(groupBoxPasswdChange);
        pushButtonChangePwdCancel->setObjectName(QString::fromUtf8("pushButtonChangePwdCancel"));
        sizePolicy.setHeightForWidth(pushButtonChangePwdCancel->sizePolicy().hasHeightForWidth());
        pushButtonChangePwdCancel->setSizePolicy(sizePolicy);
        pushButtonChangePwdCancel->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(pushButtonChangePwdCancel, 0, 9, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 0, 5, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        pushButtonChangePwdOk = new PushButtonEx(groupBoxPasswdChange);
        pushButtonChangePwdOk->setObjectName(QString::fromUtf8("pushButtonChangePwdOk"));
        sizePolicy.setHeightForWidth(pushButtonChangePwdOk->sizePolicy().hasHeightForWidth());
        pushButtonChangePwdOk->setSizePolicy(sizePolicy);
        pushButtonChangePwdOk->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(pushButtonChangePwdOk, 0, 10, 1, 1);


        gridLayout_3->addWidget(groupBoxPasswdChange, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 3, 0, 1, 1);

        groupBox = new GroupBoxEx(UserForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 150));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(20, 50, 20, -1);
        pushButtonLogoutUser = new PushButtonEx(groupBox);
        pushButtonLogoutUser->setObjectName(QString::fromUtf8("pushButtonLogoutUser"));
        sizePolicy.setHeightForWidth(pushButtonLogoutUser->sizePolicy().hasHeightForWidth());
        pushButtonLogoutUser->setSizePolicy(sizePolicy);
        pushButtonLogoutUser->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(pushButtonLogoutUser, 0, 10, 1, 1);

        horizontalSpacer = new QSpacerItem(61, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 7, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 0, 8, 1, 1);

        label_8 = new LabelEx(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        labelUserName = new LabelEx(groupBox);
        labelUserName->setObjectName(QString::fromUtf8("labelUserName"));
        labelUserName->setEnabled(false);
        sizePolicy.setHeightForWidth(labelUserName->sizePolicy().hasHeightForWidth());
        labelUserName->setSizePolicy(sizePolicy);
        labelUserName->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(labelUserName, 0, 1, 1, 1);

        labelLevel = new LabelEx(groupBox);
        labelLevel->setObjectName(QString::fromUtf8("labelLevel"));
        labelLevel->setEnabled(false);
        sizePolicy.setHeightForWidth(labelLevel->sizePolicy().hasHeightForWidth());
        labelLevel->setSizePolicy(sizePolicy);
        labelLevel->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(labelLevel, 0, 4, 1, 1);

        label_10 = new LabelEx(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_10, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 6, 1, 1);

        pushButtonChangePasswd = new PushButtonEx(groupBox);
        pushButtonChangePasswd->setObjectName(QString::fromUtf8("pushButtonChangePasswd"));
        sizePolicy.setHeightForWidth(pushButtonChangePasswd->sizePolicy().hasHeightForWidth());
        pushButtonChangePasswd->setSizePolicy(sizePolicy);
        pushButtonChangePasswd->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(pushButtonChangePasswd, 0, 9, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 0, 5, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBoxUserChange = new GroupBoxEx(UserForm);
        groupBoxUserChange->setObjectName(QString::fromUtf8("groupBoxUserChange"));
        groupBoxUserChange->setMinimumSize(QSize(0, 300));
        gridLayout_4 = new QGridLayout(groupBoxUserChange);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setVerticalSpacing(15);
        gridLayout_4->setContentsMargins(20, 40, 20, 20);
        label_14 = new LabelEx(groupBoxUserChange);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);
        label_14->setMinimumSize(QSize(0, 0));
        label_14->setMaximumSize(QSize(60, 16777215));

        gridLayout_4->addWidget(label_14, 1, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_7, 1, 2, 1, 1);

        tableViewUserInfo = new TableViewEx(groupBoxUserChange);
        tableViewUserInfo->setObjectName(QString::fromUtf8("tableViewUserInfo"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableViewUserInfo->sizePolicy().hasHeightForWidth());
        tableViewUserInfo->setSizePolicy(sizePolicy2);
        tableViewUserInfo->setMinimumSize(QSize(930, 0));

        gridLayout_4->addWidget(tableViewUserInfo, 0, 0, 1, 14);

        lineEditUserName = new LineEditEx(groupBoxUserChange);
        lineEditUserName->setObjectName(QString::fromUtf8("lineEditUserName"));
        sizePolicy.setHeightForWidth(lineEditUserName->sizePolicy().hasHeightForWidth());
        lineEditUserName->setSizePolicy(sizePolicy);
        lineEditUserName->setMinimumSize(QSize(150, 30));
        lineEditUserName->setReadOnly(false);

        gridLayout_4->addWidget(lineEditUserName, 1, 1, 1, 1);

        lineEditUserPasswd = new LineEditEx(groupBoxUserChange);
        lineEditUserPasswd->setObjectName(QString::fromUtf8("lineEditUserPasswd"));
        sizePolicy.setHeightForWidth(lineEditUserPasswd->sizePolicy().hasHeightForWidth());
        lineEditUserPasswd->setSizePolicy(sizePolicy);
        lineEditUserPasswd->setMinimumSize(QSize(150, 30));
        lineEditUserPasswd->setReadOnly(false);

        gridLayout_4->addWidget(lineEditUserPasswd, 1, 4, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_8, 1, 5, 1, 1);

        label_15 = new LabelEx(groupBoxUserChange);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);
        label_15->setMaximumSize(QSize(60, 16777215));

        gridLayout_4->addWidget(label_15, 1, 3, 1, 1);

        comboBoxLevel = new ComboBoxEx(groupBoxUserChange);
        comboBoxLevel->setObjectName(QString::fromUtf8("comboBoxLevel"));
        comboBoxLevel->setMinimumSize(QSize(150, 30));

        gridLayout_4->addWidget(comboBoxLevel, 1, 7, 1, 1);

        pushButtonUserAdd = new PushButtonEx(groupBoxUserChange);
        pushButtonUserAdd->setObjectName(QString::fromUtf8("pushButtonUserAdd"));
        sizePolicy.setHeightForWidth(pushButtonUserAdd->sizePolicy().hasHeightForWidth());
        pushButtonUserAdd->setSizePolicy(sizePolicy);
        pushButtonUserAdd->setMinimumSize(QSize(0, 30));

        gridLayout_4->addWidget(pushButtonUserAdd, 1, 9, 1, 1);

        pushButtonUserChange = new PushButtonEx(groupBoxUserChange);
        pushButtonUserChange->setObjectName(QString::fromUtf8("pushButtonUserChange"));
        sizePolicy.setHeightForWidth(pushButtonUserChange->sizePolicy().hasHeightForWidth());
        pushButtonUserChange->setSizePolicy(sizePolicy);
        pushButtonUserChange->setMinimumSize(QSize(0, 30));

        gridLayout_4->addWidget(pushButtonUserChange, 1, 11, 1, 1);

        label_16 = new LabelEx(groupBoxUserChange);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy1.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy1);
        label_16->setMaximumSize(QSize(60, 16777215));

        gridLayout_4->addWidget(label_16, 1, 6, 1, 1);

        pushButtonUserDel = new PushButtonEx(groupBoxUserChange);
        pushButtonUserDel->setObjectName(QString::fromUtf8("pushButtonUserDel"));
        sizePolicy.setHeightForWidth(pushButtonUserDel->sizePolicy().hasHeightForWidth());
        pushButtonUserDel->setSizePolicy(sizePolicy);
        pushButtonUserDel->setMinimumSize(QSize(0, 30));

        gridLayout_4->addWidget(pushButtonUserDel, 1, 13, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_9, 1, 8, 1, 1);


        gridLayout_3->addWidget(groupBoxUserChange, 2, 0, 1, 1);


        retranslateUi(UserForm);

        QMetaObject::connectSlotsByName(UserForm);
    } // setupUi

    void retranslateUi(QWidget *UserForm)
    {
        UserForm->setWindowTitle(QApplication::translate("UserForm", "Form", nullptr));
        groupBoxPasswdChange->setTitle(QApplication::translate("UserForm", "GroupBox", nullptr));
        label_11->setText(QApplication::translate("UserForm", "\346\227\247\345\257\206\347\240\201\357\274\232", nullptr));
        label_12->setText(QApplication::translate("UserForm", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        label_13->setText(QApplication::translate("UserForm", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        pushButtonChangePwdCancel->setText(QApplication::translate("UserForm", "\345\217\226\346\266\210", nullptr));
        pushButtonChangePwdOk->setText(QApplication::translate("UserForm", "\347\241\256\350\256\244", nullptr));
        groupBox->setTitle(QApplication::translate("UserForm", "GroupBox", nullptr));
        pushButtonLogoutUser->setText(QApplication::translate("UserForm", "\346\263\250\351\224\200\347\224\250\346\210\267", nullptr));
        label_8->setText(QApplication::translate("UserForm", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        labelUserName->setText(QString());
        labelLevel->setText(QString());
        label_10->setText(QApplication::translate("UserForm", "\346\235\203   \351\231\220\357\274\232", nullptr));
        pushButtonChangePasswd->setText(QApplication::translate("UserForm", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        groupBoxUserChange->setTitle(QApplication::translate("UserForm", "GroupBox", nullptr));
        label_14->setText(QApplication::translate("UserForm", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_15->setText(QApplication::translate("UserForm", "\345\257\206   \347\240\201\357\274\232", nullptr));
        pushButtonUserAdd->setText(QApplication::translate("UserForm", "\346\267\273\345\212\240", nullptr));
        pushButtonUserChange->setText(QApplication::translate("UserForm", "\344\277\256\346\224\271", nullptr));
        label_16->setText(QApplication::translate("UserForm", "\346\235\203     \351\231\220\357\274\232", nullptr));
        pushButtonUserDel->setText(QApplication::translate("UserForm", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserForm: public Ui_UserForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERFORM_H
