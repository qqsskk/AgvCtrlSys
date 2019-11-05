#ifndef GRAPHICSAGV_H
#define GRAPHICSAGV_H

#include "graphic/Graphic.h"
#include <QDebug>

class GraphicAgv : public Graphic
{
public:
    GraphicAgv(quint32 unNo, QString strType, QString strMove);
    ~GraphicAgv();

protected:
    quint32 m_unNo;             // 编号
    QString m_strType;			// 类型 P牵引式 S潜入式 T移载式 F叉车式 A机械手式 L激光式
    QString m_strMove;			// 可运动方向 S单向 D双向 F全向

protected:
    bool m_bRun;				// 移动标识
    bool m_bUnVol;				// 电量不足标识
    bool m_bObs;				// 避障标识
    bool m_bError;				// 异常标识

protected:
    bool m_bShow;				// 显示标识符
    QPoint m_ptCenter;			// 中心坐标 矢量坐标

protected:
    static quint32 g_unWidth;       // 宽
    static quint32 g_unHeight;      // 高
    static QString g_strAGV;		// AGV贴图
    static QString g_strRun;		// 移动贴图
    static QString g_strUnVol;		// 电量不足贴图
    static QString g_strError;		// 异常贴图
    static QString g_strObs;		// 避障贴图

    QImage *m_pImageAgv;
    QImage *m_pImageRun;
    QImage *m_pImageUnvol;
    QImage *m_pImageError;
    QImage *m_pImageObs;

public:
    /**
     * @brief setType   设置类型
     * @param strType   类型
     */
    void setType(QString strType);

    /**
     * @brief setMove   设置可运动方向
     * @param strMove   可运动方向
     */
    void setMove(QString strMove);

    /**
     * @brief getNo 获取编号
     * @return 编号
     */
    quint32 getNo();

    /**
     * @brief getType   获取类型
     * @return P牵引式 S潜入式 T移载式 F叉车式 A机械手式 L激光式
     */
    QString getType();

    /**
     * @brief getMove   获取可运动方向
     * @return S单向 D双向 F全向
     */
    QString getMove();

    /**
     * @brief setImage  设置贴图
     * @param strAGV    AGV贴图路径
     * @param strRun    移动贴图路径
     * @param strUnVol  电量不足贴图路径
     * @param strError  异常贴图路径
     * @param strObs    避障贴图路径
     */
    static void setImage(QString strAGV, QString strRun, QString strUnVol, QString strError, QString strObs);

    /**
     * @brief getImage  获取贴图
     * @param strAGV    返回AGV贴图路径
     * @param strRun    返回移动贴图路径
     * @param strUnVol  返回电量不足贴图路径
     * @param strError  返回异常贴图路径
     * @param strObs    返回避障贴图路径
     */
    static void getImage(QString &strAGV, QString &strRun, QString &strUnVol, QString &strError, QString &strObs);

    /**
     * @brief setStatus 设置状态
     * @param bRun      移动标识
     * @param bUnVol    电量不足标识
     * @param bObs      避障标识
     * @param bError    异常标识
     */
    void setStatus(bool bRun, bool bUnVol, bool bObs, bool bError);

    /**
     * @brief isShow    是否显示
     * @param bShow     true为显示 false为隐藏
     */
    void isShow(bool bShow);

    /**
     * @brief setCenterPoint    设置中心坐标
     * @param ptCenter  中心坐标(矢量坐标)
     */
    void setCenterPoint(QPoint ptCenter);

    /**
     * @brief getCenterPoint    获取中心坐标
     * @return  中心坐标(矢量坐标)
     */
    QPoint getCenterPoint();

    /**
     * @brief draw      绘制
     * @param painter   绘图
     */
    void draw(QPainter &painter);
};

#endif // GRAPHICSAGV_H
