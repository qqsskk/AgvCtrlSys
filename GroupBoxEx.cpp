#include "GroupBoxEx.h"

GroupBoxEx::GroupBoxEx(QWidget *parent) : QGroupBox(parent)
{
    setStyleSheet("QGroupBox::title{background:#31343B; color:#CCCCCC; subcontrol-origin: margin;\
                   subcontrol-position: top; padding: 12 1000px;}\
                   QGroupBox{border: 1px solid #31343B}");
}
