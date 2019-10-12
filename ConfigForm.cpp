#include "ConfigForm.h"
#include "ui_ConfigForm.h"

ConfigForm::ConfigForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigForm)
{
    ui->setupUi(this);
}

ConfigForm::~ConfigForm()
{
    delete ui;
}
