/********************************************************************************
** Form generated from reading UI file 'ConfigForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGFORM_H
#define UI_CONFIGFORM_H

#include <GroupBoxEx.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "ComboBoxEx.h"
#include "LabelEx.h"
#include "LineEditEx.h"
#include "PushButtonEx.h"

QT_BEGIN_NAMESPACE

class Ui_ConfigForm
{
public:
    QGridLayout *gridLayout;
    GroupBoxEx *groupBox_3;
    QGridLayout *gridLayout_3;
    LabelEx *label_22;
    LineEditEx *lineEditSerName_18;
    QSpacerItem *horizontalSpacer_5;
    LabelEx *label_14;
    PushButtonEx *pushButton_6;
    LabelEx *label_15;
    LineEditEx *lineEditSerName_6;
    QSpacerItem *horizontalSpacer_6;
    LineEditEx *lineEditSerName_19;
    LineEditEx *lineEditSerName_20;
    LabelEx *label_23;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    GroupBoxEx *groupBox;
    QGridLayout *gridLayout_2;
    LabelEx *label_21;
    LineEditEx *lineEditDbName;
    QSpacerItem *horizontalSpacer_3;
    LabelEx *label_13;
    PushButtonEx *pushButtonSetDb;
    LabelEx *label_8;
    LineEditEx *lineEditSerName;
    QSpacerItem *horizontalSpacer;
    LineEditEx *lineEditPasswd;
    LineEditEx *lineEditLoginName;
    LabelEx *label_20;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    GroupBoxEx *groupBox_2;
    QGridLayout *gridLayout_4;
    LabelEx *label_17;
    QSpacerItem *horizontalSpacer_20;
    QSpacerItem *horizontalSpacer_19;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *horizontalSpacer_18;
    LineEditEx *lineEditNetSerIP;
    PushButtonEx *pushButtonSetNet;
    LabelEx *label_16;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *horizontalSpacer_14;
    LabelEx *label_7;
    QSpacerItem *horizontalSpacer_23;
    LabelEx *labelNetState;
    LineEditEx *lineEditNetSerPort;
    QSpacerItem *horizontalSpacer_21;
    QSpacerItem *horizontalSpacer_22;
    QSpacerItem *horizontalSpacer_9;
    GroupBoxEx *groupBox_4;
    QGridLayout *gridLayout_5;
    PushButtonEx *pushButtonRefresh;
    LabelEx *label_25;
    PushButtonEx *pushButtonSetCom;
    LabelEx *labelComState;
    LineEditEx *lineEditComNumber;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_12;
    LabelEx *label_18;
    LabelEx *label_19;
    ComboBoxEx *comboBoxComName;
    QSpacerItem *horizontalSpacer_11;
    ComboBoxEx *comboBoxBaud;
    LabelEx *label_24;

    void setupUi(QWidget *ConfigForm)
    {
        if (ConfigForm->objectName().isEmpty())
            ConfigForm->setObjectName(QString::fromUtf8("ConfigForm"));
        ConfigForm->resize(1060, 662);
        gridLayout = new QGridLayout(ConfigForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_3 = new GroupBoxEx(ConfigForm);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox_3->setCheckable(false);
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(-1, 30, -1, 0);
        label_22 = new LabelEx(groupBox_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_22, 0, 9, 1, 1);

        lineEditSerName_18 = new LineEditEx(groupBox_3);
        lineEditSerName_18->setObjectName(QString::fromUtf8("lineEditSerName_18"));
        sizePolicy1.setHeightForWidth(lineEditSerName_18->sizePolicy().hasHeightForWidth());
        lineEditSerName_18->setSizePolicy(sizePolicy1);
        lineEditSerName_18->setMinimumSize(QSize(0, 30));

        gridLayout_3->addWidget(lineEditSerName_18, 0, 4, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 0, 8, 1, 1);

        label_14 = new LabelEx(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_14, 0, 3, 1, 1);

        pushButton_6 = new PushButtonEx(groupBox_3);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        pushButton_6->setMinimumSize(QSize(80, 30));

        gridLayout_3->addWidget(pushButton_6, 0, 12, 1, 1);

        label_15 = new LabelEx(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_15, 0, 0, 1, 1);

        lineEditSerName_6 = new LineEditEx(groupBox_3);
        lineEditSerName_6->setObjectName(QString::fromUtf8("lineEditSerName_6"));
        sizePolicy1.setHeightForWidth(lineEditSerName_6->sizePolicy().hasHeightForWidth());
        lineEditSerName_6->setSizePolicy(sizePolicy1);
        lineEditSerName_6->setMinimumSize(QSize(0, 30));

        gridLayout_3->addWidget(lineEditSerName_6, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 0, 2, 1, 1);

        lineEditSerName_19 = new LineEditEx(groupBox_3);
        lineEditSerName_19->setObjectName(QString::fromUtf8("lineEditSerName_19"));
        sizePolicy1.setHeightForWidth(lineEditSerName_19->sizePolicy().hasHeightForWidth());
        lineEditSerName_19->setSizePolicy(sizePolicy1);
        lineEditSerName_19->setMinimumSize(QSize(0, 30));

        gridLayout_3->addWidget(lineEditSerName_19, 0, 10, 1, 1);

        lineEditSerName_20 = new LineEditEx(groupBox_3);
        lineEditSerName_20->setObjectName(QString::fromUtf8("lineEditSerName_20"));
        sizePolicy1.setHeightForWidth(lineEditSerName_20->sizePolicy().hasHeightForWidth());
        lineEditSerName_20->setSizePolicy(sizePolicy1);
        lineEditSerName_20->setMinimumSize(QSize(0, 30));

        gridLayout_3->addWidget(lineEditSerName_20, 0, 7, 1, 1);

        label_23 = new LabelEx(groupBox_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        sizePolicy1.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_23, 0, 6, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_7, 0, 5, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_8, 0, 11, 1, 1);


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox = new GroupBoxEx(ConfigForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox->setCheckable(false);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 30, -1, 0);
        label_21 = new LabelEx(groupBox);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        sizePolicy1.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_21, 0, 9, 1, 1);

        lineEditDbName = new LineEditEx(groupBox);
        lineEditDbName->setObjectName(QString::fromUtf8("lineEditDbName"));
        sizePolicy1.setHeightForWidth(lineEditDbName->sizePolicy().hasHeightForWidth());
        lineEditDbName->setSizePolicy(sizePolicy1);
        lineEditDbName->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(lineEditDbName, 0, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 8, 1, 1);

        label_13 = new LabelEx(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_13, 0, 3, 1, 1);

        pushButtonSetDb = new PushButtonEx(groupBox);
        pushButtonSetDb->setObjectName(QString::fromUtf8("pushButtonSetDb"));
        sizePolicy1.setHeightForWidth(pushButtonSetDb->sizePolicy().hasHeightForWidth());
        pushButtonSetDb->setSizePolicy(sizePolicy1);
        pushButtonSetDb->setMinimumSize(QSize(80, 30));

        gridLayout_2->addWidget(pushButtonSetDb, 0, 12, 1, 1);

        label_8 = new LabelEx(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_8, 0, 0, 1, 1);

        lineEditSerName = new LineEditEx(groupBox);
        lineEditSerName->setObjectName(QString::fromUtf8("lineEditSerName"));
        sizePolicy1.setHeightForWidth(lineEditSerName->sizePolicy().hasHeightForWidth());
        lineEditSerName->setSizePolicy(sizePolicy1);
        lineEditSerName->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(lineEditSerName, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

        lineEditPasswd = new LineEditEx(groupBox);
        lineEditPasswd->setObjectName(QString::fromUtf8("lineEditPasswd"));
        sizePolicy1.setHeightForWidth(lineEditPasswd->sizePolicy().hasHeightForWidth());
        lineEditPasswd->setSizePolicy(sizePolicy1);
        lineEditPasswd->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(lineEditPasswd, 0, 10, 1, 1);

        lineEditLoginName = new LineEditEx(groupBox);
        lineEditLoginName->setObjectName(QString::fromUtf8("lineEditLoginName"));
        sizePolicy1.setHeightForWidth(lineEditLoginName->sizePolicy().hasHeightForWidth());
        lineEditLoginName->setSizePolicy(sizePolicy1);
        lineEditLoginName->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(lineEditLoginName, 0, 7, 1, 1);

        label_20 = new LabelEx(groupBox);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        sizePolicy1.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_20, 0, 6, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 5, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 11, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        groupBox_2 = new GroupBoxEx(ConfigForm);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox_2->setCheckable(false);
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(-1, 50, -1, 0);
        label_17 = new LabelEx(groupBox_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy1.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(label_17, 1, 0, 1, 1);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_20, 0, 9, 1, 1);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_19, 0, 13, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_15, 0, 11, 1, 1);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_18, 0, 14, 1, 1);

        lineEditNetSerIP = new LineEditEx(groupBox_2);
        lineEditNetSerIP->setObjectName(QString::fromUtf8("lineEditNetSerIP"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEditNetSerIP->sizePolicy().hasHeightForWidth());
        lineEditNetSerIP->setSizePolicy(sizePolicy2);
        lineEditNetSerIP->setMinimumSize(QSize(0, 30));

        gridLayout_4->addWidget(lineEditNetSerIP, 0, 1, 1, 1);

        pushButtonSetNet = new PushButtonEx(groupBox_2);
        pushButtonSetNet->setObjectName(QString::fromUtf8("pushButtonSetNet"));
        sizePolicy1.setHeightForWidth(pushButtonSetNet->sizePolicy().hasHeightForWidth());
        pushButtonSetNet->setSizePolicy(sizePolicy1);
        pushButtonSetNet->setMinimumSize(QSize(80, 30));

        gridLayout_4->addWidget(pushButtonSetNet, 0, 15, 1, 1);

        label_16 = new LabelEx(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy1.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy1);
        label_16->setMaximumSize(QSize(50, 16777215));

        gridLayout_4->addWidget(label_16, 0, 0, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_16, 0, 12, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_14, 0, 7, 1, 1);

        label_7 = new LabelEx(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_4->addWidget(label_7, 0, 3, 1, 1);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_23, 0, 6, 1, 1);

        labelNetState = new LabelEx(groupBox_2);
        labelNetState->setObjectName(QString::fromUtf8("labelNetState"));
        sizePolicy2.setHeightForWidth(labelNetState->sizePolicy().hasHeightForWidth());
        labelNetState->setSizePolicy(sizePolicy2);
        labelNetState->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelNetState, 1, 1, 1, 1);

        lineEditNetSerPort = new LineEditEx(groupBox_2);
        lineEditNetSerPort->setObjectName(QString::fromUtf8("lineEditNetSerPort"));
        sizePolicy1.setHeightForWidth(lineEditNetSerPort->sizePolicy().hasHeightForWidth());
        lineEditNetSerPort->setSizePolicy(sizePolicy1);
        lineEditNetSerPort->setMinimumSize(QSize(0, 30));

        gridLayout_4->addWidget(lineEditNetSerPort, 0, 5, 1, 1);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_21, 0, 8, 1, 1);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_22, 0, 2, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_9, 0, 10, 1, 1);


        gridLayout->addWidget(groupBox_2, 2, 0, 1, 1);

        groupBox_4 = new GroupBoxEx(ConfigForm);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        groupBox_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox_4->setCheckable(false);
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(-1, 50, -1, 0);
        pushButtonRefresh = new PushButtonEx(groupBox_4);
        pushButtonRefresh->setObjectName(QString::fromUtf8("pushButtonRefresh"));
        sizePolicy1.setHeightForWidth(pushButtonRefresh->sizePolicy().hasHeightForWidth());
        pushButtonRefresh->setSizePolicy(sizePolicy1);
        pushButtonRefresh->setMinimumSize(QSize(80, 30));
        pushButtonRefresh->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_5->addWidget(pushButtonRefresh, 0, 9, 1, 1);

        label_25 = new LabelEx(groupBox_4);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(label_25, 0, 3, 1, 1);

        pushButtonSetCom = new PushButtonEx(groupBox_4);
        pushButtonSetCom->setObjectName(QString::fromUtf8("pushButtonSetCom"));
        sizePolicy1.setHeightForWidth(pushButtonSetCom->sizePolicy().hasHeightForWidth());
        pushButtonSetCom->setSizePolicy(sizePolicy1);
        pushButtonSetCom->setMinimumSize(QSize(80, 30));
        pushButtonSetCom->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_5->addWidget(pushButtonSetCom, 0, 12, 1, 1);

        labelComState = new LabelEx(groupBox_4);
        labelComState->setObjectName(QString::fromUtf8("labelComState"));
        sizePolicy2.setHeightForWidth(labelComState->sizePolicy().hasHeightForWidth());
        labelComState->setSizePolicy(sizePolicy2);
        labelComState->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(labelComState, 2, 1, 1, 1);

        lineEditComNumber = new LineEditEx(groupBox_4);
        lineEditComNumber->setObjectName(QString::fromUtf8("lineEditComNumber"));
        lineEditComNumber->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEditComNumber->sizePolicy().hasHeightForWidth());
        lineEditComNumber->setSizePolicy(sizePolicy1);
        lineEditComNumber->setMinimumSize(QSize(0, 30));
        lineEditComNumber->setMaximumSize(QSize(120, 16777215));

        gridLayout_5->addWidget(lineEditComNumber, 0, 4, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_13, 0, 10, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_10, 0, 8, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_12, 0, 2, 1, 1);

        label_18 = new LabelEx(groupBox_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        sizePolicy3.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(label_18, 0, 6, 1, 1);

        label_19 = new LabelEx(groupBox_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        sizePolicy3.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(label_19, 0, 0, 1, 1);

        comboBoxComName = new ComboBoxEx(groupBox_4);
        comboBoxComName->setObjectName(QString::fromUtf8("comboBoxComName"));
        sizePolicy1.setHeightForWidth(comboBoxComName->sizePolicy().hasHeightForWidth());
        comboBoxComName->setSizePolicy(sizePolicy1);
        comboBoxComName->setMinimumSize(QSize(0, 30));
        comboBoxComName->setMaximumSize(QSize(120, 16777215));

        gridLayout_5->addWidget(comboBoxComName, 0, 1, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_11, 0, 5, 1, 1);

        comboBoxBaud = new ComboBoxEx(groupBox_4);
        comboBoxBaud->setObjectName(QString::fromUtf8("comboBoxBaud"));
        sizePolicy1.setHeightForWidth(comboBoxBaud->sizePolicy().hasHeightForWidth());
        comboBoxBaud->setSizePolicy(sizePolicy1);
        comboBoxBaud->setMinimumSize(QSize(0, 30));
        comboBoxBaud->setMaximumSize(QSize(120, 16777215));

        gridLayout_5->addWidget(comboBoxBaud, 0, 7, 1, 1);

        label_24 = new LabelEx(groupBox_4);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        sizePolicy3.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(label_24, 2, 0, 1, 1);


        gridLayout->addWidget(groupBox_4, 3, 0, 1, 1);


        retranslateUi(ConfigForm);

        QMetaObject::connectSlotsByName(ConfigForm);
    } // setupUi

    void retranslateUi(QWidget *ConfigForm)
    {
        ConfigForm->setWindowTitle(QApplication::translate("ConfigForm", "Form", nullptr));
        groupBox_3->setTitle(QString());
        label_22->setText(QApplication::translate("ConfigForm", "\345\257\206   \347\240\201\357\274\232", nullptr));
        label_14->setText(QApplication::translate("ConfigForm", "\346\225\260\346\215\256\345\272\223\345\220\215\357\274\232", nullptr));
        pushButton_6->setText(QApplication::translate("ConfigForm", "\350\256\276\347\275\256", nullptr));
        label_15->setText(QApplication::translate("ConfigForm", "\346\234\215\345\212\241\345\231\250\345\220\215\357\274\232", nullptr));
        label_23->setText(QApplication::translate("ConfigForm", "\347\231\273\345\275\225\345\220\215\357\274\232", nullptr));
        groupBox->setTitle(QString());
        label_21->setText(QApplication::translate("ConfigForm", "\345\257\206   \347\240\201\357\274\232", nullptr));
        label_13->setText(QApplication::translate("ConfigForm", "\346\225\260\346\215\256\345\272\223\345\220\215\357\274\232", nullptr));
        pushButtonSetDb->setText(QApplication::translate("ConfigForm", "\350\256\276\347\275\256", nullptr));
        label_8->setText(QApplication::translate("ConfigForm", "\346\234\215\345\212\241\345\231\250\345\220\215\357\274\232", nullptr));
        label_20->setText(QApplication::translate("ConfigForm", "\347\231\273\345\275\225\345\220\215\357\274\232", nullptr));
        groupBox_2->setTitle(QString());
        label_17->setText(QApplication::translate("ConfigForm", "\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232", nullptr));
        pushButtonSetNet->setText(QApplication::translate("ConfigForm", "\350\256\276\347\275\256", nullptr));
        label_16->setText(QApplication::translate("ConfigForm", "IP\357\274\232", nullptr));
        label_7->setText(QApplication::translate("ConfigForm", "\347\253\257     \345\217\243\357\274\232", nullptr));
        labelNetState->setText(QApplication::translate("ConfigForm", "\346\226\255\345\274\200", nullptr));
        groupBox_4->setTitle(QString());
        pushButtonRefresh->setText(QApplication::translate("ConfigForm", "\345\210\267\346\226\260", nullptr));
        label_25->setText(QApplication::translate("ConfigForm", " \345\272\217\345\210\227\345\217\267\357\274\232   ", nullptr));
        pushButtonSetCom->setText(QApplication::translate("ConfigForm", "\350\256\276\347\275\256", nullptr));
        labelComState->setText(QApplication::translate("ConfigForm", "\345\205\263\351\227\255", nullptr));
        label_18->setText(QApplication::translate("ConfigForm", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        label_19->setText(QApplication::translate("ConfigForm", "\344\270\262\345\217\243\345\220\215\357\274\232     ", nullptr));
        label_24->setText(QApplication::translate("ConfigForm", "\346\211\223\345\274\200\347\212\266\346\200\201\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfigForm: public Ui_ConfigForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGFORM_H
