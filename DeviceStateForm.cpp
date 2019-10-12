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

//    // 测试连接数据库
//    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC3");
//    db.setDatabaseName(QString("DRIVER={SQL SERVER};"
//                                   "SERVER=%1;"  //服务器名称
//                                   "DATABASE=%2;"//数据库名
//                                   "UID=%3;"     //登录名
//                                   "PWD=%4;"     //密码
//                                   )
//                           .arg("zoufawei")
//                           .arg("LYDB")
//                           .arg("sa")
//                           .arg("456852")
//                           );
//    if (!db.open())
//    {
//        qDebug()<<"connect sql server failed!";
//        return;

//    }
//    else
//    {
//        qDebug()<<"connect sql server successfully!";
//    }
//    QSqlQueryModel *model = new QSqlQueryModel;
//    model->setQuery(QObject::tr("select * from AGV"));

    // 使用JSON
    QString str("[	{\"a\":1,\"b\":0.1,\"c\":\"xx\"},\
    {\"a\":2,\"b\":0.2,\"c\":\"yy\"},\
      {\"a\":2,\"b\":0.2,\"c\":\"zz\"}]");
    QJsonParseError err;
    QJsonDocument jd = QJsonDocument::fromJson(str.toUtf8(), &err);
    QJsonArray ja = jd.array();
    CustomJsonModel *model = new CustomJsonModel(ja, this);

    // CustomTableModel *model = new CustomTableModel;
    ui->tableView->setTableModel(model);
}

DeviceStateForm::~DeviceStateForm()
{
    delete ui;
}
