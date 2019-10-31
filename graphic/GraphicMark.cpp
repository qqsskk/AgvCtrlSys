#include "graphic/GraphicMark.h"

quint32 GraphicMark::g_unWidth = 10;	// 宽
quint32 GraphicMark::g_unHeight = 10;	// 高

GraphicMark::GraphicMark(quint32 unNo)
{
    m_unNo = unNo;

    m_ptCenter = QPoint(0,0);
    m_ptPrepoint = QPoint(0, 0);
    m_ptLastpoint = QPoint(0, 0);
    m_ptLocal = QPoint(0, 0);
    m_bMove = false;
    m_bSelect = false;
}

GraphicMark::~GraphicMark()
{
}

quint32 GraphicMark::getNo()
{
    return m_unNo;
}

bool GraphicMark::isInside(QPoint ptWinpoint)
{
    QPoint ptWindow = vecToWin(m_ptCenter);
    QRect rect;
    rect.setLeft(ptWindow.x() - (g_unWidth / 2) * g_fScale);
    rect.setTop(ptWindow.y() - (g_unHeight / 2) * g_fScale);
    rect.setRight(rect.left() + g_unWidth * g_fScale);
    rect.setBottom(rect.top() + g_unHeight * g_fScale);

    rect.setLeft(ptWindow.x() - (g_unWidth/2)*g_fScale);

    return rect.contains(ptWinpoint);
}

bool GraphicMark::isSelected()
{
    return m_bSelect;
}

void GraphicMark::select(QPoint ptWinpoint)
{
    m_ptPrepoint = ptWinpoint;
    m_ptLastpoint = ptWinpoint;

    m_bMove = true;
    m_bSelect = true;

    return;
}

QCursor GraphicMark::drag(QPoint ptWinPoint)
{
    QCursor cursor;
    m_ptLastpoint = ptWinPoint;

    if (m_bMove)
    {
        m_ptCenter.rx() = (m_ptLastpoint.x() - m_ptPrepoint.x()) / g_fScale + m_ptLocal.x();
        m_ptCenter.ry() = -(m_ptLastpoint.y() - m_ptPrepoint.y()) / g_fScale + m_ptLocal.y();

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

void GraphicMark::confirm()
{
    m_bMove = false;

    m_ptCenter = Graphic::correctPoint(m_ptCenter);

    return;
}

void GraphicMark::cancel()
{
    m_ptCenter = m_ptLocal;
    m_bMove = false;
    m_bSelect = false;

    return;
}

QPoint GraphicMark::getCenterPoint()
{
    return m_ptCenter;
}

void GraphicMark::setCenterPoint(QPoint ptCenter)
{
    m_ptCenter = ptCenter;
    m_ptLocal = m_ptCenter;

    return;
}

void GraphicMark::draw(QPainter &painter)
{
    QPoint ptWindow = vecToWin(m_ptCenter);
    QRect rect;
    rect.setLeft(ptWindow.x() - (g_unWidth / 2) * g_fScale);
    rect.setTop(ptWindow.y() - (g_unHeight / 2) * g_fScale);
    rect.setRight(rect.left() + g_unWidth * g_fScale);
    rect.setBottom(rect.top() + g_unHeight * g_fScale);

    QPen pen;
    // 绘制选中背景
    if (m_bSelect)
    {
        painter.fillRect(QRect(rect.left(), rect.top(), rect.width(), rect.height()), QColor(Qt::red));
    }

    // 绘制外圈
    pen.setBrush(QColor(Qt::black));
    pen.setWidth(2);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    painter.setBrush(QBrush(Qt::white));
    painter.drawEllipse(QRect(rect.left(), rect.top(), rect.width(), rect.height()));

    // 绘制编号
    QFont font("Microsoft YaHei", (g_unWidth / 3) * g_fScale, QFont::Bold);
    painter.setFont(font);
    painter.drawText(rect.left(), rect.top(), rect.width(), rect.height(), Qt::AlignCenter, QString("%1").arg(m_unNo));

    return;
}
