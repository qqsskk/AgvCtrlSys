﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TitleBarEx.h"
#include "CustomTabStyle.h"
#include "MapForm.h"
#include "TaskForm.h"
#include "DeviceStateForm.h"
#include "UserForm.h"
#include "HistoryForm.h"
#include "AbnormalForm.h"
#include "ConfigForm.h"
#include "ModulesForm.h"
#include "MsgBoxEx.h"
#include "CustomData.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QString user, QString passwd, int level, QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

    QString m_userName;
    QString m_userPasswd;
    int m_userLevel;

private:
    void initWindow();

private slots:
    void onWindowClose();
    void onBtnOkClicked();
    void onBtnCancelClicked();

    void onUpdateAbnormalExist(bool exist);
    void onCallerEnable(int id, bool enable);

signals:
    /**
     * @brief netServerStateChange 网络服务状态信号
     * @param isLink 是否连接  true 连接，false 断开
     */
    void netServerStateChange(bool isLink);

    /**
     * @brief serialPortStateChange 串口状态信息
     * @param isOpen 是否打开  true 打开，false 关闭
     */
    void serialPortStateChange(bool isOpen);

    /**
     * @brief showAgv       显示AGV
     * @param unNo          ID
     * @param strType       类型
     * @param unCurMark     当前地标卡
     * @param bRun          是否运行
     * @param bUnVol        是否低电
     * @param bObs          是否避障
     * @param bError        是否异常
     */
    void showAgv(quint32 unNo, QString strType, quint32 unCurMark, bool bRun, bool bUnVol, bool bObs, bool bError);


    /**
     * @brief hideAgv     隐藏GV
     * @param unNo        AGV编号
     */
    void hideAgv(quint32 unNo);


    /**
     * @brief callerEnable  呼叫器禁用
     * @details 绑定此信号获取呼叫器是否被启用，与updateCallerData()信号一起使用
     * @param id        呼叫器编号
     * @param enable    是否可用
     */
    void callerEnable(int id, bool enable);


    /**
     * @brief updateCallerData 更新呼叫器信息
     * @details 需要刷新用于显示的呼叫器信息的时候发送此信号
     */
    void updateCallerData();
};

#endif // MAINWINDOW_H
