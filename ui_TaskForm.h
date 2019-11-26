/********************************************************************************
** Form generated from reading UI file 'TaskForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKFORM_H
#define UI_TASKFORM_H

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

class Ui_TaskForm
{
public:
    QGridLayout *gridLayout_2;
    TableViewEx *tableView;
    GroupBoxEx *groupBox;
    QGridLayout *gridLayout;
    LabelEx *label_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    ComboBoxEx *comboBoxTargetWork;
    PushButtonEx *pushButtonDelTask;
    ComboBoxEx *comboBoxTaskDetails;
    PushButtonEx *pushButtonCreateTask;
    QSpacerItem *horizontalSpacer_2;
    LabelEx *label_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    LabelEx *label;
    LineEditEx *lineEditTaskNum;

    void setupUi(QWidget *TaskForm)
    {
        if (TaskForm->objectName().isEmpty())
            TaskForm->setObjectName(QString::fromUtf8("TaskForm"));
        TaskForm->resize(760, 544);
        gridLayout_2 = new QGridLayout(TaskForm);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableView = new TableViewEx(TaskForm);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout_2->addWidget(tableView, 0, 0, 1, 1);

        groupBox = new GroupBoxEx(TaskForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 50, -1, -1);
        label_3 = new LabelEx(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 4, 1, 1);

        comboBoxTargetWork = new ComboBoxEx(groupBox);
        comboBoxTargetWork->setObjectName(QString::fromUtf8("comboBoxTargetWork"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxTargetWork->sizePolicy().hasHeightForWidth());
        comboBoxTargetWork->setSizePolicy(sizePolicy);
        comboBoxTargetWork->setMinimumSize(QSize(150, 30));

        gridLayout->addWidget(comboBoxTargetWork, 0, 2, 1, 1);

        pushButtonDelTask = new PushButtonEx(groupBox);
        pushButtonDelTask->setObjectName(QString::fromUtf8("pushButtonDelTask"));
        sizePolicy.setHeightForWidth(pushButtonDelTask->sizePolicy().hasHeightForWidth());
        pushButtonDelTask->setSizePolicy(sizePolicy);
        pushButtonDelTask->setMinimumSize(QSize(150, 35));

        gridLayout->addWidget(pushButtonDelTask, 2, 7, 1, 1);

        comboBoxTaskDetails = new ComboBoxEx(groupBox);
        comboBoxTaskDetails->setObjectName(QString::fromUtf8("comboBoxTaskDetails"));
        sizePolicy.setHeightForWidth(comboBoxTaskDetails->sizePolicy().hasHeightForWidth());
        comboBoxTaskDetails->setSizePolicy(sizePolicy);
        comboBoxTaskDetails->setMinimumSize(QSize(150, 30));

        gridLayout->addWidget(comboBoxTaskDetails, 0, 5, 1, 1);

        pushButtonCreateTask = new PushButtonEx(groupBox);
        pushButtonCreateTask->setObjectName(QString::fromUtf8("pushButtonCreateTask"));
        sizePolicy.setHeightForWidth(pushButtonCreateTask->sizePolicy().hasHeightForWidth());
        pushButtonCreateTask->setSizePolicy(sizePolicy);
        pushButtonCreateTask->setMinimumSize(QSize(150, 35));

        gridLayout->addWidget(pushButtonCreateTask, 0, 7, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(157, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 5, 1, 1);

        label_2 = new LabelEx(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 6, 1, 1);

        label = new LabelEx(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditTaskNum = new LineEditEx(groupBox);
        lineEditTaskNum->setObjectName(QString::fromUtf8("lineEditTaskNum"));
        sizePolicy.setHeightForWidth(lineEditTaskNum->sizePolicy().hasHeightForWidth());
        lineEditTaskNum->setSizePolicy(sizePolicy);
        lineEditTaskNum->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEditTaskNum, 2, 2, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 1);


        retranslateUi(TaskForm);

        QMetaObject::connectSlotsByName(TaskForm);
    } // setupUi

    void retranslateUi(QWidget *TaskForm)
    {
        TaskForm->setWindowTitle(QApplication::translate("TaskForm", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("TaskForm", "GroupBox", nullptr));
        label_3->setText(QApplication::translate("TaskForm", "\344\273\273\345\212\241\345\217\267\357\274\232", nullptr));
        pushButtonDelTask->setText(QApplication::translate("TaskForm", "\345\210\240\351\231\244\344\273\273\345\212\241", nullptr));
        pushButtonCreateTask->setText(QApplication::translate("TaskForm", "\345\210\233\345\273\272\344\273\273\345\212\241", nullptr));
        label_2->setText(QApplication::translate("TaskForm", "\344\273\273\345\212\241\345\206\205\345\256\271\357\274\232", nullptr));
        label->setText(QApplication::translate("TaskForm", "\347\233\256\346\240\207\345\267\245\347\253\231\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskForm: public Ui_TaskForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKFORM_H
