#include "graphic/GraphicAgv.h"

quint32 GraphicAgv::g_unWidth = 20;
quint32 GraphicAgv::g_unHeight = 20;
QString GraphicAgv::g_strAGV = "./res/image/AGV.png";
QString GraphicAgv::g_strRun = "./res/image/run.png";
QString GraphicAgv::g_strUnVol = "./res/image/unvol.png";
QString GraphicAgv::g_strError = "./res/image/error.png";
QString GraphicAgv::g_strObs = "./res/image/obs.png";

GraphicAgv::GraphicAgv(quint32 unNo, QString strType)
{
    m_unNo = unNo;
    m_strType = strType;

    m_bRun = false;
    m_bUnVol = false;
    m_bError = false;
    m_bObs = false;

    m_bShow = false;

    m_ptCenter = QPoint(0,0);


    m_pImageAgv = new QImage(g_strAGV);
    m_pImageRun = new QImage(g_strRun);
    m_pImageUnvol = new QImage(g_strUnVol);
    m_pImageError = new QImage(g_strError);
    m_pImageObs = new QImage(g_strObs);
}


GraphicAgv::~GraphicAgv()
{
    if(m_pImageAgv)
    {
        delete m_pImageAgv;
        m_pImageAgv = nullptr;
    }
    if(m_pImageRun)
    {
        delete m_pImageRun;
        m_pImageRun = nullptr;
    }
    if(m_pImageUnvol)
    {
        delete m_pImageUnvol;
        m_pImageUnvol = nullptr;
    }
    if(m_pImageError)
    {
        delete m_pImageError;
        m_pImageError = nullptr;
    }
    if(m_pImageObs)
    {
        delete m_pImageObs;
        m_pImageObs = nullptr;
    }
}

void GraphicAgv::setType(QString strType)
{
    m_strType = strType;
    return;
}

quint32 GraphicAgv::getNo()
{
    return m_unNo;
}

QString GraphicAgv::getType()
{
    return m_strType;
}

void GraphicAgv::setImage(QString strAGV, QString strRun, QString strUnVol, QString strError, QString strObs)
{
    g_strAGV = strAGV;
    g_strRun = strRun;
    g_strUnVol = strUnVol;
    g_strError = strError;
    g_strObs = strObs;

    return;
}

void GraphicAgv::getImage(QString &strAGV, QString &strRun, QString &strUnVol, QString &strError, QString &strObs)
{
    strAGV = g_strAGV;
    strRun = g_strRun;
    strUnVol = g_strUnVol;
    strError = g_strError;
    strObs = g_strObs;

    return;
}

void GraphicAgv::setStatus(bool bRun, bool bUnVol, bool bObs, bool bError)
{
    m_bRun = bRun;
    m_bUnVol = bUnVol;
    m_bObs = bObs;
    m_bError = bError;
    return;
}

void GraphicAgv::isShow(bool bShow)
{
    m_bShow = bShow;

    return;
}

void GraphicAgv::setCenterPoint(QPoint ptCenter)
{
    m_ptCenter = ptCenter;

    return;
}

QPoint GraphicAgv::getCenterPoint()
{
    return m_ptCenter;
}

void GraphicAgv::draw(QPainter &painter)
{
    if (m_bShow == false)
    {
        return;
    }

    QPoint ptWindow = vecToWin(m_ptCenter);
    QRect rect;
    rect.setLeft(ptWindow.x() - (g_unWidth / 2) * g_fScale);
    rect.setTop(ptWindow.y() - (g_unHeight / 2) * g_fScale);
    rect.setRight(rect.left() + g_unWidth * g_fScale);
    rect.setBottom(rect.top() + g_unHeight * g_fScale);

    // 绘制AGV型号
    QString strType = m_strType;
    QString strName = QString("%1: %2").arg(strType).arg(m_unNo);
    QFont font("Microsoft YaHei", (g_unWidth / 10) * g_fScale, QFont::Bold);
    painter.setFont(font);
    painter.drawText(QRectF(rect.left(), rect.top() - rect.height(), rect.width(), rect.height()), Qt::AlignCenter | Qt::AlignBottom, QString("NO.%1").arg(m_unNo));

    // 绘制AGV贴图
    painter.drawImage(QRectF(rect.left(), rect.top(), rect.width(), rect.height()), *m_pImageAgv);

    // 绘制AGV状态
    QRectF rc(rect.left() + rect.width() / 4, rect.top() + rect.height() / 4, rect.width() / 2, rect.height() / 2);

    // 异常
    if (m_bError)
    {
        painter.drawImage(rc, *m_pImageError);
        return;
    }
    // 避障
    if (m_bObs)
    {
        painter.drawImage(rc, *m_pImageObs);
        return;
    }
    // 电量不足
    if (m_bUnVol)
    {
        painter.drawImage(rc, *m_pImageUnvol);
        return;
    }
    // 移动
    if (m_bRun)
    {
        painter.drawImage(rc, *m_pImageRun);
    }
    return;
}
