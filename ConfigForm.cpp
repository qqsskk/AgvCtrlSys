#include "ConfigForm.h"
#include "ui_ConfigForm.h"

ConfigForm::ConfigForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigForm)
{
    ui->setupUi(this);

    init();
}

ConfigForm::~ConfigForm()
{
    delete ui;
}

void ConfigForm::init()
{
    ui->groupBox->setTitle(QString::fromLocal8Bit("数据库服务器参数配置"));
    ui->groupBox_2->setTitle(QString::fromLocal8Bit("网络服务器参数配置"));
    ui->groupBox_3->setTitle(QString::fromLocal8Bit("设备配置"));
    ui->groupBox_3->setVisible(false);
    ui->groupBox_4->setTitle(QString::fromLocal8Bit("WMS服务器参数配置"));

    QRegExp rx("\\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b");
    ui->lineEditDevIP->setValidator(new QRegExpValidator(rx, this));
    ui->lineEditNetSerIP->setValidator(new QRegExpValidator(rx, this));
    ui->lineEditNetSerPort->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));

    // 读取服务器配置参数
    Config config("./res/set/config.ini");
    QString serverName = config.get("DataBase", "ServerName").toString();
    QString databaseName = config.get("DataBase", "DataBaseName").toString();
    QString loginName = config.get("DataBase", "LoginName").toString();
    QString passwd = config.get("DataBase", "Passwd").toString();
    QString netip = config.get("Net", "IP").toString();
    QString netport = config.get("Net", "Port").toString();

    // 填充相应文本框
    ui->lineEditSerName->setText(serverName);
    ui->lineEditDbName->setText(databaseName);
    ui->lineEditLoginName->setText(loginName);
    ui->lineEditPasswd->setText(passwd);
    ui->lineEditNetSerIP->setText(netip);
    ui->lineEditNetSerPort->setText(netport);

    // 初始化组合框
    // P牵引式 S潜入式 T移载式 F叉车式 A机械手式 L激光式
    // S单向 D双向 F全向
    ui->comboBoxDevType->addItem(QString::fromLocal8Bit("牵引式"));
    ui->comboBoxDevType->addItem(QString::fromLocal8Bit("潜入式"));
    ui->comboBoxDevType->addItem(QString::fromLocal8Bit("移载式"));
    ui->comboBoxDevType->addItem(QString::fromLocal8Bit("叉车式"));
    ui->comboBoxDevType->addItem(QString::fromLocal8Bit("机械手式"));
    ui->comboBoxDevType->addItem(QString::fromLocal8Bit("激光式"));
    ui->comboBoxDire->addItem(QString::fromLocal8Bit("单向"));
    ui->comboBoxDire->addItem(QString::fromLocal8Bit("双向"));
    ui->comboBoxDire->addItem(QString::fromLocal8Bit("全向"));
}

void ConfigForm::on_pushButtonSetDb_clicked()
{
    QString serverName = ui->lineEditSerName->text();
    QString databaseName = ui->lineEditDbName->text();
    QString loginName = ui->lineEditLoginName->text();
    QString passwd = ui->lineEditPasswd->text();

    if(serverName.isEmpty() || databaseName.isEmpty() || loginName.isEmpty() || passwd.isEmpty())
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("所有数据库服务器参数都不可为空！"));
        return;
    }

    // 设置服务器参数
    Config config("./res/set/config.ini");
    config.set("DataBase", "ServerName", QString("%1").arg(serverName));
    config.set("DataBase", "DataBaseName", QString("%1").arg(databaseName));
    config.set("DataBase", "LoginName", QString("%1").arg(loginName));
    config.set("DataBase", "Passwd", QString("%1").arg(passwd));

    MsgBoxEx *msgBox = new MsgBoxEx();
    msgBox->setMsgBoxMode(QString::fromLocal8Bit("数据库服务器参数设置成功，若要应用此设置请重启程序！"), 3000);
}

void ConfigForm::on_pushButtonSetNet_clicked()
{
    QString ip = ui->lineEditNetSerIP->text();
    QString port = ui->lineEditNetSerPort->text();

    if(ip.isEmpty() || port.isEmpty())
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("网络服务器参数不可为空！"));
        return;
    }

    Config config("./res/set/config.ini");
    config.set("Net", "IP", QString("%1").arg(ui->lineEditNetSerIP->text()));
    config.set("Net", "Port", QString("%1").arg(ui->lineEditNetSerPort->text()));

    MsgBoxEx *msgBox = new MsgBoxEx();
    msgBox->setMsgBoxMode(QString::fromLocal8Bit("网络服务器参数设置成功，若要应用此设置请重启程序！"), 3000);
}

void ConfigForm::on_pushButtonAddDev_clicked()
{
    QString devid = ui->lineEditDevNO->text();
    QString devip = ui->lineEditDevIP->text();
    QString devport = ui->lineEditDevPort->text();
    QString devtype = ui->comboBoxDevType->currentText();
    QString devdire = ui->comboBoxDire->currentText();


    if(devid.isEmpty() || devip.isEmpty() || devport.isEmpty())
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("设备信息不可为空！"));
        return;
    }

    QSqlQuery query;
    query.exec(QString("SELECT * FROM AGVDB_INFO_AGV WHERE ID = %1").arg(devid));
    if(query.next())
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("设备ID重复！"));
        return;
    }

    query.prepare(QString("INSERT INTO AGVDB_INFO_AGV (ID, Type, Move, IP, Port) \
                          VALUES (%1, '%2', '%3', '%4', %5)").arg(devid).arg(devtype).arg(devdire).arg(devip).arg(devport));
    if(query.exec())
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("添加成功！"));
    }
    else
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("添加失败！"));
    }
}
