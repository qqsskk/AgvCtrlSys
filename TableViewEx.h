#ifndef TABLEVIEWEX_H
#define TABLEVIEWEX_H

#include <QTableView>
#include <QHeaderView>
#include <QCheckBox>

class TableViewEx : public QTableView
{
    Q_OBJECT
public:
      TableViewEx(QWidget *parent = 0);
private:
      void init();
public:
      void setTableModel(QAbstractTableModel *model);

};
#endif // TABLEVIEWEX_H
