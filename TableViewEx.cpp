#include "TableViewEx.h"

TableViewEx::TableViewEx(QWidget *parent) : QTableView(parent)
{
    CustomTableModel *model = new CustomTableModel;

    this->setModel(model);

    setStyleSheet("QTableView {border: 1px solid #CCCCCC; background: #484C55;}\
                 QTableView::item {font: 15pt Microsoft YaHei; color: #CCCCCC;\
                  padding-left: 5px; padding-right: 5px; border: none; background: #484C55;\
                  border-right: 1px solid #CCCCCC; border-bottom: 1px solid #CCCCCC;}\
                QTableView::item:selected {background: #4EB485;}\
                QTableView::item:selected:!active {color: #FFFFFF;}\
                QHeaderView::section{background:#484C55; color: #CCCCCC; height: 40px; font: 15pt Microsoft YaHei;}");




}


