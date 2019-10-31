#include "LoginForm.h"
#include "ui_LoginForm.h"

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);

    init();
}

LoginForm::~LoginForm()
{
    delete ui;

    if(m_loginSetForm)
    {
        delete m_loginSetForm;
        m_loginSetForm = nullptr;
    }

}

void LoginForm::init()
{
    setWindowIcon(QIcon("./res/icon/sys.png"));
    setWindowTitle(QString::fromLocal8Bit("系统登录"));
    setWindowFlags(Qt::FramelessWindowHint);

    ui->pushButtonTitle->setStyleSheet("QPushButton:!enabled{background:#31343B; font-size:18pt; font-family:Microsoft YaHei; color:#FFFFFF}");
    ui->pushButtonTitle->setEnabled(false);
    ui->pushButtonTitle->setText(QString::fromLocal8Bit("AGV 调度系统"));

    ui->lineEdit_userName->setText("Admin");
    ui->lineEdit_passwd->setText("Admin");

    ui->label->setStyleSheet("QLabel {font: 10pt Microsoft YaHei; color:000000}");
    ui->label_2->setStyleSheet("QLabel {font: 10pt Microsoft YaHei; color:000000}");
    ui->toolButtonSet->setStyleSheet("QToolButton{background:transparent; border-image:url(./res/icon/set.png)}\
                        QToolButton:hover{border-image:url(./res/icon/set_hover.png)}\
                        QToolButton:pressed{border-image:url(./res/icon/set_pressed.png);}");
    connect(ui->toolButtonSet, SIGNAL(clicked()), this, SLOT(onSetClicked()));

    m_loginSetForm = new LoginSetForm();
    connect(m_loginSetForm, SIGNAL(setFormClosed()), this, SLOT(onSetFormClosed()));
    connect(this, SIGNAL(closeLoginSetForm()), m_loginSetForm, SLOT(onCloseLoginSetForm()));
}

void LoginForm::on_pushButton_login_clicked()
{
    if(!linkdb())
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("连接数据库失败，请检查服务器参数配置！"), 3000);
        return;
    }

     // 空字符校验
    QString strName = ui->lineEdit_userName->text();
    QString strPasswd = ui->lineEdit_passwd->text();
    if (strName.isEmpty() || strPasswd.isEmpty())
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("用户名或密码不可为空！"));
        return;
    }


    // 查询用户表
    bool bOk = false;
    QSqlQuery query;
    query.exec(tr("SELECT * FROM AGVDB_INFO_USER WHERE user_name = '%1' AND user_passwd = '%2'").arg(strName).arg(strPasswd));
    while (query.next())
    {
        m_userName = query.value(0).toString();
        m_userPasswd = query.value(1).toString();
        m_userLevel = query.value(2).toInt();
        Qt::CaseSensitivity cs = Qt::CaseSensitive;
        if (strName.compare(m_userName, cs) == 0 && strPasswd.compare(m_userPasswd, cs) == 0)
        {
           bOk = true;
        }
    }

    if(!bOk)
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("用户名或密码错误，请重新输入!"));
        ui->lineEdit_userName->clear();
        ui->lineEdit_passwd->clear();
        return;
    }
    else
    {
        emit closeLoginSetForm();   // 关闭登录设置窗口

        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("登录成功！"));
        QTimer::singleShot(500, this, SLOT(onLoginMainWindow()));
        this->close();
    }
}

void LoginForm::on_pushButton_exit_clicked()
{
    MsgBoxEx *msgBox = new MsgBoxEx();
    connect(msgBox, SIGNAL(btnOkClicked()), this, SLOT(onBtnOkClicked()));
    connect(msgBox, SIGNAL(btnCancelClicked()), this, SLOT(onBtnCancelClicked()));
    msgBox->setMsgBoxMode(QString::fromLocal8Bit("确定要退出系统吗？"), "", MsgBoxBtnType::MsgBoxBtnType_OkCancle);
}

void LoginForm::onBtnOkClicked()
{
    emit closeLoginSetForm();   // 关闭登录设置窗口

    close();
}

void LoginForm::onBtnCancelClicked(){}

void LoginForm::onLoginMainWindow()
{
    MainWindow *mainWindow = new MainWindow(m_userName, m_userPasswd, m_userLevel);
    mainWindow->show();
}

void LoginForm::onSetClicked()
{
    m_loginSetForm->show();
    ui->toolButtonSet->setVisible(false);
}

bool LoginForm::linkdb()
{
    // 读取服务器配置参数
    Config config("./res/set/config.ini");
    QString serverName = config.get("DataBase", "ServerName").toString();
    QString databaseName = config.get("DataBase", "DataBaseName").toString();
    QString loginName = config.get("DataBase", "LoginName").toString();
    QString passwd = config.get("DataBase", "Passwd").toString();

    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC3");
    db.setDatabaseName(QString("DRIVER={SQL SERVER};"
                                   "SERVER=%1;"
                                   "DATABASE=%2;"
                                   "UID=%3;"
                                   "PWD=%4;").arg(serverName).arg(databaseName).arg(loginName).arg(passwd));
    if (!db.open())
    {
        return false;
    }
    return true;
}


void LoginForm::onSetFormClosed()
{
    ui->toolButtonSet->setVisible(true);
}
