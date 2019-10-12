#include "AbnormalForm.h"
#include "ui_AbnormalForm.h"

AbnormalForm::AbnormalForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AbnormalForm)
{
    ui->setupUi(this);
}

AbnormalForm::~AbnormalForm()
{
    delete ui;
}
