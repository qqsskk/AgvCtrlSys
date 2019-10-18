#include "LabelEx.h"

LabelEx::LabelEx(QWidget *parent) : QLabel(parent)
{
    setStyleSheet("QLabel {font: 10pt Microsoft YaHei;  color:#CCCCCC}\
                   QLabel:!enabled{font: 10pt Microsoft YaHei;  color:#FFFFFF}");
}
