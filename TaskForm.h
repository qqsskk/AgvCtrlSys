#ifndef TASKFORM_H
#define TASKFORM_H

#include <QWidget>
#include <QTimer>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QToolTip>
#include "MsgBoxEx.h"

namespace Ui {
class TaskForm;
}

class TaskForm : public QWidget
{
    Q_OBJECT

public:
    explicit TaskForm(QWidget *parent = nullptr);
    ~TaskForm();

private:
    Ui::TaskForm *ui;
    QSqlQueryModel *m_model;

private slots:
    void onUpdateModel();
    void on_pushButtonCreateTask_clicked();
    void on_pushButtonDelTask_clicked();

signals:
    /**
     * @brief createTask    创建任务信号
     * @param workName      工作站名称
     * @param taskDetails   任务内容
     */
    void createTask(QString workName, QString taskDetails);
};

#endif // TASKFORM_H
