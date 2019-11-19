#ifndef DEVICESTATEFORM_H
#define DEVICESTATEFORM_H

#include <QWidget>
#include <QHBoxLayout>
#include <QTimer>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QDebug>
#include <QJsonParseError>
#include <QJsonArray>
#include <QVariantMap>
#include <memory>
#include <QAbstractTableModel>
#include <QJsonArray>
#include "CustomJsonModel.h"

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
    QSqlQueryModel *m_modelAgv;
    QSqlQueryModel *m_modelCaller;

private slots:
    void onUpdateModel();
};

#endif // DEVICESTATEFORM_H
