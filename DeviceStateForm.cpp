#include "DeviceStateForm.h"
#include "ui_DeviceStateForm.h"

DeviceStateForm::DeviceStateForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceStateForm)
{
    ui->setupUi(this);

}

DeviceStateForm::~DeviceStateForm()
{
    delete ui;
}
