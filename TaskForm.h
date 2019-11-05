#ifndef TASKFORM_H
#define TASKFORM_H

#include <QWidget>
#include <QTimer>
#include <QSqlQueryModel>
#include <QSqlTableModel>

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
};

#endif // TASKFORM_H
