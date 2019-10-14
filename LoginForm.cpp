#include "LoginForm.h"
#include "ui_LoginForm.h"

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);

    ui->pushButtonTitle->setStyleSheet("QPushButton{background:#CCCCCC; font-size:25pt; font-family:Microsoft YaHei; color:#000000}");
    ui->pushButtonTitle->setEnabled(false);
    ui->pushButtonTitle->setText(QString::fromLocal8Bit("AGV 调度系统"));

    ui->lineEdit_userName->setText("Admin");
    ui->lineEdit_passwd->setText("Admin");

}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_pushButton_login_clicked()
{
    //检验用户名或密码是否为空
   if (ui->lineEdit_userName->text().isEmpty() || ui->lineEdit_passwd->text().isEmpty())
   {
        MessageBoxEx *msgBox = new MessageBoxEx();
        msgBox->setMessageBoxMode(QString::fromLocal8Bit("用户名或密码不可为空！"));
        return;
   }

    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC3");
    db.setDatabaseName(QString("DRIVER={SQL SERVER};"
                                   "SERVER=%1;"  //服务器名称
                                   "DATABASE=%2;"//数据库名
                                   "UID=%3;"     //登录名
                                   "PWD=%4;"     //密码
                                   )
                           .arg("zoufawei")
                           .arg("AGVDB")
                           .arg("sa")
                           .arg("456852")
                           );
    if (!db.open())
    {
        qDebug()<<QString::fromLocal8Bit("连接SQL Server数据库失败!");
        return;

    }
    QString strName = ui->lineEdit_userName->text();
    QString strPasswd = ui->lineEdit_passwd->text();

    QSqlTableModel model;
    model.setTable("AGVDB_USER");
    model.setFilter(tr("user_name = '%1' and user_passwd = '%2'").arg(strName).arg(strPasswd));
    model.select();

    MessageBoxEx *msgBox = new MessageBoxEx();
    if(model.rowCount() == 1)
    {
        msgBox->setMessageBoxMode(QString::fromLocal8Bit("登录成功！"));
        Qt::TimerType timerType;
        QTimer::singleShot(500, timerType, this, SLOT(onLoginMainWindow()));
        this->close();
    }
    else
    {
        msgBox->setMessageBoxMode(QString::fromLocal8Bit("用户名或密码错误，请重新输入!"));
        ui->lineEdit_userName->clear();
        ui->lineEdit_passwd->clear();
        return;
    }
}

void LoginForm::on_pushButton_exit_clicked()
{
    MessageBoxEx *msgBox = new MessageBoxEx();
    connect(msgBox, SIGNAL(btnOkClicked()), this, SLOT(onBtnOkClicked()));
    connect(msgBox, SIGNAL(btnCancelClicked()), this, SLOT(onBtnCancelClicked()));
    msgBox->setMessageBoxMode(QString::fromLocal8Bit("确定要退出系统吗？"),"hello", MessageBoxBtnType_OkCancle);
}

void LoginForm::onBtnOkClicked()
{
    close();
}

void LoginForm::onBtnCancelClicked()
{
}

void LoginForm::onLoginMainWindow()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}
