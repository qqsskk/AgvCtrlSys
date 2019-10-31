#include "graphic/GraphicStation.h"

quint32 GraphicStation::g_unWidth = 20;
quint32 GraphicStation::g_unHeight = 20;
QString GraphicStation::g_strPath = "./res/image/station.png";

GraphicStation::GraphicStation(quint32 unNo, quint32 unMark, QString strName)
{
    m_unNo = unNo;
    m_unMark = unMark;
    m_strName = strName;

    m_ptCenter = QPoint(0, 0);
    m_ptPrepoint = QPoint(0, 0);
    m_ptLastpoint = QPoint(0, 0);
    m_ptLocal = QPoint(0, 0);
    m_bMove = false;
    m_bSelect = false;

    m_pImage = new QImage(g_strPath);
}

GraphicStation::~GraphicStation()
{
}

quint32 GraphicStation::getNo()
{
    return m_unNo;
}

void GraphicStation::setName(QString cstrName)
{
    m_strName = cstrName;

    return;
}

QString GraphicStation::getName()
{
    return m_strName;
}

void GraphicStation::setMark(quint32 unMark)
{
    m_unMark = unMark;

    return;
}

quint32 GraphicStation::getMark()
{
    return m_unMark;;
}

void GraphicStation::setImage(QString cstrPath)
{
    g_strPath = cstrPath;

    return;
}

QString GraphicStation::getImage()
{
    return g_strPath;
}

bool GraphicStation::isInside(QPoint ptWinpoint)
{
    QPoint ptWindow = vecToWin(m_ptCenter);
    QRect rect;
    rect.setLeft(ptWindow.x() - (g_unWidth / 2) * g_fScale);
    rect.setTop(ptWindow.y() - (g_unHeight / 2) * g_fScale);
    rect.setRight(rect.left() + g_unWidth * g_fScale);
    rect.setBottom(rect.top() + g_unHeight * g_fScale);

    return rect.contains(ptWinpoint);
}

bool GraphicStation::isSelected()
{
    return m_bSelect;
}

void GraphicStation::select(QPoint ptWinpoint)
{
    m_ptPrepoint = ptWinpoint;
    m_ptLastpoint = ptWinpoint;

    m_bMove = true;
    m_bSelect = true;

    return;
}

QCursor GraphicStation::drag(QPoint ptWinPoint)
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

void GraphicStation::confirm()
{
    m_bMove = false;

    m_ptCenter = Graphic::correctPoint(m_ptCenter);

    return;
}

void GraphicStation::cancel()
{
    m_ptCenter = m_ptLocal;
    m_bMove = false;
    m_bSelect = false;

    return;
}

QPoint GraphicStation::getCenterPoint()
{
    return m_ptCenter;
}

void GraphicStation::setCenterPoint(QPoint ptCenter)
{
    m_ptCenter = ptCenter;
    m_ptLocal = m_ptCenter;

    return;
}

void GraphicStation::draw(QPainter &painter)
{
    QPoint ptWindow = vecToWin(m_ptCenter);
    QRect rect;
    rect.setLeft(ptWindow.x() - (g_unWidth / 2) * g_fScale);
    rect.setTop(ptWindow.y() - (g_unHeight / 2) * g_fScale);
    rect.setRight(rect.left() + g_unWidth * g_fScale);
    rect.setBottom(rect.top() + g_unHeight * g_fScale);

    // 绘制选中背景
    if (m_bSelect)
    {
        painter.fillRect(QRect(rect.left(), rect.top(), rect.width(), rect.height()), QColor(Qt::red));
    }

    // 绘制底图
    painter.drawImage(QRect(rect.left(), rect.top(), rect.width(), rect.height()), *m_pImage);

    // 绘制编号
    QFont font("Microsoft YaHei", (g_unWidth / 10) * g_fScale, QFont::Bold);
    painter.setFont(font);
    painter.drawText(QRectF(rect.left(), rect.top() - rect.width(), rect.width(), rect.height()), Qt::AlignCenter | Qt::AlignBottom, QString("NO.%1").arg(m_unNo));

    // 绘制名称
    painter.drawText(QRectF(rect.left(), rect.top() + rect.width(), rect.width(), rect.height()), Qt::AlignHCenter, QString::fromLocal8Bit("%1").arg(m_strName));

    return;
}
