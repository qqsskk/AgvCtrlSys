#include "PushButtonEx.h"


PushButtonEx::PushButtonEx(QWidget *parent) : QPushButton(parent)
{
    init();
}


void PushButtonEx::init()
{
    setStyleSheet("QPushButton{background:#FFFFFF; border-radius:5px; font-size:12pt; font-family:Microsoft YaHei; color:#000000} \
                  QPushButton::hover{background:#4EB485; color:#FFFFFF} \
                  QPushButton::pressed{background:#34373E; color:#FFFFFF}");
}
