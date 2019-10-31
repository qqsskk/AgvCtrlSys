#include "graphic/Graphic.h"

unsigned long long Graphic::g_ullFlashTime = 0;
QPoint Graphic::g_ptOffset = QPoint(0,0);
float Graphic::g_fScale = DEFALUT_SCALE;
quint32 Graphic::g_unDistance = 10;
QSize Graphic::g_sizeVector = QSize(4800, 4800);
QRect Graphic::g_rcClient = QRect(0,0,0,0);

Graphic::Graphic()
{

}

Graphic::~Graphic()
{

}

void Graphic::setClientRect(QRect rcClient)
{
    g_rcClient = rcClient;
    return;
}

QPoint Graphic::getOffset()
{
    return g_ptOffset;
}

void Graphic::setOffset(QPoint ptOffset)
{
    g_ptOffset = ptOffset;
    return;
}

float Graphic::getScale()
{
    return g_fScale;
}

void Graphic::setScale(float fScale)
{
    g_fScale = fScale;
    return;
}

QPoint Graphic::vecToWin(QPoint ptVector)
{
    int nX = ptVector.x() * g_fScale + g_rcClient.right() / 2 + g_ptOffset.x();
    int nY = -ptVector.y() * g_fScale + g_rcClient.bottom() / 2 + g_ptOffset.y();

    return QPoint(nX,nY);
}

QPoint Graphic::winToVec(QPoint ptWindow)
{
    double fX0 = g_rcClient.right() / 2.0f;     // 客户区中心X坐标
    double fY0 = g_rcClient.bottom() / 2.0f;	// 客户区中心Y坐标

    int nX = ptWindow.x() - (int)fX0;
    int nY = (int)fY0 - ptWindow.y();

    nX = ((nX - g_ptOffset.x()) / g_fScale);
    nY = ((nY + g_ptOffset.y()) / g_fScale);

    return QPoint(nX,nY);
}

QPoint Graphic::correctPoint(QPoint ptVector)
{
    int nDis = g_unDistance;
    int nDx = abs(ptVector.x()) % nDis;
    int nDy = abs(ptVector.y()) % nDis;

    if (nDx > nDis)
    {
        if (ptVector.x() > 0)
        {
            ptVector.rx() += nDis;
        }
        else
        {
            ptVector.rx() -= nDis;
        }
    }

    if (nDy > nDis)
    {
        if (ptVector.y() > 0)
        {
            ptVector.ry() += nDis;
        }
        else
        {
            ptVector.ry() -= nDis;
        }
    }

    if (ptVector.x() > 0)
    {
        ptVector.rx() -= nDx;
    }
    else
    {
        ptVector.rx() += nDx;
    }

    if (ptVector.y() > 0)
    {
        ptVector.ry() -= nDy;
    }
    else
    {
        ptVector.ry() += nDy;
    }

    return ptVector;
}
