﻿#include "LoginSetForm.h"
#include "ui_LoginSetForm.h"

LoginSetForm::LoginSetForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginSetForm)
{
    ui->setupUi(this);

    // 初始界面
    setWindowIcon(QIcon("./res/icon/sys.png"));
    setWindowTitle(QString::fromLocal8Bit("系统配置"));
    setWindowFlags(Qt::FramelessWindowHint);
    ui->pushButtonTitle->setStyleSheet("QPushButton:!enabled{background:#31343B; font-size:15pt; font-family:Microsoft YaHei; color:#FFFFFF}");
    ui->pushButtonTitle->setEnabled(false);
    ui->pushButtonTitle->setText(QString::fromLocal8Bit("服务器配置"));
    ui->label_2->setStyleSheet("QLabel {font: 10pt Microsoft YaHei; color:000000}");
    ui->label_3->setStyleSheet("QLabel {font: 10pt Microsoft YaHei; color:000000}");
    ui->label_4->setStyleSheet("QLabel {font: 10pt Microsoft YaHei; color:000000}");
    ui->label_5->setStyleSheet("QLabel {font: 10pt Microsoft YaHei; color:000000}");

    // 读取服务器配置参数
    Config config("./res/set/config.ini");
    QString serverName = config.get("DataBase", "ServerName").toString();
    QString databaseName = config.get("DataBase", "DataBaseName").toString();
    QString loginName = config.get("DataBase", "LoginName").toString();
    QString passwd = config.get("DataBase", "Passwd").toString();

    // 填充相应文本框
    ui->lineEditSerName->setText(serverName);
    ui->lineEditDbName->setText(databaseName);
    ui->lineEditLoginName->setText(loginName);
    ui->lineEditLoginPwd->setText(passwd);
}

LoginSetForm::~LoginSetForm()
{
    delete ui;
}

void LoginSetForm::on_pushButtonCancel_clicked()
{
    close();
}

void LoginSetForm::on_pushButtonOk_clicked()
{
    QString serverName = ui->lineEditSerName->text();
    QString databaseName = ui->lineEditDbName->text();
    QString loginName = ui->lineEditLoginName->text();
    QString passwd = ui->lineEditLoginPwd->text();

    MsgBoxEx *msgBox = new MsgBoxEx();
    if(serverName.isEmpty() || databaseName.isEmpty() || loginName.isEmpty() || passwd.isEmpty())
    {
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("所有服务器参数都不可为空！"));
        return;
    }

    // 设置服务器参数
    Config config("./res/set/config.ini");
    config.set("DataBase", "ServerName", QString("%1").arg(serverName));
    config.set("DataBase", "DataBaseName", QString("%1").arg(databaseName));
    config.set("DataBase", "LoginName", QString("%1").arg(loginName));
    config.set("DataBase", "Passwd", QString("%1").arg(passwd));

    close();
}