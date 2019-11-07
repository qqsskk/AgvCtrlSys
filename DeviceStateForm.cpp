#include "DeviceStateForm.h"
#include "ui_DeviceStateForm.h"

#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QDebug>
#include <QJsonParseError>
#include <QJsonArray>
#include "CustomJsonModel.h"
#include <QVariantMap>
#include <memory>
#include <QAbstractTableModel>
#include <QJsonArray>

DeviceStateForm::DeviceStateForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceStateForm)
{
    ui->setupUi(this);


    m_model= new QSqlQueryModel(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onUpdateModel()));
    timer->start(1000);
}

DeviceStateForm::~DeviceStateForm()
{
    delete ui;
}

void DeviceStateForm::onUpdateModel()
{
    m_model->setQuery(QString("SELECT * FROM AGVDB_INFO_AGV"));
    m_model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("编号"));
    m_model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("类型"));
    m_model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("IP"));
    m_model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("端口"));
    m_model->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("当前地标卡"));
    m_model->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("目标地标卡"));
    m_model->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("状态"));
    m_model->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("电量"));
    m_model->setHeaderData(8, Qt::Horizontal, QString::fromLocal8Bit("速度"));
    m_model->setHeaderData(9, Qt::Horizontal, QString::fromLocal8Bit("载货"));
    m_model->setHeaderData(10, Qt::Horizontal, QString::fromLocal8Bit("动作"));
    m_model->setHeaderData(11, Qt::Horizontal, QString::fromLocal8Bit("异常"));
    ui->tableView->setTableModel(m_model);
}
