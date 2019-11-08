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
    //    // 使用JSON
    //    QString str("[	{\"a\":1,\"b\":0.1,\"c\":\"xx\"},\
    //    {\"a\":2,\"b\":0.2,\"c\":\"yy\"},\
    //      {\"a\":2,\"b\":0.2,\"c\":\"zz\"}]");
    //        QJsonParseError err;
    //        QJsonDocument jd = QJsonDocument::fromJson(str.toUtf8(), &err);
    //        QJsonArray ja = jd.array();
    //      CustomJsonModel *model = new CustomJsonModel(ja, this);
    //        ui->tableViewAgv->setTableModel(model);

    // 更新按钮
    ui->toolButtonUpdate->setStyleSheet("QToolButton{background:transparent; border-image:url(./res/icon/update_modules_normal.png)}\
                        QToolButton:hover{border-image:url(./res/icon/update_modules_normal.png)}\
                        QToolButton:pressed{border-image:url(./res/icon/update_modules_clicked.png);}");

    // 组合框
    ui->groupBox_1->setTitle(QString::fromLocal8Bit("AGV 类型"));
    ui->groupBox_2->setTitle(QString::fromLocal8Bit("待机队列信息"));
    ui->groupBox_3->setTitle(QString::fromLocal8Bit("工作站信息"));
    ui->groupBox_7->setTitle(QString::fromLocal8Bit("待机站信息"));
    ui->groupBox_5->setTitle(QString::fromLocal8Bit("充电站信息"));
    ui->groupBox_6->setTitle(QString::fromLocal8Bit("交通管制点信息"));
    ui->groupBox_8->setTitle(QString::fromLocal8Bit("AGV"));

    // AGV 类型
    m_itemModelAgvType = new QStandardItemModel(this);
    m_itemModelAgvType->setColumnCount(7);
    m_itemModelAgvType->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("类型名称"));
    m_itemModelAgvType->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("品牌"));
    m_itemModelAgvType->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("型号"));
    m_itemModelAgvType->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("最大速度"));
    m_itemModelAgvType->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("最大载重量"));
    m_itemModelAgvType->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("协议类型"));
    m_itemModelAgvType->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("动作码"));
    ui->tableViewAgvType->setModel(m_itemModelAgvType);

    // 待机队列
    m_itemModelRestQueue = new QStandardItemModel(this);
    m_itemModelRestQueue->setColumnCount(2);
    m_itemModelRestQueue->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("编号"));
    m_itemModelRestQueue->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("成员"));
    ui->tableViewResetQueue->setModel(m_itemModelRestQueue);

    // AGV
    m_itemModelAgv = new QStandardItemModel(this);
    m_itemModelAgv->setColumnCount(7);
    m_itemModelAgv->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("编号"));
    m_itemModelAgv->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("类型名称"));
    m_itemModelAgv->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("网络类型"));
    m_itemModelAgv->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("IP"));
    m_itemModelAgv->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("端口"));
    m_itemModelAgv->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("本地IP"));
    m_itemModelAgv->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("本地端口"));
    ui->tableViewAgv->setModel(m_itemModelAgv);

    // 工作站
    m_itemModelWorkStation = new QStandardItemModel(this);
    m_itemModelWorkStation->setColumnCount(4);
    m_itemModelWorkStation->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("编号"));
    m_itemModelWorkStation->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("名称"));
    m_itemModelWorkStation->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("坐标"));
    m_itemModelWorkStation->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("是否启用"));
    ui->tableViewWorkStation->setModel(m_itemModelWorkStation);

    // 待机站
    m_itemModelResetStation = new QStandardItemModel(this);
    m_itemModelResetStation->setColumnCount(3);
    m_itemModelResetStation->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("编号"));
    m_itemModelResetStation->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("名称"));
    m_itemModelResetStation->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("坐标"));
    ui->tableViewResetStation->setModel(m_itemModelResetStation);

    // 充电站
    m_itemModelCharger = new QStandardItemModel(this);
    m_itemModelCharger->setColumnCount(3);
    m_itemModelCharger->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("编号"));
    m_itemModelCharger->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("名称"));
    m_itemModelCharger->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("坐标"));
    ui->tableViewCharger->setModel(m_itemModelCharger);

    // 交通管制点
    m_itemModelTraffic = new QStandardItemModel(this);
    m_itemModelTraffic->setColumnCount(3);
    m_itemModelTraffic->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("管制点"));
    m_itemModelTraffic->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("锁定区域"));
    m_itemModelTraffic->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("比对管制点"));
    ui->tableViewTraffic->setModel(m_itemModelTraffic);

    // 加载组件信息
    loadJsonData("./res/set/modules.json");
}

void ModulesForm::clearAllTabelModel()
{
    m_itemModelAgvType->removeRows(0, m_itemModelAgvType->rowCount());
    m_itemModelRestQueue->removeRows(0, m_itemModelRestQueue->rowCount());
    m_itemModelAgv->removeRows(0, m_itemModelAgv->rowCount());
    m_itemModelWorkStation->removeRows(0, m_itemModelWorkStation->rowCount());
    m_itemModelResetStation->removeRows(0, m_itemModelResetStation->rowCount());
    m_itemModelCharger->removeRows(0, m_itemModelCharger->rowCount());
    m_itemModelTraffic->removeRows(0, m_itemModelTraffic->rowCount());
}

bool ModulesForm::loadJsonData(QString jsonFilePath)
{
    QFile file(jsonFilePath);
    if(!file.open(QFile::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"json open fail";
        return false;
    }
    QString data = file.readAll();
    file.close();

    QJsonObject obj;
    QJsonParseError jsonError;
    QJsonDocument doc(QJsonDocument::fromJson(data.toUtf8(), &jsonError));

    if(jsonError.error != QJsonParseError::NoError)
    {
        qDebug()<<"json error:"<<jsonError.error;
        return false;
    }

    if(doc.isObject())
    {
        obj = doc.object();
        QJsonValue value;
        value = obj.take("AGVType");
        updateTableAgvType(value.toObject());
        value = obj.take("RestQueue");
        updateTableRestQueue(value.toObject());
        value = obj.take("AGV");
        updateTableAgv(value.toObject());
        value = obj.take("WorkStation");
        updateTableWorkStation(value.toObject());
        value = obj.take("RestStation");
        updateTableResetStation(value.toObject());
        value = obj.take("ChargeStation");
        updateTableCharger(value.toObject());
        value = obj.take("Traffic");
        updateTableTraffic(value.toObject());
    }

    return true;
}

bool ModulesForm::updateTableAgvType(const QJsonObject &json)
{
    if (json.isEmpty())
    {
        return false;
    }

    QStringList listKey = json.keys();

    for (int i = 0; i < listKey.size(); ++i)
    {
        QString strType = listKey.at(i);                            // 类型名称
        QJsonObject obj = json.value(strType).toObject();
        QString strBrand = obj.value("Brand").toString();           // 品牌
        QString strVersion = obj.value("Version").toString();       // 型号
        double fMaxSpeed = obj.value("MaxSpeed").toDouble();        // 最大速度
        double fMaxWeight = obj.value("MaxWeight").toDouble();      // 最大载重量
        int nProtocol = obj.value("Protocol").toInt();              // 协议类型
        QJsonObject objAction = obj.value("Action").toObject();     // 动作名列表
        if (objAction.isEmpty())
        {
            continue;
        }
        QStringList listCode = objAction.keys();
        QString strCodeList;
        for (int j = 0; j < listCode.size(); ++j)
        {
            strCodeList += objAction.value(listCode.at(j)).toString();
            strCodeList += ";";
        }
        strCodeList.chop(1);
        int rowCount = m_itemModelAgvType->rowCount();
        m_itemModelAgvType->setItem(rowCount, 0, new QStandardItem(strType));
        m_itemModelAgvType->setItem(rowCount, 1, new QStandardItem(strBrand));
        m_itemModelAgvType->setItem(rowCount, 2, new QStandardItem(strVersion));
        m_itemModelAgvType->setItem(rowCount, 3, new QStandardItem(QString::number(fMaxSpeed)));
        m_itemModelAgvType->setItem(rowCount, 4, new QStandardItem(QString::number(fMaxWeight)));
        m_itemModelAgvType->setItem(rowCount, 5, new QStandardItem(QString::number(nProtocol)));
        m_itemModelAgvType->setItem(rowCount, 6, new QStandardItem(strCodeList));
    }

    return true;
}

bool ModulesForm::updateTableRestQueue(const QJsonObject &json)
{
    if (json.isEmpty())
    {
        return false;
    }

    QStringList listKey = json.keys();

    for (int i = 0; i < listKey.size(); ++i)
    {
        QString strQueueID = listKey.at(i);                             // 队列编号
        QJsonArray array = json.value(strQueueID).toArray();            // 队列成员
        QString strQueueMember;
        for(int j = 0; j < array.size(); j++)
        {
            int nMember = array.at(j).toInt();
            strQueueMember += QString::number(nMember);
            strQueueMember += ",";
        }
        strQueueMember.chop(1);
        int rowCount = m_itemModelRestQueue->rowCount();
        m_itemModelRestQueue->setItem(rowCount, 0, new QStandardItem(strQueueID));
        m_itemModelRestQueue->setItem(rowCount, 1, new QStandardItem(strQueueMember));
    }

    return true;
}

bool ModulesForm::updateTableAgv(const QJsonObject &json)
{
    if (json.isEmpty())
    {
        return false;
    }

    QStringList listKey = json.keys();

    for (int i = 0; i < listKey.size(); ++i)
    {
        QString strAgvID = listKey.at(i);                       // AGV编号
        QJsonObject obj = json.value(strAgvID).toObject();
        QString strType = obj.value("Type").toString();         // 类型名称
        bool bClient = obj.value("Client").toBool();            // 网络类型
        QString strClient;
        if(bClient)
        {
            strClient = QString::fromLocal8Bit("客户端");
        }
        else
        {
            strClient = QString::fromLocal8Bit("服务端");
        }
        QString strIP = obj.value("IP").toString();             // IP
        int nPort = obj.value("Port").toInt();                  // 端口
        QString strLocalIP = obj.value("LocalIP").toString();   // 本地IP
        int nLocalPort = obj.value("LocalPort").toInt();        // 本地端口

        int rowCount = m_itemModelAgv->rowCount();
        m_itemModelAgv->setItem(rowCount, 0, new QStandardItem(strAgvID));
        m_itemModelAgv->setItem(rowCount, 1, new QStandardItem(strType));
        m_itemModelAgv->setItem(rowCount, 2, new QStandardItem(strClient));
        m_itemModelAgv->setItem(rowCount, 3, new QStandardItem(strIP));
        m_itemModelAgv->setItem(rowCount, 4, new QStandardItem(QString::number(nPort)));
        m_itemModelAgv->setItem(rowCount, 5, new QStandardItem(strLocalIP));
        m_itemModelAgv->setItem(rowCount, 6, new QStandardItem(QString::number(nLocalPort)));
    }

    return true;
}

bool ModulesForm::updateTableWorkStation(const QJsonObject &json)
{
    if (json.isEmpty())
    {
        return false;
    }

    QStringList listKey = json.keys();

    for (int i = 0; i < listKey.size(); ++i)
    {
        QString strStationID = listKey.at(i);                   // 工作站编号
        QJsonObject obj = json.value(strStationID).toObject();
        QString strName = obj.value("Name").toString();         // 工作站名称
        int nLocation = obj.value("Location").toInt();          // 所在地标卡
        bool bUse = obj.value("Use").toBool();                  // 启用标识
        QString strUse;
        if(bUse)
        {
            strUse = QString::fromLocal8Bit("是");
        }
        else
        {
            strUse = QString::fromLocal8Bit("否");
        }

        int rowCount = m_itemModelWorkStation->rowCount();
        m_itemModelWorkStation->setItem(rowCount, 0, new QStandardItem(strStationID));
        m_itemModelWorkStation->setItem(rowCount, 1, new QStandardItem(strName));
        m_itemModelWorkStation->setItem(rowCount, 2, new QStandardItem(QString::number(nLocation)));
        m_itemModelWorkStation->setItem(rowCount, 3, new QStandardItem(strUse));
    }

    return true;
}

bool ModulesForm::updateTableResetStation(const QJsonObject &json)
{
    if (json.isEmpty())
    {
        return false;
    }

    QStringList listKey = json.keys();

    for (int i = 0; i < listKey.size(); ++i)
    {
        QString strStationID = listKey.at(i);                   // 待机站编号
        QJsonObject obj = json.value(strStationID).toObject();
        QString strName = obj.value("Name").toString();         // 工作站名称
        int nLocation = obj.value("Location").toInt();          // 所在地标卡

        int rowCount = m_itemModelResetStation->rowCount();
        m_itemModelResetStation->setItem(rowCount, 0, new QStandardItem(strStationID));
        m_itemModelResetStation->setItem(rowCount, 1, new QStandardItem(strName));
        m_itemModelResetStation->setItem(rowCount, 2, new QStandardItem(QString::number(nLocation)));
    }

    return true;
}

bool ModulesForm::updateTableCharger(const QJsonObject &json)
{
    if (json.isEmpty())
    {
        return false;
    }

    QStringList listKey = json.keys();

    for (int i = 0; i < listKey.size(); ++i)
    {
        QString strStationID = listKey.at(i);                   // 充电站编号
        QJsonObject obj = json.value(strStationID).toObject();
        QString strName = obj.value("Name").toString();         // 充电站名称
        int nLocation = obj.value("Location").toInt();          // 所在地标卡

        int rowCount = m_itemModelCharger->rowCount();
        m_itemModelCharger->setItem(rowCount, 0, new QStandardItem(strStationID));
        m_itemModelCharger->setItem(rowCount, 1, new QStandardItem(strName));
        m_itemModelCharger->setItem(rowCount, 2, new QStandardItem(QString::number(nLocation)));
    }

    return true;
}

bool ModulesForm::updateTableTraffic(const QJsonObject &json)
{
    if (json.isEmpty())
    {
        return false;
    }

    QStringList listKey = json.keys();

    for (int i = 0; i < listKey.size(); ++i)
    {
        QString strTrafficPoint = listKey.at(i);     // 管制点

        QJsonObject obj = json.value(strTrafficPoint).toObject();
        // 锁定区域
        QJsonArray arrayLock = obj.value("Lock").toArray();
        QString strLock;
        for(int j = 0; j < arrayLock.size(); j++)
        {
            int nLock = arrayLock.at(j).toInt();
            strLock += QString::number(nLock);
            strLock += ",";
        }
        strLock.chop(1);

        // 比对管制点列表
        QJsonArray arrayCompare = obj.value("Compare").toArray();
        QString strCompare;
        for(int k = 0; k < arrayCompare.size(); k++)
        {
            int nCompare = arrayCompare.at(k).toInt();
            strCompare += QString::number(nCompare);
            strCompare += ",";
        }
        strCompare.chop(1);

        int rowCount = m_itemModelTraffic->rowCount();
        m_itemModelTraffic->setItem(rowCount, 0, new QStandardItem(strTrafficPoint));
        m_itemModelTraffic->setItem(rowCount, 1, new QStandardItem(strLock));
        m_itemModelTraffic->setItem(rowCount, 2, new QStandardItem(strCompare));
    }

    return true;
}

void ModulesForm::on_toolButtonUpdate_clicked()
{
    MsgBoxEx *msgBox = new MsgBoxEx();
    connect(msgBox, SIGNAL(btnOkClicked()), this, SLOT(onBtnOkClicked()));
    connect(msgBox, SIGNAL(btnCancelClicked()), this, SLOT(onBtnCancelClicked()));
    msgBox->setMsgBoxMode(QString::fromLocal8Bit("确定要更新组件信息吗？"), "", MsgBoxBtnType::MsgBoxBtnType_OkCancle);
    delete msgBox;
}

void ModulesForm::onBtnOkClicked()
{
    QFile file("./res/set/modules.json");
    if (!file.exists())
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("未找到 ./res/set/modules.json 文件,请检查此文件是否在！"));
        delete msgBox;
        return;
    }

    clearAllTabelModel();

    if(! loadJsonData("./res/set/modules.json"))
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("更新组件信息失败！"));
        delete msgBox;
    }
    else
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("更新组件信息成功！"));
        delete msgBox;
    }
}

void ModulesForm::onBtnCancelClicked(){}
