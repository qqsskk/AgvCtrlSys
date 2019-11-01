#ifndef GRAPHICTRACK_H
#define GRAPHICTRACK_H
#include "graphic/Graphic.h"

class GraphicTrack : public Graphic
{  
public:
    GraphicTrack(bool bArc);
    ~GraphicTrack();

protected:
    QPoint m_ptStart;       // 起点坐标
    QPoint m_ptEnd;         // 终点坐标
    bool m_bArc;            // 弧线标识

    QPoint m_ptPrepoint;	// 起始坐标
    QPoint m_ptLastpoint;	// 终止坐标
    QPoint m_ptLocal;		// 记录起点坐标
    QPoint m_ptDistance;	// 间距
    bool m_bMove;			// 移动标识
    bool m_bSelect;			// 选中标识

    static float g_fWidth;	// 宽

public:
    /**
     * @brief setStartPoint 设置起点坐标
     * @param ptStart 起点坐标(矢量坐标)
     */
    void setStartPoint(QPoint ptStart);

    /**
     * @brief setEndPoint 设置终点坐标
     * @param ptEnd 终点坐标(矢量坐标)
     */
    void setEndPoint(QPoint ptEnd);

    /**
     * @brief setType 设置轨道类型
     * @param bArc true 弧线, false 直线
     */
    void setType(bool bArc);

    /**
     * @brief getStartPoint 获取起点坐标(矢量坐标)
     * @return 起点坐标
     */
    QPoint getStartPoint();

    /**
     * @brief getEndPoint 获取终点坐标(矢量坐标)
     * @return 终点坐标
     */
    QPoint getEndPoint();

    /**
     * @brief getType 获取轨道类型
     * @return true 弧形, false 直线
     */
    bool getType();

    /**
     * @brief isSelected 获取选中状态
     * @return true 选中，false 未选中
     */
    bool isSelected();

    /**
     * @brief select        选中
     * @param ptWinpoint    窗口坐标
     */
    void select(QPoint ptWinpoint);

    /**
     * @brief drag          拖拽
     * @param ptWinPoint    窗口坐标
     * @return 鼠标指针形状
     */
    QCursor drag(QPoint ptWinPoint);

    /**
     * @brief confirm 确认
     */
    void confirm();

    /**
     * @brief cancel 取消
     */
    void cancel();

    /**
     * @brief draw      绘制
     * @param painter   绘画
     */
    void draw(QPainter &painter);

    /**
     * @brief setWidth  设置轨道宽度
     * @param fWidth 宽度
     */
    static void setWidth(float fWidth);

    /**
     * @brief getWidth 获取轨道宽度
     * @return 宽度
     */
    static float getWidth();

    /**
     * @brief radianToAngle 弧度转角度
     * @param dbRadian  弧度值
     * @return 角度值
     */
    static double radianToAngle(double dbRadian);

    /**
     * @brief angleToRadian 角度转弧度
     * @param dbAngle 角度值
     * @return 弧度值
     */
    static double angleToRadian(double dbAngle);
};

#endif // GRAPHICTRACK_H
