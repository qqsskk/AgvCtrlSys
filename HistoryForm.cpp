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
    m_model->setHeaderData(0, Qt::Horizontal,QString::fromLocal8Bit("取货点"));
    m_model->setHeaderData(1, Qt::Horizontal,QString::fromLocal8Bit("卸货点"));
    m_model->setHeaderData(2, Qt::Horizontal,QString::fromLocal8Bit("执行AGV"));
    m_model->setHeaderData(3, Qt::Horizontal,QString::fromLocal8Bit("任务状态"));
    m_model->setHeaderData(4, Qt::Horizontal,QString::fromLocal8Bit("任务发布时间"));
    m_model->setHeaderData(5, Qt::Horizontal,QString::fromLocal8Bit("任务执行时间"));
    m_model->setHeaderData(6, Qt::Horizontal,QString::fromLocal8Bit("任务完成时间"));
    m_model->setHeaderData(7, Qt::Horizontal,QString::fromLocal8Bit("备注"));
    m_model->setHeaderData(7, Qt::Horizontal,QString::fromLocal8Bit("备注"));
    ui->tableView->setTableModel(m_model);
}
