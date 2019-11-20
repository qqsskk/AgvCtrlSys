#include "ModulesForm.h"
#include "ui_ModulesForm.h"

ModulesForm::ModulesForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModulesForm)
{
    ui->setupUi(this);

    init();
}

ModulesForm::~ModulesForm()
{
    delete ui;
}

void ModulesForm::init()
{
    // 组合框
    ui->groupBox_1->setTitle(QString::fromLocal8Bit("AGV 类型"));
    ui->groupBox_4->setTitle(QString::fromLocal8Bit("AGV"));
    ui->groupBox_2->setTitle(QString::fromLocal8Bit("待机队列信息"));
    ui->groupBox_3->setTitle(QString::fromLocal8Bit("工作站信息"));
    ui->groupBox_7->setTitle(QString::fromLocal8Bit("待机站信息"));
    ui->groupBox_5->setTitle(QString::fromLocal8Bit("充电站信息"));
    ui->groupBox_6->setTitle(QString::fromLocal8Bit("交通管制点信息"));
    ui->groupBox_8->setTitle(QString::fromLocal8Bit("呼叫器信息"));


    loadModulesData();

}

void ModulesForm::loadModulesData()
{
    // AGV 类型
    m_itemModelAgvType = new QSqlQueryModel(this);
    m_itemModelAgvType->setQuery(QString("SELECT * FROM AGVDB_INFO_AGVTYPE"));
    m_itemModelAgvType->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("类型名称"));
    m_itemModelAgvType->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("品牌"));
    m_itemModelAgvType->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("型号"));
    m_itemModelAgvType->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("最大速度"));
    m_itemModelAgvType->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("最大载重量"));
    m_itemModelAgvType->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("协议类型"));
    m_itemModelAgvType->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("动作码"));
    ui->tableViewAgvType->setTableModel(m_itemModelAgvType);

    // AGV
    m_itemModelAgv = new QSqlQueryModel(this);
    m_itemModelAgv->setQuery(QString("SELECT ID,Type,Client,IP,Port,LocalIP,LocalPort FROM AGVDB_INFO_AGV"));
    m_itemModelAgv->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("编号"));
    m_itemModelAgv->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("类型名称"));
    m_itemModelAgv->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("网络模式"));
    m_itemModelAgv->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("IP"));
    m_itemModelAgv->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("端口"));
    m_itemModelAgv->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("本地IP"));
    m_itemModelAgv->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("本地端口"));
    ui->tableViewAgv->setTableModel(m_itemModelAgv);

    // 待机队列
    m_itemModelRestQueue = new QSqlQueryModel(this);
    m_itemModelRestQueue->setQuery(QString("SELECT * FROM AGVDB_INFO_RESTQUEUE"));
    m_itemModelRestQueue->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("编号"));
    m_itemModelRestQueue->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("成员"));
    ui->tableViewResetQueue->setTableModel(m_itemModelRestQueue);

    // 呼叫器
    m_itemModelCaller = new QStandardItemModel(this);
    m_itemModelCaller->setColumnCount(4);
    m_itemModelCaller->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("编号"));
    m_itemModelCaller->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("地址"));
    m_itemModelCaller->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("坐标"));
    m_itemModelCaller->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("是否启用"));
    ui->tableViewCaller->setModel(m_itemModelCaller);

    onUpdateCallerData();

    // 工作站
    m_itemModelWorkStation = new QSqlQueryModel(this);
    m_itemModelWorkStation->setQuery(QString("SELECT ID,Location,Name FROM AGVDB_INFO_WORK"));
    m_itemModelWorkStation->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("编号"));
    m_itemModelWorkStation->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("坐标"));
    m_itemModelWorkStation->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("名称"));
    ui->tableViewWorkStation->setTableModel(m_itemModelWorkStation);

    // 待机站
    m_itemModelResetStation = new QSqlQueryModel(this);
    m_itemModelResetStation->setQuery(QString("SELECT ID,Location,Name,Lock FROM AGVDB_INFO_RESET"));
    m_itemModelResetStation->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("编号"));
    m_itemModelResetStation->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("坐标"));
    m_itemModelResetStation->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("名称"));
    m_itemModelResetStation->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("锁定区域"));
    ui->tableViewResetStation->setTableModel(m_itemModelResetStation);

    // 充电站
    m_itemModelCharger = new QSqlQueryModel(this);
    m_itemModelCharger->setQuery(QString("SELECT ID,Location,Name FROM AGVDB_INFO_CHARGER"));
    m_itemModelCharger->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("编号"));
    m_itemModelCharger->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("坐标"));
    m_itemModelCharger->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("名称"));
    ui->tableViewCharger->setTableModel(m_itemModelCharger);

    // 交通管制点
    m_itemModelTraffic = new QSqlQueryModel(this);
    m_itemModelTraffic->setQuery(QString("SELECT * FROM AGVDB_INFO_TRAFFIC"));
    m_itemModelTraffic->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("管制点"));
    m_itemModelTraffic->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("锁定区域"));
    m_itemModelTraffic->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("比对管制点"));
    ui->tableViewTraffic->setTableModel(m_itemModelTraffic);
}

void ModulesForm::showItemTip(const QSqlQueryModel *model, const QModelIndex index)
{
    if(!index.isValid())
        return;

    QModelIndex _index = model->index(index.row(),index.column());
    QVariant data = model->data(_index);
    QString text = data.toString();
    if(text.isEmpty())
        return;
    QFont font("Microsoft YaHei", 10, QFont::Bold);
    QToolTip::setFont(font);
    QToolTip::showText(QCursor::pos(), text);
}

void ModulesForm::on_tableViewAgvType_clicked(const QModelIndex &index)
{
    showItemTip(m_itemModelAgvType, index);
}

void ModulesForm::on_tableViewAgv_clicked(const QModelIndex &index)
{
    showItemTip(m_itemModelAgv, index);
}

void ModulesForm::on_tableViewWorkStation_clicked(const QModelIndex &index)
{
    showItemTip(m_itemModelWorkStation, index);
}

void ModulesForm::on_tableViewResetStation_clicked(const QModelIndex &index)
{
    showItemTip(m_itemModelResetStation, index);
}

void ModulesForm::on_tableViewCharger_clicked(const QModelIndex &index)
{
    showItemTip(m_itemModelCharger, index);
}

void ModulesForm::on_tableViewResetQueue_clicked(const QModelIndex &index)
{
    showItemTip(m_itemModelRestQueue, index);
}

void ModulesForm::on_tableViewTraffic_clicked(const QModelIndex &index)
{
    showItemTip(m_itemModelTraffic, index);
}

void ModulesForm::onStateChanged(int state)
{
    int nCount = m_itemModelCaller->rowCount();
    for(int i=0; i<nCount; i++)
    {
        QModelIndex index;

        // ID
        index = m_itemModelCaller->index(i, 0);
        QString strID = m_itemModelCaller->data(index).toString();
        int nID = strID.toInt();

        // 是否启用
        index = m_itemModelCaller->index(i, 3);
        QCheckBox *checkBox = (QCheckBox*)ui->tableViewCaller->indexWidget(index);
        bool bEnable = false;
        if(checkBox->checkState())
        {
            bEnable = true;
        }

        emit callerEnable(nID, bEnable);
    }
}

void ModulesForm::onUpdateCallerData()
{
    m_itemModelCaller->removeRows(0, m_itemModelCaller->rowCount());
    QSqlQuery query;
    query.exec("SELECT ID,Address,Station,Enable FROM AGVDB_INFO_CALLER");
    while (query.next())
    {
        int nID = query.value(0).toInt();
        QString strAddress = query.value(1).toString();
        int nStation = query.value(2).toInt();
        bool bEnable = query.value(3).toBool();

        int rowCount = m_itemModelCaller->rowCount();
        m_itemModelCaller->setItem(rowCount, 0, new QStandardItem(QString::number(nID)));
        m_itemModelCaller->setItem(rowCount, 1, new QStandardItem(strAddress));
        m_itemModelCaller->setItem(rowCount, 2, new QStandardItem(QString::number(nStation)));

        QModelIndex index(m_itemModelCaller->index(rowCount, 3));
        QCheckBox *checkBox = new QCheckBox(this);
        if(bEnable)
        {
            checkBox->setChecked(true);
        }
        else
        {
            checkBox->setChecked(false);
        }
        ui->tableViewCaller->setIndexWidget(index, checkBox);
        connect(checkBox, SIGNAL(stateChanged(int)), this, SLOT(onStateChanged(int)));
    }
}

