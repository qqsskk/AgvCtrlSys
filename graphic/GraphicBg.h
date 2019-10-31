#ifndef GRAPHICBG_H
#define GRAPHICBG_H
#include "graphic/Graphic.h"
#include <QMutex>

class GraphicBg : public Graphic
{
public:
    GraphicBg(QColor colorLine = Qt::black, float fWidth = 2.0f, QString strPath = "./res/image/background.jpg");
    ~GraphicBg();

protected:
    QImage *m_pImage;		// 背景图
    QPen *m_pPen;			// 画笔
    QColor m_colorLine;		// 辅助线颜色
    float m_fWidth;			// 辅助线宽度
    QString m_strPath;		// 背景图路径
    bool m_bMove;			// 移动标识
    QPoint m_ptPrepoint;	// 起始坐标
    QPoint m_ptLastpoint;	// 终止坐标
    QPoint m_ptLocal;		// 偏移量记录

protected:
    QMutex m_mutexLock;

public:
    /**
     * @brief setLine   设置辅助线
     * @param colorLine 辅助线颜色
     * @param fWidth    辅助线宽度
     */
    void setLine(QColor colorLine, float fWidth);

    /**
     * @brief getLine   获取辅助线
     * @param colorLine 返回辅助线颜色
     * @param fWidth    返回辅助线宽度
     */
    void getLine(QColor &colorLine, float &fWidth);

    /**
     * @brief setImage  设置背景图
     * @param strPath   背景图路径
     */
    void setImage(QString strPath);

    /**
     * @brief getImage  获取背景图
     * @return 背景图路径
     */
    QString getImage();

    /**
     * @brief scale     缩放
     * @param bShrink   true 放大， false 缩小
     */
    void scale(bool bShrink = false);

    /**
     * @brief reset 复位
     */
    void reset();

    /**
     * @brief drag          拖拽
     * @param ptWinPoint    窗口坐标
     * @return 鼠标指针形状
     */
    QCursor drag(QPoint ptWinPoint);

    /**
     * @brief select        选中
     * @param ptWinPoint    窗口坐标
     * @details 鼠标左键点击底图,触发此函数
     */
    void select(QPoint ptWinPoint);

    /**
     * @brief cancel 取消拖拽
     */
    void cancel();

    /**
     * @brief confirm 完成拖拽
     */
    void confirm();

public:
    /**
     * @brief drawBg    绘制背景图
     * @param painter   绘图
     */
    void drawBg(QPainter &painter);

    /**
     * @brief drawSubline   绘制辅助线
     * @param painter   绘图
     */
    void drawSubline(QPainter &painter);

    /**
     * @brief drawSubpoint  绘制辅助坐标
     * @param painter   绘图
     */
    void drawSubpoint(QPainter &painter);
};

#endif // GRAPHICBG_H
