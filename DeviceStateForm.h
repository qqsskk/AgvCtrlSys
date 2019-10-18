#ifndef DEVICESTATEFORM_H
#define DEVICESTATEFORM_H

#include <QWidget>
#include <QHBoxLayout>
#include <QTimer>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include "CustomTableModel.h"

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
    QSqlQueryModel *m_model;

private slots:
    void onUpdateModel();
};

#endif // DEVICESTATEFORM_H
