#include "graphic/GraphicRest.h"

quint32 GraphicRest::g_unWidth = 20;
quint32 GraphicRest::g_unHeight = 20;
QString GraphicRest::g_strPath = "./res/image/rest.png";

GraphicRest::GraphicRest(quint32 unNo, quint32 unMark)
{
    m_unNo = unNo;
    m_unMark = unMark;

    m_ptCenter = QPoint(0, 0);
    m_ptPrepoint = QPoint(0, 0);
    m_ptLastpoint = QPoint(0, 0);
    m_ptLocal = QPoint(0, 0);
    m_bMove = false;
    m_bSelect = false;

    m_pImage = new QImage(g_strPath);
}


GraphicRest::~GraphicRest()
{
    if(m_pImage)
    {
        delete m_pImage;
        m_pImage = nullptr;
    }
}

quint32 GraphicRest::getNo()
{
    return m_unNo;
}

void GraphicRest::setMark(quint32 unMark)
{
    m_unMark = unMark;

    return;
}

quint32 GraphicRest::getMark()
{
    return m_unMark;
}

void GraphicRest::setImage(QString strPath)
{
    g_strPath = strPath;

    return;
}

QString GraphicRest::getImage()
{
    return g_strPath;
}

bool GraphicRest::isInside(QPoint ptWinpoint)
{
    QPoint ptWindow = vecToWin(m_ptCenter);
    QRect rect;
    rect.setLeft(ptWindow.x() - (g_unWidth / 2) * g_fScale);
    rect.setTop(ptWindow.y() - (g_unHeight / 2) * g_fScale);
    rect.setRight(rect.left() + g_unWidth * g_fScale);
    rect.setBottom(rect.top() + g_unHeight * g_fScale);

    return rect.contains(ptWinpoint);
}

bool GraphicRest::isSelected()
{
    return m_bSelect;
}

void GraphicRest::select(QPoint ptWinpoint)
{
    m_ptPrepoint = ptWinpoint;
    m_ptLastpoint = ptWinpoint;

    m_bMove = true;
    m_bSelect = true;

    return;
}

QCursor GraphicRest::drag(QPoint ptWinPoint)
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

void GraphicRest::confirm()
{
    m_bMove = false;

    m_ptCenter = Graphic::correctPoint(m_ptCenter);

    return;
}

void GraphicRest::cancel()
{
    m_ptCenter = m_ptLocal;
    m_bMove = false;
    m_bSelect = false;

    return;
}

QPoint GraphicRest::getCenterPoint()
{
    return m_ptCenter;
}

void GraphicRest::setCenterPoint(QPoint ptCenter)
{
    m_ptCenter = ptCenter;
    m_ptLocal = m_ptCenter;

    return;
}

void GraphicRest::draw(QPainter &painter)
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

    return;
}
