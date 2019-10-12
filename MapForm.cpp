#include "MapForm.h"
#include "ui_MapForm.h"

MapForm::MapForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapForm)
{
    ui->setupUi(this);

}

MapForm::~MapForm()
{
    delete ui;
}
