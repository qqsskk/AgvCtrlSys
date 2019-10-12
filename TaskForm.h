#ifndef TASKFORM_H
#define TASKFORM_H

#include <QWidget>

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
};

#endif // TASKFORM_H
