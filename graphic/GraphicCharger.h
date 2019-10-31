#ifndef GRAPHICCHARGER_H
#define GRAPHICCHARGER_H

#include "graphic/Graphic.h"

class GraphicCharger : public Graphic
{
public:
    GraphicCharger(quint32 unNo, quint32 unMark, quint32 unCtrl);
    ~GraphicCharger();

protected:
    quint32 m_unNo;                  // 编号
    quint32 m_unMark;                // 地标卡
    quint32 m_unCtrl;                // 控制器

protected:
    bool m_bPower;                  // 通电状态

protected:
    static quint32 g_unWidth;        // 宽
    static quint32 g_unHeight;       // 高
    static QString g_strPath;		// 背景图路径
    static QString g_strPower;		// 充电标识路径

protected:
    QPoint m_ptCenter;              // 中心坐标
    QPoint m_ptPrepoint;            // 起始坐标
    QPoint m_ptLastpoint;           // 终止坐标
    QPoint m_ptLocal;               // 记录坐标
    bool m_bMove;                   // 移动标识
    bool m_bSelect;                 // 选中标识
    QImage *m_pImageBg;
    QImage *m_pImagePower;

public:
    /**
    * @brief getNo 获取编号
    * @return 编号
    */
    quint32 getNo();

    /**
    * @brief setPower 设置充电状态
    * @param bPower true充电, false断电
    */
    void setPower(bool bPower);

    /**
    * @brief setCtrl   设置控制器
    * @param unCtrl    控制器编号
    */
    void setCtrl(quint32 unCtrl);

    /**
    * @brief getCtrl 获取控制器
    * @return 控制器编号
    */
    quint32 getCtrl();

    /**
    * @brief setMark   设置地标卡
    * @param unMark    地标卡
    */
    void setMark(quint32 unMark);

    /**
    * @brief getMark   获取地标卡
    * @return 地标卡
    */
    quint32 getMark();

    /**
    * @brief setImage  设置背景图
    * @param strPath   背景图路径
    * @param strPower  充电标识路径
    */
    static void setImage(QString strPath, QString strPower);

    /**
    * @brief getImage  获取背景图
    * @param strPath   返回背景图路径
    * @param strPower  返回充电标识路径
    */
    static void getImage(QString &strPath, QString &strPower);

    /**
    * @brief isInside      窗口坐标是否在区域内
    * @param ptWinpoint    窗口坐标
    * @return true 在区域内，false 不在区域内
    */
    bool isInside(QPoint ptWinpoint);

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
    * @return 鼠标指针形状
    */
    QCursor drag(QPoint ptWinPoint);

    /**
    * @brief confirm   确认
    */
    void confirm();

    /**
    * @brief cancel 取消
    */
    void cancel();

    /**
    * @brief getCenterPoint    获取中心坐标
    * @return 中心坐标
    */
    QPoint getCenterPoint();

    /**
    * @brief setCenterPoint    设置中心坐标
    * @param ptCenter  中心坐标
    */
    void setCenterPoint(QPoint ptCenter);

    /**
    * @brief draw      绘制
    * @param painter   绘图
    */
    void draw(QPainter &painter);
};

#endif // GRAPHICCHARGER_H
