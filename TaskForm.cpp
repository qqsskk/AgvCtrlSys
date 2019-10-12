#include "TaskForm.h"
#include "ui_TaskForm.h"

TaskForm::TaskForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskForm)
{
    ui->setupUi(this);
}

TaskForm::~TaskForm()
{
    delete ui;
}
