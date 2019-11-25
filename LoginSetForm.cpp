#include "LoginSetForm.h"
#include "ui_LoginSetForm.h"

LoginSetForm::LoginSetForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginSetForm)
{
    ui->setupUi(this);

    init();
}

LoginSetForm::~LoginSetForm()
{
    delete ui;
}

void LoginSetForm::init()
{
    // 初始界面
    setWindowIcon(QIcon("./res/icon/sys.png"));
    setWindowTitle(QString::fromLocal8Bit("参数配置"));
    setWindowFlags(Qt::FramelessWindowHint);

    ui->pushButtonTitle->setStyleSheet("QPushButton:!enabled{background:#31343B; font-size:15pt; font-family:Microsoft YaHei; color:#FFFFFF}");
    ui->pushButtonTitle->setEnabled(false);
    ui->pushButtonTitle->setText(QString::fromLocal8Bit("参数配置"));
    QString strLabelStyle = "QLabel {font: 10pt Microsoft YaHei; color:000000}";
    ui->label_2->setStyleSheet(strLabelStyle);
    ui->label_3->setStyleSheet(strLabelStyle);
    ui->label_4->setStyleSheet(strLabelStyle);
    ui->label_5->setStyleSheet(strLabelStyle);
    ui->label_6->setStyleSheet(strLabelStyle);
    ui->label_8->setStyleSheet(strLabelStyle);
    ui->label_9->setStyleSheet(strLabelStyle);
    ui->label_10->setStyleSheet(strLabelStyle);
    ui->label_11->setStyleSheet(strLabelStyle);
    ui->label_12->setStyleSheet(strLabelStyle);
    ui->labelComDetails->setStyleSheet(strLabelStyle);

    ui->toolButtonEye->setStyleSheet("QToolButton{background:transparent;}\
                                     QToolButton:!checked{border-image:url(./res/icon/eye_close.png);}\
                                     QToolButton:checked{border-image:url(./res/icon/eye_open.png);}");
    connect(ui->toolButtonEye, SIGNAL(toggled(bool)), this, SLOT(onEyeToggled(bool)));

    QString strGroupBoxStyle = "QGroupBox{border: 1px solid #CCCCCC}";
    ui->groupBox->setStyleSheet(strGroupBoxStyle);
    ui->groupBox_2->setStyleSheet(strGroupBoxStyle);
    ui->groupBox_3->setStyleSheet(strGroupBoxStyle);


    // 串口号
    m_mapSerialPort.clear();
    ui->comboBoxComName->clear();
    ui->lineEditComNum->setText("");
    ui->comboBoxComBaud->setCurrentIndex(-1);
    ui->labelComDetails->setText("");

    QSerialPort serial;
    QStringList listPort;
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
    {
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            m_mapSerialPort[info.portName()] = info.serialNumber()+";"+info.description();
            serial.close();
        }
    }
    for (QMap<QString, QString>::iterator it = m_mapSerialPort.begin(); it != m_mapSerialPort.end(); it++)
    {
        if(!it.key().isEmpty())
        {
            ui->comboBoxComName->addItem(it.key());
        }
    }
    ui->comboBoxComName->setCurrentIndex(-1);

    // 波特率
    ui->comboBoxComBaud->addItem("9600");
    ui->comboBoxComBaud->addItem("19200");
    ui->comboBoxComBaud->addItem("38400");
    ui->comboBoxComBaud->addItem("57600");
    ui->comboBoxComBaud->addItem("115200");

    // 读取服务器配置参数
    Config config("./res/set/config.ini");
    QString serverName = config.get("DataBase", "ServerName").toString();
    QString databaseName = config.get("DataBase", "DataBaseName").toString();
    QString loginName = config.get("DataBase", "LoginName").toString();
    QString passwd = config.get("DataBase", "Passwd").toString();
    QString netip = config.get("Net", "IP").toString();
    QString netport = config.get("Net", "Port").toString();
    QString com = config.get("SerialPort", "Com").toString();
    QString num = config.get("SerialPort", "Num").toString();
    QString baud = config.get("SerialPort", "Baud").toString();
    QString details = config.get("SerialPort", "Details").toString();

    // 填充相应文本框
    ui->lineEditSerName->setText(serverName);
    ui->lineEditDbName->setText(databaseName);
    ui->lineEditLoginName->setText(loginName);
    ui->lineEditLoginPwd->setText(passwd);
    ui->lineEditNetIP->setText(netip);
    ui->lineEditNetPort->setText(netport);
    ui->comboBoxComName->setCurrentText(com);
    ui->lineEditComNum->setText(num);
    ui->comboBoxComBaud->setCurrentText(baud);
    ui->labelComDetails->setText(details);
}

void LoginSetForm::onEyeToggled(bool checked)
{
    if(checked)
    {
        ui->lineEditLoginPwd->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->lineEditLoginPwd->setEchoMode(QLineEdit::Password);
    }
}

void LoginSetForm::on_pushButtonCancel_clicked()
{
    emit setFormClosed();
    close();
}

void LoginSetForm::on_pushButtonOk_clicked()
{
    QString serverName = ui->lineEditSerName->text();
    QString databaseName = ui->lineEditDbName->text();
    QString loginName = ui->lineEditLoginName->text();
    QString passwd = ui->lineEditLoginPwd->text();
    QString ip = ui->lineEditNetIP->text();
    QString port = ui->lineEditNetPort->text();
    QString name = ui->comboBoxComName->currentText();
    QString num = ui->lineEditComNum->text();
    QString baud = ui->comboBoxComBaud->currentText();
    QString details = ui->labelComDetails->text();

    if(serverName.isEmpty() || databaseName.isEmpty() || loginName.isEmpty() || passwd.isEmpty())
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("所有服务器参数都不可为空！"));
        delete msgBox;
        return;
    }
    if(port.isEmpty())
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("网络服务器端口不可为空！"));
        delete msgBox;
        return;
    }
    if(name.isEmpty() || baud.isEmpty())
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("串口名或波特率不可为空！"));
        delete msgBox;
        return;
    }

    // 设置服务器参数
    Config config("./res/set/config.ini");
    config.set("DataBase", "ServerName", QString("%1").arg(serverName));
    config.set("DataBase", "DataBaseName", QString("%1").arg(databaseName));
    config.set("DataBase", "LoginName", QString("%1").arg(loginName));
    config.set("DataBase", "Passwd", QString("%1").arg(passwd));
    config.set("Net", "IP", QString("%1").arg(ip));
    config.set("Net", "Port", QString("%1").arg(port));
    config.set("SerialPort", "Com", QString("%1").arg(name));
    config.set("SerialPort", "Num", QString("%1").arg(num));
    config.set("SerialPort", "Baud", QString("%1").arg(baud));
    config.set("SerialPort", "Details", QString("%1").arg(details));

    emit setFormClosed();
    close();
}

void LoginSetForm::onCloseLoginSetForm()
{
    close();
}

void LoginSetForm::on_comboBoxComName_currentTextChanged(const QString &arg1)
{
    QString strValue = m_mapSerialPort[arg1];
    QStringList listValue = strValue.split(";");

    if(listValue.count()!=2)
        return;
    ui->lineEditComNum->setText(listValue[0]);
    ui->labelComDetails->setText(listValue[1]);
}
