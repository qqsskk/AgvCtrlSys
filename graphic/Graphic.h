#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QPainter>
#include <QWidget>
#include <QDebug>

#define MAX_SCALE 10.0f
#define MIN_SCALE 0.4f
#define DEFALUT_SCALE 3.0f

class Graphic : public QWidget
{
public:
    Graphic();
    ~Graphic();

protected:
    static QPoint g_ptOffset;                       // 偏移量
    static float g_fScale;                          // 缩放比例
    static quint32 g_unDistance;                    // 网格间距
    static QSize g_sizeVector;                      // 矢量图尺寸
    static QRect g_rcClient;                        // 客户区尺寸
    static unsigned long long g_ullFlashTime;       // 闪烁开始时间

public:
    /**
     * @brief setClientRect 设置客户区尺寸
     * @param rcClient 客户区尺寸
     */
    static void setClientRect(QRect rcClient);

    /**
     * @brief getOffset 获取偏移量
     * @return 偏移量
     */
    static QPoint getOffset();

    /**
     * @brief setOffset 设置偏移量
     * @param ptOffset 偏移量
     */
    static void setOffset(QPoint ptOffset);

    /**
     * @brief getScale 获取缩放比例
     * @return 缩放比例
     */
    static float getScale();

    /**
     * @brief setScale 设置缩放比例
     * @param fScale 缩放比例
     */
    static void setScale(float fScale);

    /**
     * @brief vecToWin 将矢量坐标转换为窗口坐标
     * @param ptVector 矢量坐标
     * @return 窗口坐标
     */
    static QPoint vecToWin(QPoint ptVector);

    /**
     * @brief winToVec 将窗口坐标转换未矢量坐标
     * @param ptWindow 窗口坐标
     * @return 矢量坐标
     */
    static QPoint winToVec(QPoint ptWindow);

    /**
     * @brief correctPoint 矫正矢量坐标
     * @param ptVector  矢量坐标
     * @return 矫正后的矢量坐标
     */
    static QPoint correctPoint(QPoint ptVector);
};

#endif // GRAPHIC_H
