#include "TableViewEx.h"

TableViewEx::TableViewEx(QWidget *parent) : QTableView(parent)
{
    init();
}

void TableViewEx::init()
{
    setStyleSheet("QTableView {border: 1px solid #31343B; background: #484C55;}\
                  QTableView::item {font: 15pt Microsoft YaHei; color: #CCCCCC;\
                                    padding-left: 5px; padding-right: 5px; border: none; background: #484C55;\
                                    border-right: 1px solid #CCCCCC; border-bottom: 1px solid #CCCCCC;}\
                  QTableView::item:selected {background: #4EB485; color:#FFFFFF}\
                  QTableView::item:selected:!active {color: #FFFFFF;}\
                  QHeaderView::section{background:#484C55; color:#FFFFFF; height:40px; font:12pt Microsoft YaHei;}\
                  QHeaderView{background:#484C55}");

    setSelectionBehavior(QAbstractItemView::SelectRows);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setSortingEnabled(false);
    verticalHeader()->hide();
    setWordWrap(false);
    setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    setShowGrid(false);
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    horizontalHeader()->setHighlightSections(false);
    setAlternatingRowColors(true);
    setFrameShape(QFrame::NoFrame);
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void TableViewEx::setTableModel(QAbstractTableModel *model, bool isInteractive)
{
    this->setModel(model);
    if(isInteractive)
    {
        this->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    }
}
