#include "graphic/GraphicBg.h"

GraphicBg::GraphicBg(QColor colorLine, float fWidth, QString strPath)
{
    m_colorLine = colorLine;
    m_fWidth = fWidth;
    m_strPath = strPath;
    m_bMove = false;
    m_ptPrepoint = QPoint(0,0);
    m_ptLastpoint = QPoint(0, 0);
    m_ptLocal = QPoint(0, 0);

    m_pImage = new QImage(m_strPath);
    m_pPen = new QPen(m_colorLine, m_fWidth);
}


GraphicBg::~GraphicBg()
{
    if(m_pImage)
    {
        delete m_pImage;
        m_pImage = nullptr;
    }
    if(m_pPen)
    {
        delete m_pPen;
        m_pPen = nullptr;
    }
}

void GraphicBg::setLine(QColor colorLine, float fWidth)
{
    QMutexLocker locker(&m_mutexLock);

    m_colorLine = colorLine;
    m_fWidth = fWidth;
    m_pPen = new QPen(m_colorLine, m_fWidth);

    return;
}

void GraphicBg::getLine(QColor &colorLine, float & fWidth)
{
    colorLine = m_colorLine;
    fWidth = m_fWidth;

    return;
}

void GraphicBg::setImage(QString strPath)
{
    QMutexLocker locker(&m_mutexLock);

    m_strPath = strPath;
    m_pImage = new QImage(m_strPath);

    return;
}

QString GraphicBg::getImage()
{
    return m_strPath;
}

void GraphicBg::scale(bool bShrink)
{
    if (bShrink)
    {
        if (g_fScale >= MIN_SCALE)
        {
            g_fScale -= 0.1f;
        }
    }
    else
    {
        if (g_fScale <= MAX_SCALE)
        {
            g_fScale += 0.1f;
        }
    }

    if (g_fScale == 0)
    {
        if (bShrink)
        {
            g_fScale -= 0.1f;
        }
        else
        {
            g_fScale += 0.1f;
        }
    }

    return;
}

void GraphicBg::reset()
{
    g_fScale = DEFALUT_SCALE;
    g_ptOffset = QPoint(0, 0);

    return;
}

QCursor GraphicBg::drag(QPoint ptWinPoint)
{
    QCursor cursor;
    m_ptLastpoint = ptWinPoint;

    if (m_bMove)
    {
        g_ptOffset = m_ptLastpoint - m_ptPrepoint + m_ptLocal;

        QPoint ptLeftTop = winToVec(QPoint(g_rcClient.left(), g_rcClient.top()));
        QPoint ptRightBottom = winToVec(QPoint(g_rcClient.right(), g_rcClient.bottom()));

        if (ptLeftTop.x() < -g_sizeVector.width() / 2
            || ptLeftTop.y() > g_sizeVector.height() / 2
            || ptRightBottom.x() > g_sizeVector.width() / 2
            || ptRightBottom.y() < -g_sizeVector.height() / 2)
        {
            g_ptOffset = m_ptLocal;
        }
        cursor = Qt::OpenHandCursor;
    }
    else
    {
        m_ptLocal = g_ptOffset;
        cursor = Qt::ArrowCursor;
    }

    return cursor;
}

void GraphicBg::select(QPoint ptWinPoint)
{
    m_ptPrepoint = ptWinPoint;
    m_ptLastpoint = ptWinPoint;

    m_bMove = true;

    return;
}

void GraphicBg::cancel()
{
    g_ptOffset = m_ptLocal;

    m_bMove = false;

    return;
}

void GraphicBg::confirm()
{
    m_bMove = false;

    return;
}

void GraphicBg::drawBg(QPainter &painter)
{
    if (m_mutexLock.try_lock() == false)
    {
        return;
    }

    painter.drawImage(QRectF(g_rcClient.left(), g_rcClient.top(), g_rcClient.width(), g_rcClient.height()), *m_pImage);

    m_mutexLock.unlock();

    return;
}

void GraphicBg::drawSubline(QPainter &painter)
{
    if (m_mutexLock.try_lock() == false)
    {
        return;
    }

    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setColor(QColor(m_colorLine));
    pen.setWidth(m_fWidth);
    painter.setPen(pen);


    QPoint cptStart = QPoint(0,0);	// 起点坐标
    QPoint cptEnd = QPoint(0,0);	// 终点坐标

    QPoint ptStart = QPoint(0, 0);	// 起点坐标
    QPoint ptEnd = QPoint(0, 0);	// 终点坐标

    // 绘制实线
    // 从左向右绘制实线(竖线)
    for (int x = -g_sizeVector.width() / 2; x <= g_sizeVector.width() / 2; x += g_unDistance * 10)
    {
        cptStart = vecToWin(QPoint(x, g_sizeVector.height() / 2));
        cptEnd = vecToWin(QPoint(x, -g_sizeVector.height() / 2));
        ptStart.setX(cptStart.x());
        ptStart.setY(cptStart.y());
        ptEnd.setX(cptEnd.x());
        ptEnd.setY(cptEnd.y());

        ptStart.setY(ptStart.y() < g_rcClient.top() ? g_rcClient.top() : ptStart.y());
        ptEnd.setY(ptEnd.y() > g_rcClient.bottom() ? g_rcClient.bottom() - 1 : ptEnd.y());

        if (g_rcClient.contains(QPoint(ptStart.x(), ptStart.y())) && g_rcClient.contains(QPoint(ptEnd.x(), ptEnd.y())))
        {
            painter.drawLine(ptStart, ptEnd);
        }
    }

    // 由上至下绘制实线(横线)
    for (int y = g_sizeVector.width(); y >= -g_sizeVector.height() / 2; y -= g_unDistance*10)
    {
        cptStart = vecToWin(QPoint(-g_sizeVector.width() / 2, y));
        cptEnd = vecToWin(QPoint(g_sizeVector.width() / 2, y));
        ptStart.setX(cptStart.x());
        ptStart.setY(cptStart.y());
        ptEnd.setX(cptEnd.x());
        ptEnd.setY(cptEnd.y());

        ptStart.setX(ptStart.x() < g_rcClient.left() ? g_rcClient.left() : ptStart.x());
        ptEnd.setX(ptEnd.x() > g_rcClient.right() ? g_rcClient.right() - 1 : ptEnd.x());

        if (g_rcClient.contains(QPoint(ptStart.x(), ptStart.y())) && g_rcClient.contains(QPoint(ptEnd.x(), ptEnd.y())))
        {
            painter.drawLine(ptStart, ptEnd);
        }
    }

    // 绘制虚线
    if (g_fScale < 1)
    {
        m_mutexLock.unlock();

        return;
    }

    pen.setStyle(Qt::DotLine);
    pen.setWidth(1.0f);
    painter.setPen(pen);

    int nCount = 0;

    // 从左向右绘制虚线(竖线)
    for (int x = -g_sizeVector.width() / 2; x <= g_sizeVector.width() / 2; x += g_unDistance, nCount++)
    {
        if (nCount % 10 == 0)
        {
            continue;
        }

        cptStart = vecToWin(QPoint(x, g_sizeVector.height() / 2));
        cptEnd = vecToWin(QPoint(x, -g_sizeVector.height() / 2));
        ptStart.setX(cptStart.x());
        ptStart.setY(cptStart.y());
        ptEnd.setX(cptEnd.x());
        ptEnd.setY(cptEnd.y());

        ptStart.setY(ptStart.y() < g_rcClient.top() ? g_rcClient.top() : ptStart.y());
        ptEnd.setY(ptEnd.y() > g_rcClient.bottom() ? g_rcClient.bottom() - 1 : ptEnd.y());

        if (g_rcClient.contains(QPoint(ptStart.x(), ptStart.y())) && g_rcClient.contains(QPoint(ptEnd.x(), ptEnd.y())))
        {
            painter.drawLine(ptStart, ptEnd);
        }
    }

    nCount = 0;

    // 由上至下绘制虚线(横线)
    for (int y = g_sizeVector.width(); y >= -g_sizeVector.height() / 2; y -= g_unDistance, nCount++)
    {
        if (nCount % 10 == 0)
        {
            continue;
        }
        cptStart = vecToWin(QPoint(-g_sizeVector.width() / 2, y));
        cptEnd = vecToWin(QPoint(g_sizeVector.width() / 2, y));
        ptStart.setX(cptStart.x());
        ptStart.setY(cptStart.y());
        ptEnd.setX(cptEnd.x());
        ptEnd.setY(cptEnd.y());

        ptStart.setX(ptStart.x() < g_rcClient.left() ? g_rcClient.left() : ptStart.x());
        ptEnd.setX(ptEnd.x() > g_rcClient.right() ? g_rcClient.right() - 1 : ptEnd.x());

        if (g_rcClient.contains(QPoint(ptStart.x(), ptStart.y())) && g_rcClient.contains(QPoint(ptEnd.x(), ptEnd.y())))
        {
            painter.drawLine(ptStart, ptEnd);
        }
    }

    m_mutexLock.unlock();

    return;
}

void GraphicBg::drawSubpoint(QPainter &painter)
{
    if (m_mutexLock.try_lock() == false)
    {
        return;
    }

    QPoint cptVector = QPoint(0, 0);	// 矢量坐标
    QString strText;


    QFont font("Microsoft YaHei", 10.0f, QFont::Bold);
    painter.setFont(font);

    // 绘制实线坐标
    // 绘制X坐标(实线)
    for (int x = g_rcClient.left(); x <= g_rcClient.right(); x++)
    {
        cptVector = winToVec(QPoint(x, g_rcClient.top()));

        if (qAbs(cptVector.x()) % (g_unDistance * 10) == 0 && qAbs(cptVector.x()) < g_sizeVector.width() / 2)
        {
            painter.drawText(QRectF(x + m_fWidth, g_rcClient.top(), 50, 15), Qt::AlignCenter, QString("%1").arg(cptVector.x()));
        }
    }

    // 绘制Y坐标(实线)
    for (int y = g_rcClient.top(); y <= g_rcClient.bottom(); y++)
    {
        cptVector = winToVec(QPoint(g_rcClient.left(), y));

        if (abs(cptVector.y()) % (g_unDistance * 10) == 0 && abs(cptVector.y()) < g_sizeVector.height() / 2)
        {
            painter.drawText(QRectF(g_rcClient.left(), y + m_fWidth, 50, 15), Qt::AlignCenter, QString("%1").arg(cptVector.y()));
        }
    }

    // 绘制虚线坐标
    if (g_fScale < 1)
    {
        m_mutexLock.unlock();
        return;
    }

    // 绘制X坐标(实线)
    for (int x = g_rcClient.left(); x <= g_rcClient.right(); x++)
    {
        cptVector = winToVec(QPoint(x, g_rcClient.top()));

        // 跳过实线
        if (qAbs(cptVector.x()) % (g_unDistance * 10) == 0)
        {
            continue;
        }

        if (qAbs(cptVector.x()) % (g_unDistance) == 0 && abs(cptVector.x()) < g_sizeVector.width() / 2)
        {
            painter.drawText(QRectF(x + m_fWidth, g_rcClient.top(), 50, 15), Qt::AlignCenter, QString("%1").arg(cptVector.x()));
        }
    }
    // 绘制Y坐标(实线)
    for (int y = g_rcClient.top(); y <= g_rcClient.bottom(); y++)
    {
        cptVector = winToVec(QPoint(g_rcClient.left(), y));

        // 跳过实线
        if (qAbs(cptVector.y()) % (g_unDistance * 10) == 0 && abs(cptVector.y()) < g_sizeVector.height() / 2)
        {
            continue;
        }

        if (qAbs(cptVector.y()) % (g_unDistance) == 0)
        {
            painter.drawText(QRectF(g_rcClient.left(), y + m_fWidth, 50, 15), Qt::AlignCenter, QString("%1").arg(cptVector.y()));
        }
    }

    m_mutexLock.unlock();

    return;
}
