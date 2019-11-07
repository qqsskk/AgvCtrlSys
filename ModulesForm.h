#ifndef MODULESFORM_H
#define MODULESFORM_H

#include <QWidget>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QStandardItem>
#include "CustomJsonModel.h"
#include <QFile>
#include <QDebug>
#include <MsgBoxEx.h>

namespace Ui {
class ModulesForm;
}

class ModulesForm : public QWidget
{
    Q_OBJECT

public:
    explicit ModulesForm(QWidget *parent = nullptr);
    ~ModulesForm();

private:
    Ui::ModulesForm *ui;

private slots:
    void onBtnOkClicked();
    void onBtnCancelClicked();

    void on_toolButtonUpdate_clicked();

private:
    /**
      * @brief init 初始化
      */
     void init();

    /**
     * @brief clearAllTabelModel 清除所有表模型行
     */
    void clearAllTabelModel();

    /**
     * @brief loadJsonData  加载json数据
     * @param jsonFilePath  json文件路径
     * @return true 成功，false 失败
     */
    bool loadJsonData(QString jsonFilePath);

    /**
     * @brief updateTableAgvType    更新AGV类型表
     * @param json  json对象
     * @return true 成功，false 失败
     */
    bool updateTableAgvType(const QJsonObject &json);

    /**
     * @brief updateTableRestQueue    更新待机队列表
     * @param json  json对象
     * @return true 成功，false 失败
     */
    bool updateTableRestQueue(const QJsonObject &json);

    /**
     * @brief updateTableAgv    更新AGV表
     * @param json  json对象
     * @return true 成功，false 失败
     */
    bool updateTableAgv(const QJsonObject &json);

    /**
     * @brief updateTableWorkStation    更新工作站表
     * @param json  json对象
     * @return true 成功，false 失败
     */
    bool updateTableWorkStation(const QJsonObject &json);

    /**
     * @brief updateTableResetStation    更新待机站表
     * @param json  json对象
     * @return true 成功，false 失败
     */
    bool updateTableResetStation(const QJsonObject &json);

    /**
     * @brief updateTableCharger    更新充电站表
     * @param json  json对象
     * @return true 成功，false 失败
     */
    bool updateTableCharger(const QJsonObject &json);

    /**
     * @brief updateTableTraffic    更新交通管制表
     * @param json  json对象
     * @return true 成功，false 失败
     */
    bool updateTableTraffic(const QJsonObject &json);

private:
    QStandardItemModel *m_itemModelAgvType;         // AGV类型表模型
    QStandardItemModel *m_itemModelRestQueue;       // 待机队列表模型
    QStandardItemModel *m_itemModelAgv;             // AGV列表模型
    QStandardItemModel *m_itemModelWorkStation;     // 工作站列表模型
    QStandardItemModel *m_itemModelResetStation;    // 待机站列表模型
    QStandardItemModel *m_itemModelCharger;         // 充电站列表模型
    QStandardItemModel *m_itemModelTraffic;         // 交通管制列表模型
};

#endif // MODULESFORM_H
