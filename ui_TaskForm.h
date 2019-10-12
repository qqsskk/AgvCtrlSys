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
#include <QtWidgets/QWidget>
#include "LineEditEx.h"

QT_BEGIN_NAMESPACE

class Ui_TaskForm
{
public:
    LineEditEx *lineEdit;
    LineEditEx *lineEdit_2;
    LineEditEx *lineEdit_3;

    void setupUi(QWidget *TaskForm)
    {
        if (TaskForm->objectName().isEmpty())
            TaskForm->setObjectName(QString::fromUtf8("TaskForm"));
        TaskForm->resize(400, 300);
        lineEdit = new LineEditEx(TaskForm);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 80, 151, 41));
        lineEdit_2 = new LineEditEx(TaskForm);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(60, 150, 151, 41));
        lineEdit_3 = new LineEditEx(TaskForm);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        lineEdit_3->setGeometry(QRect(100, 200, 151, 41));

        retranslateUi(TaskForm);

        QMetaObject::connectSlotsByName(TaskForm);
    } // setupUi

    void retranslateUi(QWidget *TaskForm)
    {
        TaskForm->setWindowTitle(QApplication::translate("TaskForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskForm: public Ui_TaskForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKFORM_H
