#include "ComboBoxEx.h"

ComboBoxEx::ComboBoxEx(QWidget *parent) : QComboBox(parent)
{
    init();
}

void ComboBoxEx::init()
{
    setView(new QListView());
    setStyleSheet("QComboBox {border-radius: 5px; border:1px solid #CCCCCC; background:#FFFFFF;\
                  font-size:12pt; font-family:Microsoft YaHei; color:#000000}\
                  QComboBox:enabled:hover, QComboBox:enabled:focus {background:#FFFFFF; border:2px solid #4EB485;}\
                  QComboBox:!enabled {background:#CCCCCC; color:#FFFFFF}\
                  QComboBox QAbstractItemView {border:none; background:#CCCCCC; font-size:12pt; font-family:Microsoft YaHei; color:#000000;}\
                  QComboBox QAbstractItemView::item {height:30px; color:#000000;}\
                  QComboBox QAbstractItemView::item:hover {background:#34373E; color:#FFFFFF}");
}
