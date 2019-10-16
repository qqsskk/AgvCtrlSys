#include "LineEditEx.h"

LineEditEx::LineEditEx(QWidget *parent) : QLineEdit(parent)
{
    init();
}
void LineEditEx::init()
{
    setStyleSheet("QLineEdit{background:#FFFFFF; border:1px solid #CCCCCC; border-radius:5px; \
                  font-size:12pt; font-family:Microsoft YaHei; color:#000000} \
                  QLineEdit:enabled:focus {background:#FFFFFF; border:2px solid #4EB485;}\
                  QLineEdit:!enabled {background: #CCCCCC;}");
}
