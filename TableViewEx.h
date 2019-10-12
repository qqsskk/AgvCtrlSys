#ifndef TABLEVIEWEX_H
#define TABLEVIEWEX_H

#include <QTableView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include "CustomTableModel.h"

class TableViewEx : public QTableView
{
    Q_OBJECT
public:
      TableViewEx(QWidget *parent = 0);

};

#endif // TABLEVIEWEX_H
