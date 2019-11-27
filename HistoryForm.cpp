#include "HistoryForm.h"
#include "ui_HistoryForm.h"

HistoryForm::HistoryForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HistoryForm)
{
    ui->setupUi(this);

    m_model= new QSqlQueryModel(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onUpdateModel()));
    timer->start(1000);
}

HistoryForm::~HistoryForm()
{
    delete ui;
}

void HistoryForm::onUpdateModel()
{  
    m_model->setQuery(QString("SELECT * FROM AGVDB_TASK_HISTORY"));
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
    ui->tableView->setTableModel(m_model, true);
}
