#include "graphic/GraphicTrack.h"

float GraphicTrack::g_fWidth = 5.0f;

GraphicTrack::GraphicTrack(bool bArc)
{
    m_ptStart = QPoint(0,0);
    m_ptEnd = QPoint(0,0);
    m_bArc = bArc;

    m_ptPrepoint = QPoint(0, 0);
    m_ptLastpoint = QPoint(0, 0);
    m_ptLocal = QPoint(0, 0);
    m_bMove = false;
    m_bSelect = false;

    m_ptDistance = m_ptStart - m_ptEnd;
 }


GraphicTrack::~GraphicTrack()
{
}

void GraphicTrack::setStartPoint(QPoint ptStart)
{
    m_ptStart = ptStart;
    m_ptDistance = m_ptStart - m_ptEnd;
    return;
}

void GraphicTrack::setEndPoint(QPoint ptEnd)
{
    m_ptEnd = ptEnd;
    m_ptDistance = m_ptStart - m_ptEnd;
    return;
}

void GraphicTrack::setType(bool bArc)
{
    m_bArc = bArc;
    return;
}

QPoint GraphicTrack::getStartPoint()
{
    return m_ptStart;
}

QPoint GraphicTrack::getEndPoint()
{
    return m_ptEnd;
}

bool GraphicTrack::getType()
{
    return m_bArc;
}

bool GraphicTrack::isSelected()
{
    return m_bSelect;
}

void GraphicTrack::select(QPoint ptWinpoint)
{
    m_ptPrepoint = ptWinpoint;
    m_ptLastpoint = ptWinpoint;

    m_bMove = true;
    m_bSelect = true;

    return;
}

QCursor GraphicTrack::drag(QPoint ptWinPoint)
{
    QCursor cursor;
    m_ptLastpoint = ptWinPoint;

    if (m_bMove)
    {
        m_ptStart.setX((m_ptLastpoint.x() - m_ptPrepoint.x()) / g_fScale + m_ptLocal.x());
        m_ptStart.setY(-(m_ptLastpoint.y() - m_ptPrepoint.y()) / g_fScale + m_ptLocal.y());

        if (m_ptStart.x() < -g_sizeVector.width() / 2
            || m_ptStart.y() > g_sizeVector.height() / 2
            || m_ptStart.x() > g_sizeVector.width() / 2
            || m_ptStart.y() < -g_sizeVector.height() / 2)
        {
            m_ptStart = m_ptLocal;
        }

        if (m_ptEnd.x() < -g_sizeVector.width() / 2
            || m_ptEnd.y() > g_sizeVector.height() / 2
            || m_ptEnd.x() > g_sizeVector.width() / 2
            || m_ptEnd.y() < -g_sizeVector.height() / 2)
        {
            m_ptStart = m_ptLocal;
        }
        cursor = Qt::OpenHandCursor;
    }
    else
    {
        m_ptLocal = m_ptStart;
        cursor = Qt::ArrowCursor;
    }

    m_ptEnd = m_ptStart - m_ptDistance;

    return cursor;
}

void GraphicTrack::confirm()
{
    m_bMove = false;

    m_ptStart = Graphic::correctPoint(m_ptStart);
    m_ptEnd = m_ptStart - m_ptDistance;

    return;
}

void GraphicTrack::cancel()
{
    m_ptStart = m_ptLocal;
    m_ptEnd = m_ptStart - m_ptDistance;

    m_bMove = false;
    m_bSelect = false;

    return;
}

void GraphicTrack::draw(QPainter &painter)
{
    QPoint ptStartWin = vecToWin(m_ptStart);
    QPoint ptEndWin = vecToWin(m_ptEnd);

    // 默认画笔
    QPen pen;
    pen.setColor(QColor(Qt::black));
    pen.setWidth(g_fWidth * g_fScale);
    pen.setStyle(Qt::DashLine);
    painter.setPen(pen);

    // 弧
    if (m_bArc)
    {
        if ((ptEndWin.x() < ptStartWin.x() && ptEndWin.y() < ptStartWin.y()) ||
            (ptEndWin.x() > ptStartWin.x() && ptEndWin.y() < ptStartWin.y()) ||
            (ptEndWin.x() < ptStartWin.x() && ptEndWin.y() > ptStartWin.y()) ||
            (ptEndWin.x() > ptStartWin.x() && ptEndWin.y() > ptStartWin.y()))
        {
            QPainterPath path;
            path.moveTo(ptStartWin);
            path.cubicTo(ptStartWin, QPoint(ptEndWin.x(), ptStartWin.y()), ptEndWin);

            // 画黑线
            painter.drawPath(path);

            // 画黄线
            pen.setWidth((g_fWidth / 2) * g_fScale);
            pen.setColor(QColor(Qt::yellow));
            pen.setStyle(Qt::DashLine);
            painter.setPen(pen);
            painter.drawPath(path);
        }
        else
        {
           painter.drawLine(ptStartWin.x(), ptStartWin.y(), ptEndWin.x(), ptEndWin.y());
           pen.setWidth((g_fWidth / 2) * g_fScale);
           pen.setColor(QColor(Qt::yellow));
           pen.setStyle(Qt::DashLine);
           painter.setPen(pen);
           painter.drawLine(ptStartWin.x(), ptStartWin.y(), ptEndWin.x(), ptEndWin.y());
        }
    }
    // 直线
    else
    {
        painter.drawLine(ptStartWin.x(), ptStartWin.y(), ptEndWin.x(), ptEndWin.y());
        pen.setWidth((g_fWidth / 2) * g_fScale);
        pen.setColor(QColor(Qt::yellow));
        pen.setStyle(Qt::DashLine);
        painter.setPen(pen);
        painter.drawLine(ptStartWin.x(), ptStartWin.y(), ptEndWin.x(), ptEndWin.y());
    }

    return;
}

void GraphicTrack::setWidth(float fWidth)
{
    g_fWidth = fWidth;

    return;
}

float GraphicTrack::getWidth()
{
    return g_fWidth;
}

double GraphicTrack::radianToAngle(double dbRadian)
{
    double PI = 3.14159265;
    return dbRadian * 180 / PI;
}


double GraphicTrack::angleToRadian(double dbAngle)
{
    double PI = 3.14159265;
    return dbAngle * PI / 180;
}
