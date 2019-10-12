#ifndef DEVICESTATEFORM_H
#define DEVICESTATEFORM_H

#include <QWidget>
#include <QHBoxLayout>
#include "TableViewEx.h"

namespace Ui {
class DeviceStateForm;
}

class DeviceStateForm : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceStateForm(QWidget *parent = nullptr);
    ~DeviceStateForm();

private:
    Ui::DeviceStateForm *ui;
};

#endif // DEVICESTATEFORM_H
