#ifndef MODULESFORM_H
#define MODULESFORM_H

#include <QWidget>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QSqlQueryModel>
#include "CustomJsonModel.h"
#include <QFile>
#include <QDebug>
#include "MsgBoxEx.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QToolTip>
#include "CustomTableModel.h"
#include <QCheckBox>

#include "headerviewex.h"

namespace Ui {
class ModulesForm;
}

class ModulesForm : public QWidget
{
    Q_OBJECT

public:
    explicit ModulesForm(QWidget *parent = nullptr);
    ~ModulesForm();

private slots:
    void on_tableViewAgvType_clicked(const QModelIndex &index);
    void on_tableViewAgv_clicked(const QModelIndex &index);
    void on_tableViewWorkStation_clicked(const QModelIndex &index);
    void on_tableViewResetStation_clicked(const QModelIndex &index);
    void on_tableViewCharger_clicked(const QModelIndex &index);
    void on_tableViewResetQueue_clicked(const QModelIndex &index);
    void on_tableViewTraffic_clicked(const QModelIndex &index);

private:
    Ui::ModulesForm *ui;

private:
    /**
      * @brief init 初始化
      */
    void init();

    /**
      * @brief showItemTip  显示表格单元格内容
      * @param model    表格模型
      * @param index    序号
      */
    void showItemTip(const QSqlQueryModel *model, const QModelIndex index);

    /**
      * @brief loadModulesData 加载数据
      */
    void loadModulesData();



private:
    QSqlQueryModel *m_itemModelAgvType;         // AGV类型表模型
    QSqlQueryModel *m_itemModelAgv;             // AGV表模型
    QSqlQueryModel *m_itemModelRestQueue;       // 待机队列表模型
    QSqlQueryModel *m_itemModelWorkStation;     // 工作站列表模型
    QSqlQueryModel *m_itemModelResetStation;    // 待机站列表模型
    QSqlQueryModel *m_itemModelCharger;         // 充电站列表模型
    QSqlQueryModel *m_itemModelTraffic;         // 交通管制列表模型
    QStandardItemModel *m_itemModelCaller;      // 呼叫器列表模型

private slots:
    void onStateChanged(int state);




public slots:
    /**
     * @brief onUpdateCallerData 更新呼叫器信息
     */
    void onUpdateCallerData();

signals:
    void callerEnable(int id, bool enable);
};

#endif // MODULESFORM_H
