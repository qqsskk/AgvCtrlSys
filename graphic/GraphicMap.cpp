#include "graphic/GraphicMap.h"

GraphicMap::GraphicMap(QWidget *parent)
{
    m_pBg = new GraphicBg();

    loadMapElement();
}


GraphicMap::~GraphicMap()
{
    // 保存地图缩放比例和偏移量
    QSqlQuery query;
    query.exec("truncate table AGVDB_INFO_BACKGROUND");
    query.exec(QString("INSERT INTO AGVDB_INFO_BACKGROUND (Scale, OffsetX, OffsetY) VALUES (%1, %2, %3)")
               .arg(GraphicBg::getScale()).arg(GraphicBg::getOffset().x()).arg(GraphicBg::getOffset().y()));

    // 清空地图元素
    clearMapElement();
}

void GraphicMap::clearMapElement()
{
    m_mutex.lock();

    for (QMap<quint32, GraphicMark*>::iterator it = m_mapMark.begin(); it != m_mapMark.end(); )
    {
        delete it.value();
        it = m_mapMark.erase(it);
    }

    for (QMap<quint32, GraphicAgv*>::iterator it = m_mapAGV.begin(); it != m_mapAGV.end(); )
    {
        delete it.value();
        it = m_mapAGV.erase(it);
    }

    for (QMap<quint32, GraphicStation*>::iterator it = m_mapStation.begin(); it != m_mapStation.end(); )
    {
        delete it.value();
        it = m_mapStation.erase(it);
    }

    for (QMap<quint32, GraphicRest*>::iterator it = m_mapRest.begin(); it != m_mapRest.end(); )
    {
        delete it.value();
        it = m_mapRest.erase(it);
    }

    for (QMap<quint32, GraphicCharger*>::iterator it = m_mapCharger.begin(); it != m_mapCharger.end(); )
    {
        delete it.value();
        it = m_mapCharger.erase(it);
    }

    for (QList<GraphicTrack*>::iterator it = m_listTrack.begin(); it != m_listTrack.end(); )
    {
        delete *it;
        it = m_listTrack.erase(it);
    }

    if (m_pBg)
    {
        delete m_pBg;
        m_pBg = nullptr;
    }

    m_mutex.unlock();
}

QCursor GraphicMap::drag(QPoint ptWinPoint)
{
    QCursor hCursor;
    if (m_pBg)
    {
        hCursor = m_pBg->drag(ptWinPoint);
    }
    return hCursor;
}

void GraphicMap::cancel()
{
    if (m_pBg)
    {
        m_pBg->cancel();
    }
}

void GraphicMap::drawMap(QPainter &painter)
{
    if (m_mutex.try_lock() == false)
    {
        return;
    }

    if (m_pBg)
    {
        m_pBg->drawBg(painter);
    }

    for (QList<GraphicTrack*>::reverse_iterator it = m_listTrack.rbegin(); it != m_listTrack.rend(); it++)
    {
        (*it)->draw(painter);
    }

    for (QMap<quint32, GraphicMark*>::iterator it = m_mapMark.begin(); it != m_mapMark.end(); it++)
    {
        it.value()->draw(painter);
    }

    for (QMap<quint32, GraphicStation*>::iterator it = m_mapStation.begin(); it != m_mapStation.end(); it++)
    {
        it.value()->draw(painter);
    }

    for (QMap<quint32, GraphicRest*>::iterator it = m_mapRest.begin(); it != m_mapRest.end(); it++)
    {
        it.value()->draw(painter);
    }

    for (QMap<quint32, GraphicCharger*>::iterator it = m_mapCharger.begin(); it != m_mapCharger.end(); it++)
    {
        it.value()->draw(painter);
    }

    for (QMap<quint32, GraphicAgv*>::iterator it = m_mapAGV.begin(); it != m_mapAGV.end(); it++)
    {
        it.value()->draw(painter);
    }

    m_mutex.unlock();

    return;
}

bool GraphicMap::select(int nButton, QPoint point)
{
    if (nButton == BUTTONCTRL_LDOWN)
    {
        if (m_pBg)
        {
            m_pBg->select(point);
        }
    }
    return true;
}

bool GraphicMap::confirm(int nButton, QPoint point)
{
    if (nButton == BUTTONCTRL_LUP)
    {
        if (m_pBg)
        {
            m_pBg->confirm();
        }
    }
    return true;
}


void GraphicMap::wheel(bool bDire)
{
    m_mutex.lock();

    if (m_pBg)
    {
        m_pBg->scale(bDire);
    }

    m_mutex.unlock();

    return;
}

void GraphicMap::size(QRect rect)
{
    m_mutex.lock();

    Graphic::setClientRect(rect);

    m_mutex.unlock();
}

void GraphicMap::showAgv(quint32 unNo, QString strType, quint32 unCurMark, bool bRun, bool bUnVol, bool bObs, bool bError)
{
    if (m_mapMark.find(unCurMark) == m_mapMark.end())
    {
        return;
    }

    if(m_mapAGV.find(unNo) != m_mapAGV.end())
    {
        m_mapAGV[unNo]->setStatus(bRun, bUnVol, bObs, bError);
        m_mapAGV[unNo]->setCenterPoint(m_mapMark[unCurMark]->getCenterPoint());
        m_mapAGV[unNo]->isShow(true);
    }
    else
    {
        m_mapAGV[unNo] = new GraphicAgv(unNo, strType);
        m_mapAGV[unNo]->setStatus(bRun, bUnVol, bObs, bError);
        m_mapAGV[unNo]->setCenterPoint(m_mapMark[unCurMark]->getCenterPoint());
        m_mapAGV[unNo]->isShow(true);
    }
}


void GraphicMap::hideAgv(quint32 unNo)
{
    m_mutex.lock();

    if (m_mapAGV.find(unNo) != m_mapAGV.end())
    {
        m_mapAGV.erase(m_mapAGV.find(unNo));
    }

    m_mutex.unlock();
}


void GraphicMap::loadMapElement()
{
    clearMapElement();

    m_mutex.lock();

    if (m_pBg == nullptr)
    {
        m_pBg = new GraphicBg();
    }

    QSqlQuery query;
    // 读取地图元素信息
    // 背景
    query.exec("SELECT * FROM AGVDB_INFO_BACKGROUND");
    while (query.next())
    {
        float fScale = query.value(0).toFloat();    // 缩放比例
        int nOffsetX = query.value(1).toInt();      // 偏移量X
        int nOffsetY = query.value(2).toInt();      // 偏移量Y

        m_pBg->setScale(fScale);
        m_pBg->setOffset(QPoint(nOffsetX, nOffsetY));
    }

    // 磁轨
    query.exec("SELECT * FROM AGVDB_INFO_TRACK");
    while (query.next())
    {
        int nStartx = query.value(0).toInt();   // 起点X坐标
        int nStarty = query.value(1).toInt();   // 起点Y坐标
        int nEndx =  query.value(2).toInt();    // 终点X坐标
        int nEndy = query.value(3).toInt();     // 终点Y坐标
        bool bArc = query.value(4).toBool();    // 弧线标识

        GraphicTrack *pGraphicTrack = new GraphicTrack(bArc);
        pGraphicTrack->setStartPoint(QPoint(nStartx, nStarty));
        pGraphicTrack->setEndPoint(QPoint(nEndx, nEndy));
        m_listTrack.push_back(pGraphicTrack);
    }

    // 地标卡
    query.exec("SELECT * FROM AGVDB_INFO_MARK");
    while (query.next())
    {
        quint32 unID = query.value(0).toUInt();
        int nX = query.value(1).toInt();
        int nY = query.value(2).toInt();
        m_mapMark[unID] = new GraphicMark(unID);
        m_mapMark[unID]->setCenterPoint(QPoint(nX, nY));
    }

    // 工位
    query.exec("SELECT * FROM AGVDB_INFO_WORK");
    while (query.next())
    {
        quint32 unID = query.value(0).toUInt();         // 编号
        quint32 unLocation = query.value(1).toUInt();   // 所在地标
        QString strName = query.value(2).toString();    // 名称
        int x = query.value(3).toInt();                 // X坐标
        int y = query.value(4).toInt();                 // Y坐标

        m_mapStation[unID] = new GraphicStation(unID, unLocation, strName);
        m_mapStation[unID]->setCenterPoint(QPoint(x, y));
    }

    // 待机位
    query.exec("SELECT * FROM AGVDB_INFO_RESET");
    while (query.next())
    {
        quint32 unID = query.value(0).toUInt();         // 编号
        quint32 unLocation = query.value(1).toUInt();   // 所在地标
        //QString strName = query.value(2).toString();    // 名称
        int x = query.value(4).toInt();                 // X坐标
        int y = query.value(5).toInt();                 // Y坐标

        m_mapRest[unID] = new GraphicRest(unID, unLocation);
        m_mapRest[unID]->setCenterPoint(QPoint(x, y));
    }

    // 充电器
    query.exec("SELECT * FROM AGVDB_INFO_CHARGER");
    while (query.next())
    {
        quint32 unID = query.value(0).toUInt();         // 编号
        quint32 unLocation = query.value(1).toUInt();   // 所在地标
        //QString strName = query.value(2).toString();    // 名称
        int x = query.value(3).toInt();                 // X坐标
        int y = query.value(4).toInt();                 // Y坐标

        m_mapCharger[unID] = new GraphicCharger(unID, unLocation);
        m_mapCharger[unID]->setCenterPoint(QPoint(x, y));
    }

    m_mutex.unlock();
}

bool GraphicMap::updateMapRelateTable(QString xmlPath)
{
    // 读取xml文件
    TiXmlDocument xmlDoc;
    if (xmlDoc.LoadFile(xmlPath.toLatin1()) == false)
    {
        QString strError = QString("Loading xml file fail, details < Desc:%1, ID:%2, Row:%3, Col:%4 >")
         .arg(xmlDoc.ErrorDesc()).arg(xmlDoc.ErrorId()).arg(xmlDoc.ErrorRow()).arg(xmlDoc.ErrorCol());
        qDebug()<<strError;
        return false;
    }
    TiXmlElement *pXmlRoot = xmlDoc.FirstChildElement();
    if (pXmlRoot == nullptr || pXmlRoot->NoChildren())
    {
        return false;
    }
    TiXmlElement *pXmlElemt = pXmlRoot->FirstChildElement();
    if (pXmlElemt == nullptr)
    {
        return false;
    }

    QSqlQuery query;
    QString strSql;
    // 清空要更新的表
    QStringList clearTableList;
    clearTableList.append("truncate table AGVDB_INFO_TRAFFIC");
    clearTableList.append("truncate table AGVDB_INFO_RESTQUEUE");
    clearTableList.append("truncate table AGVDB_INFO_AGV");
    clearTableList.append("truncate table AGVDB_INFO_MARK");
    clearTableList.append("truncate table AGVDB_INFO_RESET");
    clearTableList.append("truncate table AGVDB_INFO_WORK");
    clearTableList.append("truncate table AGVDB_INFO_CHARGER");
    clearTableList.append("truncate table AGVDB_INFO_TRACK");
    clearTableList.append("truncate table AGVDB_INFO_BACKGROUND");
    for(int i=0; i<clearTableList.size(); i++)
    {
        query.exec(clearTableList[i]);
    }

    // 读取xml写入数据库
    while (pXmlElemt)
    {
        QString elemtName(pXmlElemt->Value()); // 元素名称
        // 背景
        if (elemtName == "Background")
        {
            TiXmlAttribute *pAttr = pXmlElemt->FirstAttribute();

            float fScale = 0.0f;	// 缩放比例
            int nOffsetX = 0;		// 偏移量X
            int nOffsetY = 0;		// 偏移量Y
            while (pAttr)
            {
                QString attrName(pAttr->Name());
                QString attrValue(pAttr->Value());

                if (attrName == "Scale")
                {
                    fScale = attrValue.toFloat();
                }
                else if (attrName == "OffsetX")
                {
                    nOffsetX = attrValue.toInt();
                }
                else if (attrName == "OffsetY")
                {
                    nOffsetY = attrValue.toInt();
                }
                pAttr = pAttr->Next();
            }
            strSql = QString("INSERT INTO AGVDB_INFO_BACKGROUND (Scale, OffsetX, OffsetY) VALUES (%1, %2, %3)").arg(fScale).arg(nOffsetX).arg(nOffsetY);
            query.exec(strSql);
        }
        // 地标卡
        else if (elemtName == "Mark")
        {
            TiXmlAttribute *pAttr = pXmlElemt->FirstAttribute();

            int nNO = 0;	// ID
            int nX = 0;		// X
            int nY = 0;		// Y
            while (pAttr)
            {
                QString attrName(pAttr->Name());
                QString attrValue(pAttr->Value());

                if (attrName == "No")
                {
                    nNO = attrValue.toInt();
                }
                else if (attrName == "X")
                {
                    nX = attrValue.toInt();
                }
                else if (attrName == "Y")
                {
                    nY = attrValue.toInt();
                }
                pAttr = pAttr->Next();
            }
            strSql = QString("INSERT INTO AGVDB_INFO_MARK (ID, X, Y) VALUES (%1, %2, %3)").arg(nNO).arg(nX).arg(nY);
            query.exec(strSql);
        }
        // 工位
        else if (elemtName == "Station")
        {
            TiXmlAttribute *pAttr = pXmlElemt->FirstAttribute();

            int nNO = 0;				// ID
            QString strName("");		// 名称
            int nMark = 0;				// 定位地标卡
            int nX = 0;					// X
            int nY = 0;					// Y
            while (pAttr)
            {
                QString attrName(pAttr->Name());
                QString attrValue(pAttr->Value());

                if (attrName == "No")
                {
                    nNO = attrValue.toInt();
                }
                else if (attrName == "Mark")
                {
                    nMark = attrValue.toInt();
                }
                else if (attrName == "Name")
                {
                    strName = attrValue;
                }
                else if (attrName == "X")
                {
                    nX = attrValue.toInt();
                }
                else if (attrName == "Y")
                {
                    nY = attrValue.toInt();
                }
                pAttr = pAttr->Next();
            }
            strSql = QString("INSERT INTO AGVDB_INFO_WORK (ID, Name, Mark, X, Y) VALUES (%1, '%2', %3, %4, %5)").arg(nNO).arg(strName).arg(nMark).arg(nX).arg(nY);
            query.exec(strSql);
        }
        // 待机位
        else if (elemtName == "Rest")
        {
            TiXmlAttribute *pAttr = pXmlElemt->FirstAttribute();

            int nNO = 0;				// ID
            int nMark = 0;				// 定位地标卡
            int nX = 0;					// X
            int nY = 0;					// Y
            while (pAttr)
            {
                QString attrName(pAttr->Name());
                QString attrValue(pAttr->Value());

                if (attrName == "No")
                {
                    nNO = attrValue.toInt();
                }
                else if (attrName == "Mark")
                {
                    nMark = attrValue.toInt();
                }
                else if (attrName == "X")
                {
                    nX = attrValue.toInt();
                }
                else if (attrName == "Y")
                {
                    nY = attrValue.toInt();
                }
                pAttr = pAttr->Next();
            }
            strSql = QString("INSERT INTO AGVDB_INFO_REST (ID, Location, Name, Lock, X, Y) VALUES (%1, %2, '%3', '%4', %5, %6)")
                    .arg(nNO).arg(nMark).arg(nX).arg(nY).arg(nX).arg(nY);
            query.exec(strSql);
        }
        // 充电器
        else if (elemtName == "Charger")
        {
            TiXmlAttribute *pAttr = pXmlElemt->FirstAttribute();

            int nNO = 0;				// ID
            int nMark = 0;				// 定位地标卡
            int nCtrl = 0;				// 受控充电器控制器编号
            int nX = 0;					// X
            int nY = 0;					// Y
            while (pAttr)
            {
                QString attrName(pAttr->Name());
                QString attrValue(pAttr->Value());

                if (attrName == "No")
                {
                    nNO = attrValue.toInt();
                }
                else if (attrName == "Mark")
                {
                    nMark = attrValue.toInt();
                }
                else if (attrName == "Ctrl")
                {
                    nCtrl = attrValue.toInt();
                }
                else if (attrName == "X")
                {
                    nX = attrValue.toInt();
                }
                else if (attrName == "Y")
                {
                    nY = attrValue.toInt();
                }
                pAttr = pAttr->Next();
            }
            strSql = QString("INSERT INTO AGVDB_INFO_CHARGER (ID, Mark, Ctrl, X, Y) VALUES (%1, %2, %3, %4, %5)").arg(nNO).arg(nMark).arg(nCtrl).arg(nX).arg(nY);
            query.exec(strSql);
        }
        // 磁条
        else if (elemtName == "Track")
        {
            TiXmlAttribute *pAttr = pXmlElemt->FirstAttribute();

            int nStartX = 0;			// 起始坐标X
            int nStartY = 0;			// 起始坐标Y
            int nEndX = 0;				// 终止坐标X
            int nEndY = 0;				// 终止坐标Y
            int nArc = 0;				// 磁轨类型
            while (pAttr)
            {
                QString attrName(pAttr->Name());
                QString attrValue(pAttr->Value());

                if (attrName == "StartX")
                {
                    nStartX = attrValue.toInt();
                }
                else if (attrName == "StartY")
                {
                    nStartY = attrValue.toInt();
                }
                else if (attrName == "EndX")
                {
                    nEndX = attrValue.toInt();
                }
                else if (attrName == "EndY")
                {
                    nEndY = attrValue.toInt();
                }
                else if (attrName == "Arc")
                {
                    nArc = attrValue.toInt();
                }
                pAttr = pAttr->Next();
            }
            strSql = QString("INSERT INTO AGVDB_INFO_TRACK (StartX, StartY, EndX, EndY, Arc) VALUES (%1, %2, %3, %4, %5)").arg(nStartX).arg(nStartY).arg(nEndX).arg(nEndY).arg(nArc);
            query.exec(strSql);
        }
        // AGV
        else if (elemtName == "AGV")
        {
            TiXmlAttribute *pAttr = pXmlElemt->FirstAttribute();

            int nNO = 0;				// ID
            QString strType = "";       // 类型
            QString strIP = "";         // IP
            int nPort = 0;				// 端口
            while (pAttr)
            {
                QString attrName(pAttr->Name());
                QString attrValue(pAttr->Value());

                if (attrName == "No")
                {
                    nNO = attrValue.toInt();
                }
                else if (attrName == "Type")
                {
                    strType = getAgvType(attrValue);
                }
                else if (attrName == "IP")
                {
                    strIP = attrValue;
                }
                else if (attrName == "Port")
                {
                    nPort = attrValue.toInt();
                }
                pAttr = pAttr->Next();
            }
            strSql = QString("INSERT INTO AGVDB_INFO_AGV (ID, Type, IP, Port) VALUES (%1, '%2', '%3', %4)").arg(nNO).arg(strType).arg(strIP).arg(nPort);
            query.exec(strSql);
        }

        // 交通管制
        else if (elemtName == "Traffic")
        {
            quint32 unID = 0;              // ID
            QString strCtrlMark = "";	// 管制点列
            QString strStopMark = "";	// 禁行点列

            // Traffic
            TiXmlAttribute *pAttr = pXmlElemt->FirstAttribute();
            while (pAttr)
            {
                QString attrName(pAttr->Name());
                QString attrValue(pAttr->Value());

                if (attrName == "No")
                {
                    unID = attrValue.toUInt();
                }
                // Ctrl/Stop
                TiXmlElement *pXmlArea = pXmlElemt->FirstChildElement(); // 区域元素
                while (pXmlArea)
                {
                    QString areaValue(pXmlArea->Value());
                    TiXmlAttribute *pAttr = pXmlArea->FirstAttribute(); // 属性
                    while (pAttr)
                    {
                        QString attrName(pAttr->Name());
                        QString attrValue(pAttr->Value());
                        if (attrName == "No")
                        {
                            if (areaValue == "Ctrl")
                            {
                                strCtrlMark += attrValue;	// 管制点列
                                strCtrlMark += ",";
                            }
                            else if (areaValue == "Stop")
                            {
                                strStopMark += attrValue;	// 禁行点列
                                strStopMark += ",";
                            }
                        }
                        pAttr = pAttr->Next();
                    }
                    pXmlArea = pXmlArea->NextSiblingElement();
                }
                // 保存交通管制区域
                strCtrlMark = strCtrlMark.mid(0, strCtrlMark.length() - 1);
                strStopMark = strStopMark.mid(0, strStopMark.length() - 1);
                strSql = QString("INSERT INTO AGVDB_INFO_TRAFFIC (ID, CtrlMark, StopMark) VALUES (%1, '%2', '%3')").arg(unID).arg(strCtrlMark).arg(strStopMark);
                query.exec(strSql);
                strCtrlMark = strStopMark = "";
                pAttr = pAttr->Next();
            }
        }
        // 待机队列
        else if (elemtName == "Queue")
        {
            quint32 unQueueID = 0;         // 队列ID
            quint32 unAreaID = 0;          // 区域ID
            quint32 unRestMark = 0 ;       // 待机点
            QString strStopMark = "";	// 禁行点列

            // Queue
            TiXmlAttribute *pAttr = pXmlElemt->FirstAttribute(); // 属性
            while (pAttr)
            {
                QString attrName(pAttr->Name());
                QString attrValue(pAttr->Value());

                if (attrName == "No")
                {
                    unQueueID = attrValue.toUInt();	// 队列ID
                }

                // Area
                TiXmlElement *pXmlArea = pXmlElemt->FirstChildElement(); // 区域元素
                while (pXmlArea)
                {
                    QString areaValue(pXmlArea->Value());
                    if (areaValue == "Area")
                    {
                        TiXmlAttribute *pAttr = pXmlArea->FirstAttribute(); // 属性
                        while (pAttr)
                        {
                            QString attrName(pAttr->Name());
                            QString attrValue(pAttr->Value());
                            if (attrName == "No")
                            {
                                unAreaID = attrValue.toUInt();	// 区域ID
                            }

                            // Rest/Stop
                            TiXmlElement *pXmlType = pXmlArea->FirstChildElement();  // 类型元素
                            while (pXmlType)
                            {
                                QString typeValue(pXmlType->Value());
                                TiXmlAttribute *pAttrMark = pXmlType->FirstAttribute(); // 属性
                                QString attrName(pAttrMark->Name());
                                QString attrValue(pAttrMark->Value());

                                if (typeValue == "Rest")
                                {
                                    if (attrName == "No")
                                    {
                                        unRestMark = attrValue.toUInt(); // 待机点
                                    }
                                }
                                else if (typeValue == "Stop")
                                {
                                    if (attrName == "No")
                                    {
                                        strStopMark += attrValue; // 禁行点列
                                        strStopMark += ",";
                                    }
                                }
                                pXmlType = pXmlType->NextSiblingElement();
                            }

                            // 保存待机队列
                            strStopMark = strStopMark.mid(0, strStopMark.length() - 1);
                            strSql = QString("INSERT INTO AGVDB_INFO_RESTQUEUE (Queue, Area, RestMark, StopMark) VALUES (%d, %d, %d, '%s')").arg(unQueueID).arg(unAreaID).arg(unRestMark).arg(strStopMark);
                            query.exec(strSql);
                            strStopMark = "";

                            pAttr = pAttr->Next();
                        }
                    }
                    pXmlArea = pXmlArea->NextSiblingElement();
                }
                pAttr = pAttr->Next();
            }
        }

        pXmlElemt = pXmlElemt->NextSiblingElement();
    }

    qDebug()<<"Update map related table succeeded";
    return true;
}


QString GraphicMap::getAgvType(QString shortType)
{
    QString agvType;
    if(shortType == "P")
    {
        agvType = QString::fromLocal8Bit("牵引式");
    }
    else if (shortType == "S")
    {
        agvType = QString::fromLocal8Bit("潜入式");
    }
    else if (shortType == "T")
    {
        agvType = QString::fromLocal8Bit("移载式");
    }
    else if (shortType == "F")
    {
        agvType = QString::fromLocal8Bit("叉车式");
    }
    else if (shortType == "A")
    {
        agvType = QString::fromLocal8Bit("机械手式");
    }
    else if (shortType == "L")
    {
        agvType = QString::fromLocal8Bit("激光式");
    }
    else
    {
        agvType = QString::fromLocal8Bit("未知式");
    }
    return agvType;
}
