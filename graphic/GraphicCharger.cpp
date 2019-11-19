#include "graphic/GraphicCharger.h"


quint32 GraphicCharger::g_unWidth = 20;
quint32 GraphicCharger::g_unHeight = 20;
QString GraphicCharger::g_strPath = "./res/image/charger.png";
QString GraphicCharger::g_strPower = "./res/image/power.png";

GraphicCharger::GraphicCharger(quint32 unNo, quint32 unMark)
{
    m_unNo = unNo;
    m_unMark = unMark;

    m_bPower = false;

    m_ptCenter = QPoint(0, 0);
    m_ptPrepoint = QPoint(0, 0);
    m_ptLastpoint = QPoint(0, 0);
    m_ptLocal = QPoint(0, 0);
    m_bMove = false;
    m_bSelect = false;

    m_pImageBg = new QImage(g_strPath);
    m_pImagePower = new QImage(g_strPower);
}


GraphicCharger::~GraphicCharger()
{
    if(m_pImageBg)
    {
        delete m_pImageBg;
        m_pImageBg = nullptr;
    }
    if(m_pImagePower)
    {
        delete m_pImagePower;
        m_pImagePower = nullptr;
    }
}

quint32 GraphicCharger::getNo()
{
    return m_unNo;
}

void GraphicCharger::setPower(bool bPower)
{
    m_bPower = bPower;

    return;
}

void GraphicCharger::setMark(quint32 unMark)
{
    m_unMark = unMark;

    return;
}

quint32 GraphicCharger::getMark()
{
    return m_unMark;
}

void GraphicCharger::setImage(QString strPath, QString strPower)
{
    g_strPath = strPath;
    g_strPower = strPower;

    return;
}

void GraphicCharger::getImage(QString & strPath, QString & strPower)
{
    strPath = g_strPath;
    strPower = g_strPower;

    return;
}

bool GraphicCharger::isSelected()
{
    return m_bSelect;
}

void GraphicCharger::select(QPoint ptWinpoint)
{
    m_ptPrepoint = ptWinpoint;
    m_ptLastpoint = ptWinpoint;

    m_bMove = true;
    m_bSelect = true;

    return;
}

QCursor GraphicCharger::drag(QPoint ptWinPoint)
{
    QCursor cursor;
    m_ptLastpoint = ptWinPoint;

    if (m_bMove)
    {
        m_ptCenter.setX((m_ptLastpoint.x() - m_ptPrepoint.x()) / g_fScale + m_ptLocal.x());
        m_ptCenter.setY(-(m_ptLastpoint.y() - m_ptPrepoint.y()) / g_fScale + m_ptLocal.y());

        if (m_ptCenter.x() < -g_sizeVector.width() / 2
            || m_ptCenter.y() > g_sizeVector.height() / 2
            || m_ptCenter.x() > g_sizeVector.width() / 2
            || m_ptCenter.y() < -g_sizeVector.height() / 2)
        {
            m_ptCenter = m_ptLocal;
        }
        cursor = Qt::OpenHandCursor;
    }
    else
    {
        m_ptLocal = m_ptCenter;
        cursor = Qt::ArrowCursor;
    }

    return cursor;
}

void GraphicCharger::confirm()
{
    m_bMove = false;

    m_ptCenter = Graphic::correctPoint(m_ptCenter);

    return;
}

void GraphicCharger::cancel()
{
    m_ptCenter = m_ptLocal;
    m_bMove = false;
    m_bSelect = false;

    return;
}

QPoint GraphicCharger::getCenterPoint()
{
    return m_ptCenter;
}

void GraphicCharger::setCenterPoint(QPoint ptCenter)
{
    m_ptCenter = ptCenter;
    m_ptLocal = m_ptCenter;

    return;
}

void GraphicCharger::draw(QPainter &painter)
{
    QPoint ptWindow = vecToWin(m_ptCenter);
    QRect rect;
    rect.setLeft(ptWindow.x() - (g_unWidth / 2) * g_fScale);
    rect.setTop(ptWindow.y() - (g_unHeight / 2) * g_fScale);
    rect.setRight(rect.left() + g_unWidth * g_fScale);
    rect.setBottom(rect.top() + g_unHeight * g_fScale);

    // 绘制底图
    painter.drawImage(QRect(rect.left(), rect.top(), rect.width(), rect.height()), *m_pImageBg);

    // 绘制充电标识符
    if (m_bPower)
    {
        painter.drawImage(QRect(rect.left(), rect.top(), rect.width(), rect.height()), *m_pImagePower);
    }

    // 绘制编号
    QFont font("Microsoft YaHei", (g_unWidth / 10) * g_fScale, QFont::Bold);
    painter.setFont(font);
    painter.drawText(QRectF(rect.left(), rect.top() - rect.width(), rect.width(), rect.height()), Qt::AlignCenter | Qt::AlignBottom, QString("NO.%1").arg(m_unNo));

    return;
}

