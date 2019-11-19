#ifndef GRAPHICMAP_H
#define GRAPHICMAP_H

#include <QWidget>
#include <QMutex>
#include <QMap>
#include <QSqlQuery>
#include <QDebug>
#include <QMutex>
#include <QFile>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QSqlError>
#include "xml/TinyxmlEngine.h"
#include "graphic/GraphicBg.h"
#include "graphic/GraphicMark.h"
#include "graphic/GraphicTrack.h"
#include "graphic/GraphicStation.h"
#include "graphic/GraphicRest.h"
#include "graphic/GraphicCharger.h"
#include "graphic/GraphicAgv.h"


enum BUTTONCTRL
{
    BUTTONCTRL_LDOWN, // 鼠标左键按下
    BUTTONCTRL_LUP, // 鼠标左键抬起
    BUTTONCTRL_DL, // 双击鼠标左键
    BUTTONCTRL_RDOWN, // 鼠标右键按下
    BUTTONCTRL_RUP, // 鼠标右键抬起
    BUTTONCTRL_DR, // 双击鼠标右键
    BUTTONCTRL_MDOWN, // 鼠标中键按下
    BUTTONCTRL_MUP, // 鼠标中键抬起
    BUTTONCTRL_DM, // 双击鼠标中键
};

class GraphicMap : public QWidget
{
public:
    GraphicMap(QWidget *parent = 0);
    ~GraphicMap();

private:
    GraphicBg *m_pBg;                                // 地图指针
    QMap<quint32, GraphicMark*> m_mapMark;           // 地标卡指针集合
    QList<GraphicTrack*> m_listTrack;                // 磁轨指针列表
    QMap<quint32, GraphicStation*> m_mapStation;     // 工位指针集合
    QMap<quint32, GraphicRest*> m_mapRest;           // 待机点指针集合
    QMap<quint32, GraphicCharger*> m_mapCharger;     // 充电器指针集合
    QMap<quint32, GraphicAgv*> m_mapAGV;             // AGV指针集合


private:
    QMutex m_mutex;             // 互斥锁
    CTinyxmlEngine m_engine;

public:
    /**
     * @brief drawMap   绘制地图
     * @param painter   绘图
     */
    void drawMap(QPainter &painter);

    /**
     * @brief select    选中
     * @param nButton   鼠标键
     * @param point     坐标
     * @return  true 选中， false 未选中
     */
    bool select(int nButton, QPoint point);

    /**
     * @brief confirm   提交
     * @param nButton   鼠标键
     * @param point     坐标
     * @return true 提交， false 未提交
     */
    bool confirm(int nButton, QPoint point);

    /**
     * @brief wheel 缩放
     * @param bDire true 放大， false 缩小
     */
    void wheel(bool bDire);

    /**
     * @brief drag          拖拽
     * @param ptWinPoint    坐标
     * @return  鼠标光标
     */
    QCursor drag(QPoint ptWinPoint);

    /**
     * @brief cancel    取消拖拽
     */
    void cancel();

    /**
     * @brief size  视图更新
     * @param rect  更新范围
     */
    void size(QRect rect);

    /**
     * @brief showAgv           显示AGV
     * @param unNo              AGV编号
     * @param strType           AGV类型
     * @param unCurMark         当前地标卡
     * @param bRun              移动标识
     * @param bUnVol            电量不足标识
     * @param bObs              避障标识
     * @param bError            异常标识
     */
    void showAgv(quint32 unNo, QString strType, quint32 unCurMark, bool bRun, bool bUnVol, bool bObs, bool bError);

    /**
     * @brief hideAgv           隐藏AGV
     * @param unNo              AGV编号
     */
    void hideAgv(quint32 unNo);

    /**
     * @brief updateMapRelateTable  更新与地图相关的数据表
     * @param xmlPath xml路径
     * @return true 成功，false 失败
     */
    bool updateMapRelateTable(QString xmlPath);

    /**
     * @brief loadMapElement   加载地图元素信息
     */
    void loadMapElement();

private:
    /**
     * @brief 清除地图元素信息
     */
    void clearMapElement();

    QString getAgvType(QString shortType);

    bool updateElementData(QString jsonFilePath);

    bool insertTableAgvType(const QJsonObject &json);
    bool insertTableRestQueue(const QJsonObject &json);
};
#endif // GRAPHICMAP_H
