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

bool GraphicTrack::isInside(QPoint ptWinpoint)
{
    QPoint ptStartWin, ptEndWin;
    ptStartWin = vecToWin(m_ptStart);
    ptEndWin = vecToWin(m_ptEnd);

    double dbW = g_fWidth * g_fScale; // 检测半径:宽
    double dbH = g_fWidth * g_fScale; // 检测半径:高

    if (m_bArc)
    {
        QRectF rcTemp;
        rcTemp.setWidth((qreal)qAbs(ptStartWin.x() - ptEndWin.x()) * 2);
        rcTemp.setHeight((qreal)qAbs(ptStartWin.y() - ptEndWin.y()) * 2);

        double nLr = (rcTemp.width() >= rcTemp.height() ? rcTemp.width() : rcTemp.height()) / 2; // 长半轴
        double nSr = (rcTemp.width() <= rcTemp.height() ? rcTemp.width() : rcTemp.height()) / 2; // 短半轴

        // 中心坐标
        QPoint ptMid(0,0);

        // 角度值
        double x = 0;
        double y = 0;
        double a = 0;

         //! [1]
        if (ptEndWin.x() < ptStartWin.x() && ptEndWin.y() < ptStartWin.y())
        {
            rcTemp.setX((qreal)ptEndWin.x());
            rcTemp.setY((qreal)ptEndWin.y() - rcTemp.height() / 2);

            ptMid.setX(rcTemp.x() + rcTemp.width() / 2);
            ptMid.setY(rcTemp.y() + rcTemp.height() / 2);

            for (float i = 0; i <= 90; i += 0.1)
            {
                a = tan(angleToRadian(i));

                // 椭圆焦点在X轴 x^2/a^2+y^2/b^2=1，(a>b>0)；
                if (ptMid.x() + nSr < rcTemp.x() + rcTemp.width())
                {
                    x = sqrt((nLr*nLr) * (nSr*nSr) / ((nSr*nSr) + ((nLr*nLr) * (a * a))));
                }
                // 椭圆焦点在Y轴 y^2/a^2+x^2/b^2=1，(a>b>0)；
                else
                {
                    x = sqrt((nLr*nLr) * (nSr*nSr) / (((nSr*nSr) * (a * a)) + (nLr*nLr)));
                }

                y = a * x;

                x = ptMid.x() - x;
                y = ptMid.y() + y;

                QRectF rc(x - dbW / 2, y - dbH / 2, dbW, dbH);

                if (rc.contains(QPoint(ptWinpoint.x(), ptWinpoint.y())))
                {
                    return true;
                }
            }
        }
        //! [1]
        //! [2]
        else if (ptEndWin.x() > ptStartWin.x() && ptEndWin.y() < ptStartWin.y())
        {
            rcTemp.setX((qreal)ptStartWin.x() - rcTemp.width() / 2);
            rcTemp.setY((qreal)ptEndWin.y() - rcTemp.height() / 2);

            ptMid.setX(rcTemp.x() + rcTemp.width() / 2);
            ptMid.setY(rcTemp.y() + rcTemp.height() / 2);

            for (float i = 0; i <= 90; i += 0.1)
            {
                a = tan(angleToRadian(i));

                // 椭圆焦点在X轴 x^2/a^2+y^2/b^2=1，(a>b>0)；
                if (ptMid.x() + nSr < rcTemp.x() + rcTemp.width())
                {
                    x = sqrt((nLr*nLr) * (nSr*nSr) / ((nSr*nSr) + ((nLr*nLr) * (a * a))));
                }
                // 椭圆焦点在Y轴 y^2/a^2+x^2/b^2=1，(a>b>0)；
                else
                {
                    x = sqrt((nLr*nLr) * (nSr*nSr) / (((nSr*nSr) * (a * a)) + (nLr*nLr)));
                }

                y = a * x;

                x = ptMid.x() + x;
                y = ptMid.y() + y;

                QRectF rc(x - dbW / 2, y - dbH / 2, dbW, dbH);

                if (rc.contains(QPoint(ptWinpoint.x(), ptWinpoint.y())))
                {
                    return true;
                }
            }
        }
        //! [2]
        //! [3]
        else if (ptEndWin.x() < ptStartWin.x() && ptEndWin.y() > ptStartWin.y())
        {
            rcTemp.setX((qreal)ptEndWin.x());
            rcTemp.setY((qreal)ptStartWin.y());

//            ptMid.rx() = rcTemp.x() + rcTemp.width() / 2;
//            ptMid.ry() = rcTemp.y() + rcTemp.height() / 2;
            ptMid.setX(rcTemp.x() + rcTemp.width() / 2);
            ptMid.setY(rcTemp.y() + rcTemp.height() / 2);

            for (float i = 0; i <= 90; i += 0.1)
            {
                a = tan(angleToRadian(i));

                // 椭圆焦点在X轴 x^2/a^2+y^2/b^2=1，(a>b>0)；
                if (ptMid.x() + nSr < rcTemp.x()+ rcTemp.width())
                {
                    x = sqrt((nLr*nLr) * (nSr*nSr) / ((nSr*nSr) + ((nLr*nLr) * (a * a))));
                }
                // 椭圆焦点在Y轴 y^2/a^2+x^2/b^2=1，(a>b>0)；
                else
                {
                    x = sqrt((nLr*nLr) * (nSr*nSr) / (((nSr*nSr) * (a * a)) + (nLr*nLr)));
                }

                y = a * x;

                x = ptMid.x() - x;
                y = ptMid.y() - y;

                QRectF rc(x - dbW / 2, y - dbH / 2, dbW, dbH);

                if (rc.contains(QPoint(ptWinpoint.x(), ptWinpoint.y())))
                {
                    return true;
                }
            }
        }
        //! [3]
        //! [4]
        else if (ptEndWin.x() > ptStartWin.x() && ptEndWin.y() > ptStartWin.y())
        {
            rcTemp.setX((qreal)ptStartWin.x() - rcTemp.width() / 2);
            rcTemp.setY((qreal)ptStartWin.y());

            ptMid.setX(rcTemp.x() + rcTemp.width() / 2);
            ptMid.setY(rcTemp.y() + rcTemp.height() / 2);

            for (float i = 0; i <= 90; i += 0.1)
            {
                a = tan(angleToRadian(i));

                // 椭圆焦点在X轴 x^2/a^2+y^2/b^2=1，(a>b>0)；
                if (ptMid.x() + nSr < rcTemp.x() + rcTemp.width())
                {
                    x = sqrt((nLr*nLr) * (nSr*nSr) / ((nSr*nSr) + ((nLr*nLr) * (a * a))));
                }
                // 椭圆焦点在Y轴 y^2/a^2+x^2/b^2=1，(a>b>0)；
                else
                {
                    x = sqrt((nLr*nLr) * (nSr*nSr) / (((nSr*nSr) * (a * a)) + (nLr*nLr)));
                }

                y = a * x;

                x = ptMid.x() + x;
                y = ptMid.y() - y;

                QRectF rc(x - dbW / 2, y - dbH / 2, dbW, dbH);

                if (rc.contains(QPoint(ptWinpoint.x(), ptWinpoint.y())))
                {
                    return true;
                }
            }
        }
        //! [4]
        //! [5]
        else
        {
            x = ptStartWin.x() < ptEndWin.x() ? ptStartWin.x() : ptEndWin.x();
            y = ptStartWin.y() < ptEndWin.y() ? ptStartWin.y() : ptEndWin.y();

            x -= dbW / 2;
            y -= dbH / 2;

            int w = qAbs(ptStartWin.x() - ptEndWin.x()) > 0 ? qAbs(ptStartWin.x() - ptEndWin.x()) : dbW;
            int h = qAbs(ptStartWin.y() - ptEndWin.y()) > 0 ? qAbs(ptStartWin.y() - ptEndWin.y()) : dbW;

            QRectF rc(x, y, w, h);

            if (rc.contains(QPoint(ptWinpoint.x(), ptWinpoint.y())))
            {
                return true;
            }
        }
        //! [5]
    }
    else
    {
        //! [6]
        double dx = 0, dy = 0;
        dx = ptStartWin.x() - ptEndWin.x();
        dy = ptStartWin.y() - ptEndWin.y();

        // 直线
        if (dx == 0 || dy == 0)
        {
            int x = ptStartWin.x() < ptEndWin.x() ? ptStartWin.x() : ptEndWin.x();
            int y = ptStartWin.y() < ptEndWin.y() ? ptStartWin.y() : ptEndWin.y();

            x -= dbW / 2;
            y -= dbH / 2;

            int w = qAbs(ptStartWin.x() - ptEndWin.x()) > 0 ? qAbs(ptStartWin.x() - ptEndWin.x()) : dbW;
            int h = qAbs(ptStartWin.y() - ptEndWin.y()) > 0 ? qAbs(ptStartWin.y() - ptEndWin.y()) : dbW;

            QRectF rc(x, y, w, h);

            if (rc.contains(QPoint(ptWinpoint.x(), ptWinpoint.y())))
            {
                return true;
            }
        }
        //! [6]
        //! [7]
        // 斜线
        else
        {
            double s = qAbs(dy / dx);

            int x = 0, y = 0;
            for (int i = 0; i < qAbs(dx); i += dbW / 2)
            {
                if (dx > 0)
                {
                    x = ptStartWin.x() - i;
                }
                else
                {
                    x = ptStartWin.x() + i;
                }

                if (dy > 0)
                {
                    y = ptStartWin.y() - i * s;
                }
                else
                {
                    y = ptStartWin.y() + i * s;
                }

                QRectF rc(x - dbW / 2, y - dbH / 2, dbW, dbH);

                if (rc.contains(QPoint(ptWinpoint.x(), ptWinpoint.y())))
                {
                    return true;
                }
            }
        }
        //! [7]
    }

    return false;
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
        //! [6]
        if (m_bSelect)
        {
            pen.setColor(QColor(Qt::red));
            painter.setPen(pen);
            painter.drawLine(ptStartWin.x(), ptStartWin.y(), ptEndWin.x(), ptEndWin.y());
        }
        //! [6]
        //! [7]
        else
        {
            painter.drawLine(ptStartWin.x(), ptStartWin.y(), ptEndWin.x(), ptEndWin.y());
            pen.setWidth((g_fWidth / 2) * g_fScale);
            pen.setColor(QColor(Qt::yellow));
            pen.setStyle(Qt::DashLine);
            painter.setPen(pen);
            painter.drawLine(ptStartWin.x(), ptStartWin.y(), ptEndWin.x(), ptEndWin.y());
        }
        //! [7]
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
