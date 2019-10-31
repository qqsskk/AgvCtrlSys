#include "UserForm.h"
#include "ui_UserForm.h"

UserForm::UserForm(QString user, QString passwd, int level, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserForm)
{
    ui->setupUi(this);

    m_userName = user;
    m_userPasswd = passwd;
    m_userLevel = level;

    init();
}

UserForm::~UserForm()
{
    delete ui;
}

void UserForm::init()
{
    // 组合框
    ui->groupBox->setTitle(QString::fromLocal8Bit("当前用户信息"));
    ui->groupBoxPasswdChange->setTitle(QString::fromLocal8Bit("密码修改"));
    ui->groupBoxPasswdChange->setVisible(false);
    ui->groupBoxUserChange->setTitle(QString::fromLocal8Bit("用户设置"));
    ui->groupBoxUserChange->setVisible(false);


    // 用户名和等级
    ui->labelUserName->setText(m_userName);
    switch(m_userLevel)
    {
        case UserLevel::UserLevel_High:
        ui->labelLevel->setText(QString::fromLocal8Bit("高"));
        break;
        case UserLevel::UserLevel_Center:
        ui->labelLevel->setText(QString::fromLocal8Bit("中"));
        break;
        case UserLevel::UserLevel_Low:
        ui->labelLevel->setText(QString::fromLocal8Bit("低"));
        break;
    }

    // 用户列表
    m_modelUser = new QSqlQueryModel(this);
    connect(ui->tableViewUserInfo, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onClickedUserList(const QModelIndex &)));
    updateModel();

    // 等级组合框
    ui->comboBoxLevel->addItem("1");
    ui->comboBoxLevel->addItem("2");
    ui->comboBoxLevel->addItem("3");
    ui->comboBoxLevel->setCurrentIndex(-1);
}

void UserForm::updateModel()
{
    m_modelUser->setQuery(QString("SELECT * FROM AGVDB_INFO_USER"));
    m_modelUser->setHeaderData(0, Qt::Horizontal,QString::fromLocal8Bit("用户名"));
    m_modelUser->setHeaderData(1, Qt::Horizontal,QString::fromLocal8Bit("密  码"));
    m_modelUser->setHeaderData(2, Qt::Horizontal,QString::fromLocal8Bit("等  级"));
    ui->tableViewUserInfo->setTableModel(m_modelUser);
}

void UserForm::on_pushButtonChangePasswd_clicked()
{
    if(ui->groupBoxPasswdChange->isHidden())
    {
       ui->groupBoxPasswdChange->setVisible(true);
    }
}

void UserForm::on_pushButtonChangePwdCancel_clicked()
{
    ui->lineEditPwdOld->setText("");
    ui->lineEditPwdNew->setText("");
    ui->lineEditPwdMakesure->setText("");
    ui->groupBoxPasswdChange->setVisible(false);
}

void UserForm::on_pushButtonChangePwdOk_clicked()
{
    MsgBoxEx *msgBox = new MsgBoxEx();
    QString pwdold = ui->lineEditPwdOld->text();
    QString pwdnew = ui->lineEditPwdNew->text();
    QString pwdmakesure = ui->lineEditPwdMakesure->text();

    if(pwdold.isEmpty() || pwdnew.isEmpty() || pwdmakesure.isEmpty())
    {
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("所有密码输入框都不可为空！"));
        return;
    }

    if(pwdold != m_userPasswd)
    {
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("旧密码与当前密码不一致！"));
        return;
    }
    if(pwdold == pwdnew)
    {
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("旧密码与新密码相同！"));
        return;
    }
    if(pwdnew != pwdmakesure)
    {
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("两次输入的密码不一致！"));
        return;
    }

    // 更新密码
    QSqlQuery query;
    query.prepare(QString("UPDATE AGVDB_INFO_USER SET user_passwd = '%1'  WHERE user_name = '%2'").arg(pwdnew).arg(m_userName));
    if(query.exec())
    {
       msgBox->setMsgBoxMode(QString::fromLocal8Bit("修改密码成功！"));
       m_userPasswd = pwdnew;

       // 如果是最高权限的用户需要更新用户信息列表，对于其它权限的用户由于未显示用户信息列表，故不必更新
       if(m_userLevel==UserLevel::UserLevel_High)
       {
           updateModel();
       }
    }
    else
    {
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("修改密码失败！"));
    }

    ui->lineEditPwdOld->setText("");
    ui->lineEditPwdNew->setText("");
    ui->lineEditPwdMakesure->setText("");
    ui->groupBoxPasswdChange->setVisible(false);
}

void UserForm::visibleUsersetGroup()
{
    ui->groupBoxUserChange->setVisible(true);
}

void UserForm::on_pushButtonLogoutUser_clicked()
{
    MsgBoxEx *msgBox = new MsgBoxEx();
    connect(msgBox, SIGNAL(btnOkClicked()), this, SLOT(onBtnOkClickedLogout()));
    connect(msgBox, SIGNAL(btnCancelClicked()), this, SLOT(onBtnCancelClickedLogout()));
    msgBox->setMsgBoxMode(QString::fromLocal8Bit("此操作会将当前用户信息删除，且程序将立即退出，\n此操作不可逆，您确定注销当前用户吗？"), "", MsgBoxBtnType::MsgBoxBtnType_OkCancle);
}

void UserForm::onBtnOkClickedLogout()
{
    MsgBoxEx *msgBox = new MsgBoxEx();
    QSqlQuery query;
    query.prepare(QString("DELETE FROM AGVDB_INFO_USER WHERE user_name = '%1'").arg(m_userName));
    if(query.exec())
    {
       msgBox->setMsgBoxMode(QString::fromLocal8Bit("用户注销成功,程序将退出！"), 3000);
       QTimer::singleShot(3000, this, SLOT(onExitProgress()));
    }
    else
    {
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("用户注销失败！"));
    }
}

void UserForm::onExitProgress()
{
    qApp->quit();
}
void UserForm::onBtnCancelClickedLogout(){}

void UserForm::onClickedUserList(const QModelIndex&)
{
   QModelIndex index = ui->tableViewUserInfo->currentIndex();
   if (index.isValid())
   {
       QSqlRecord record = m_modelUser->record(index.row());
       QString user = record.value(0).toString();
       QString passwd = record.value(1).toString();
       QString level = record.value(2).toString();

       ui->lineEditUserName->setText(user);
       ui->lineEditUserPasswd->setText(passwd);
       ui->comboBoxLevel->setCurrentText(level);
   }
}

void UserForm::on_pushButtonUserAdd_clicked()
{
    MsgBoxEx *msgBox = new MsgBoxEx();
    QString user = ui->lineEditUserName->text();
    QString passwd = ui->lineEditUserPasswd->text();
    QString level = ui->comboBoxLevel->currentText();
    if(user.isEmpty() || passwd.isEmpty() || level.isEmpty())
    {
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("添加的用户信息都不可为空！"));
        return;
    }

    // 查询添加的用户是否存在
    QSqlQuery query;
    query.exec(QString("SELECT * FROM AGVDB_INFO_USER WHERE user_name = '%1'").arg(user));
    if(query.next())
    {
       msgBox->setMsgBoxMode(QString::fromLocal8Bit("用户 <%1> 已存在！").arg(user));
       return;
    }

    // 添加用户
    query.prepare(QString("INSERT INTO AGVDB_INFO_USER (user_name, user_passwd, user_level) VALUES ('%1', '%2', %3)").arg(user).arg(passwd).arg(level));
    if(query.exec())
    {
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("添加用户 <%1> 成功！").arg(user));
        updateModel();
    }
    else
    {
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("添加用户 <%1> 失败！").arg(user));
    }
}

void UserForm::on_pushButtonUserChange_clicked()
{
    MsgBoxEx *msgBox = new MsgBoxEx();
    QString user = ui->lineEditUserName->text();
    QString passwd = ui->lineEditUserPasswd->text();
    QString level = ui->comboBoxLevel->currentText();
    if(user.isEmpty())
    {
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("请选择要修改的用户！"));
        return;
    }
    if(passwd.isEmpty() || level.isEmpty())
    {
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("修改的用户信息都不可为空！"));
        return;
    }

    // 查询修改的用户是否存在
    QSqlQuery query;
    query.exec(QString("SELECT * FROM AGVDB_INFO_USER WHERE user_name = '%1'").arg(user));
    if(!query.next())
    {
       msgBox->setMsgBoxMode(QString::fromLocal8Bit("不存在将要修改的用户 <'%1'> ！").arg(user));
       return;
    }

    // 修改用户信息
    query.prepare(QString("UPDATE AGVDB_INFO_USER SET user_passwd = '%1', user_level = '%2'  WHERE user_name = '%3'")
                  .arg(passwd).arg(level).arg(user));
    if(query.exec())
    {
       msgBox->setMsgBoxMode(QString::fromLocal8Bit("修改用户 <%1> 信息成功！").arg(user));
       updateModel();
    }
    else
    {
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("修改用户 <%1> 信息失败！").arg(user));
    }
}

void UserForm::on_pushButtonUserDel_clicked()
{
    QModelIndex index = ui->tableViewUserInfo->currentIndex();
    MsgBoxEx *msgBox = new MsgBoxEx();
    if (index.isValid())
    {
        QSqlRecord record = m_modelUser->record(index.row());
        QString user = record.value(0).toString();

        // 管理员不可以删除自己，但可以注销
        if(user == m_userName)
        {
            msgBox->setMsgBoxMode(QString::fromLocal8Bit("最高权限用户不可删除自己，只可注销用户！"));
            return;
        }

        // 删除用户
        QSqlQuery query;
        query.prepare(QString("DELETE FROM AGVDB_INFO_USER WHERE user_name = '%1'").arg(user));
        if(query.exec())
        {
           msgBox->setMsgBoxMode(QString::fromLocal8Bit("删除用户 [%1] 成功！").arg(user));
           updateModel();
        }
        else
        {
            msgBox->setMsgBoxMode(QString::fromLocal8Bit("删除用户 [%1] 失败！").arg(user));
        }
    }
    else
    {
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("请选择要删除的用户！"));
    }
}
