#include "HistoryForm.h"
#include "ui_HistoryForm.h"

HistoryForm::HistoryForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HistoryForm)
{
    ui->setupUi(this);

    ui->comboBox->addItem(QString::fromLocal8Bit("测试1"));
    ui->comboBox->addItem(QString::fromLocal8Bit("测试abc"));
}

HistoryForm::~HistoryForm()
{
    delete ui;
}
