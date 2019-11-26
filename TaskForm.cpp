#include "TaskForm.h"
#include "ui_TaskForm.h"

TaskForm::TaskForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskForm)
{
    ui->setupUi(this);

    m_model= new QSqlQueryModel(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onUpdateModel()));
    timer->start(1000);


    ui->groupBox->setTitle(QString::fromLocal8Bit("任务编辑"));

    ui->comboBoxTaskDetails->addItem(QString::fromLocal8Bit("运送毛坯料"));
    ui->comboBoxTaskDetails->addItem(QString::fromLocal8Bit("运送空托盘"));
    ui->comboBoxTaskDetails->addItem(QString::fromLocal8Bit("取回空托盘"));
    ui->comboBoxTaskDetails->setCurrentIndex(-1);

    QSqlQuery query;
    query.exec("SELECT Name FROM AGVDB_INFO_WORK");
    while (query.next())
    {
        ui->comboBoxTargetWork->addItem(query.value(0).toString());
    }
    ui->comboBoxTargetWork->setCurrentIndex(-1);
}

TaskForm::~TaskForm()
{
    delete ui;
}

void TaskForm::onUpdateModel()
{
    m_model->setQuery(QString("SELECT * FROM AGVDB_TASK_CURRENT"));
    m_model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("订单号"));
    m_model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("任务号"));
    m_model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("托盘码"));
    m_model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("目标工站"));
    m_model->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("任务内容"));
    m_model->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("执行者"));
    m_model->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("任务执行状态"));
    m_model->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("下单时间"));
    m_model->setHeaderData(8, Qt::Horizontal, QString::fromLocal8Bit("执行时间"));
    m_model->setHeaderData(9, Qt::Horizontal, QString::fromLocal8Bit("完成时间"));
    m_model->setHeaderData(10, Qt::Horizontal, QString::fromLocal8Bit("异常信息"));
    ui->tableView->setTableModel(m_model);
}

void TaskForm::on_pushButtonCreateTask_clicked()
{
    QString strWorkName = ui->comboBoxTargetWork->currentText();
    QString strTaskDetails = ui->comboBoxTaskDetails->currentText();

    if(strWorkName.isEmpty() || strTaskDetails.isEmpty())
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("创建任务的参数不完整！"));
        delete msgBox;
        return;
    }

    emit createTask(strWorkName, strTaskDetails);
}

void TaskForm::on_pushButtonDelTask_clicked()
{
    QString strTaskID = ui->lineEditTaskNum->text();
    if(strTaskID.isEmpty())
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("任务编号不可为空！"));
        delete msgBox;
        return;
    }
    QSqlQuery query;
    query.prepare(QString("DELETE FROM AGVDB_INFO_WORK WHERE task_id=%1").arg(strTaskID.toInt()));
    if(!query.exec())
    {
        QSqlError err = query.lastError();
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("删除任务失败！\n描述:%1").arg(err.text()));
        delete msgBox;
    }
}
