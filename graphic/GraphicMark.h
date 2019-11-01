#ifndef GRAPHICMARK_H
#define GRAPHICMARK_H

#include "graphic/Graphic.h"

class GraphicMark : public Graphic
{
public:
    GraphicMark(quint32 unNo);
    ~GraphicMark();

protected:
    quint32 m_unNo;             // 编号
    QPoint m_ptCenter;          // 中心坐标
    QPoint m_ptPrepoint;        // 起始坐标
    QPoint m_ptLastpoint;       // 终止坐标
    QPoint m_ptLocal;           // 记录坐标
    bool m_bMove;               // 移动标识
    bool m_bSelect;             // 选中标识
    static quint32 g_unWidth;	// 宽
    static quint32 g_unHeight;	// 高

public:
    /**
     * @brief getNo 获取编号
     * @return 编号
     */
    quint32 getNo();

    /**
     * @brief isSelected 获取选中状态
     * @return true 选中, false 未选中
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
     * @return 标指针形状
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
     * @brief getCenterPoint 获取中心坐标
     * @return 中心坐标
     */
    QPoint getCenterPoint();

    /**
     * @brief setCenterPoint 设置中心坐标
     * @param ptCenter 中心坐标
     */
    void setCenterPoint(QPoint ptCenter);

    /**
     * @brief draw      绘制
     * @param painter   绘画
     */
    void draw(QPainter &painter);
};

#endif // GRAPHICMARK_H
