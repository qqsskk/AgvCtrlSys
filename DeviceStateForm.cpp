#include "DeviceStateForm.h"
#include "ui_DeviceStateForm.h"

DeviceStateForm::DeviceStateForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceStateForm)
{
    ui->setupUi(this);

    ui->groupBox_1->setTitle(QString::fromLocal8Bit("AGV状态"));
    ui->groupBox_2->setTitle(QString::fromLocal8Bit("呼叫器状态"));

    m_modelAgv= new QSqlQueryModel(this);
    m_modelCaller= new QSqlQueryModel(this);

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
    // AGV
    m_modelAgv->setQuery(QString("SELECT ID,Type,Client,IP,Port,LocalIP,LocalPort,Connection,Cur,Target,StatusInfo,Battery,\
                                Speed,CargoInfo,ActionInfo,ErrorInfo FROM AGVDB_INFO_AGV"));
    m_modelAgv->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("编号"));
    m_modelAgv->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("类型名称"));
    m_modelAgv->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("网络模式"));
    m_modelAgv->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("IP"));
    m_modelAgv->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("端口"));
    m_modelAgv->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("本地IP"));
    m_modelAgv->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("本地端口"));
    m_modelAgv->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("连接状态"));
    m_modelAgv->setHeaderData(8, Qt::Horizontal, QString::fromLocal8Bit("当前地标卡"));
    m_modelAgv->setHeaderData(9, Qt::Horizontal, QString::fromLocal8Bit("终点地标卡"));
    m_modelAgv->setHeaderData(10, Qt::Horizontal, QString::fromLocal8Bit("状态"));
    m_modelAgv->setHeaderData(11, Qt::Horizontal, QString::fromLocal8Bit("电量"));
    m_modelAgv->setHeaderData(12, Qt::Horizontal, QString::fromLocal8Bit("速度"));
    m_modelAgv->setHeaderData(13, Qt::Horizontal, QString::fromLocal8Bit("载货信息"));
    m_modelAgv->setHeaderData(14, Qt::Horizontal, QString::fromLocal8Bit("动作信息"));
    m_modelAgv->setHeaderData(15, Qt::Horizontal, QString::fromLocal8Bit("异常信息"));
    ui->tableViewAgv->setTableModel(m_modelAgv);

    // 呼叫器
    m_modelCaller->setQuery(QString("SELECT ID,ScreamInfo,CallInfo,CancelInfo FROM AGVDB_INFO_CALLER"));
    m_modelCaller->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("编号"));
    m_modelCaller->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("急停信号状态"));
    m_modelCaller->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("呼叫信号状态"));
    m_modelCaller->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("取消信号状态"));
    ui->tableViewCaller->setTableModel(m_modelCaller);
}
