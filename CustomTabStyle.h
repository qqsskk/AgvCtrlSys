#ifndef CUSTOMTABSTYLE_H
#define CUSTOMTABSTYLE_H

#include <QPainter>
#include <QProxyStyle>
#include <QStyleOptionTab>
#include <QRect>
#include <QSize>
#include <QDebug>
class CustomTabStyle : public QProxyStyle
{
public:
    QSize sizeFromContents(ContentsType type, const QStyleOption *option, const QSize &size, const QWidget *widget) const
    {
        QSize s = QProxyStyle::sizeFromContents(type, option, size, widget);
        if (type == QStyle::CT_TabBarTab)
        {
            s.transpose();
            s.rwidth() = 200;
            s.rheight() = 100;
        }
        return s;
    }

    void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
    {
        if (element == CE_TabBarTabLabel)
        {
            if (const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(option))
            {
                QRect allRect = tab->rect;

                if (tab->state & QStyle::State_Selected)
                {
                    painter->save();
                    painter->setPen(QColor("#34373E"));
                    painter->setBrush(QColor("#34373E"));
                    painter->drawRect(allRect.adjusted(0, 0, 0, 0));
                    painter->restore();
                }

                QTextOption option;
                option.setAlignment(Qt::AlignCenter);
                if (tab->state & QStyle::State_Selected)
                {
                    painter->setPen(QColor("#FFFFFF"));
                }
                else
                {
                    painter->setPen(QColor("#CCCCCC"));
                }
                painter->drawText(allRect, tab->text, option);

                if(tab->text==QString::fromLocal8Bit("地图信息"))
                {
                    painter->drawImage(allRect.x()+13, allRect.y()+36, QImage("./res/icon/tab_map.png"));
                }
                else if(tab->text==QString::fromLocal8Bit("任务信息"))
                {
                    painter->drawImage(allRect.x()+15, allRect.y()+36, QImage("./res/icon/tab_task.png"));
                }
                else if(tab->text==QString::fromLocal8Bit("历史信息"))
                {
                    painter->drawImage(allRect.x()+15, allRect.y()+36, QImage("./res/icon/tab_history.png"));
                }
                else if(tab->text==QString::fromLocal8Bit("设备状态"))
                {
                    painter->drawImage(allRect.x()+15, allRect.y()+36, QImage("./res/icon/tab_devstate.png"));
                }
                else if(tab->text==QString::fromLocal8Bit("模块信息"))
                {
                    painter->drawImage(allRect.x()+15, allRect.y()+36, QImage("./res/icon/tab_modules.png"));
                }
                else if(tab->text==QString::fromLocal8Bit("用户信息"))
                {
                    painter->drawImage(allRect.x()+15, allRect.y()+36, QImage("./res/icon/tab_user.png"));
                }
                else if(tab->text==QString::fromLocal8Bit("系统配置"))
                {
                    painter->drawImage(allRect.x()+15, allRect.y()+36, QImage("./res/icon/tab_config.png"));
                }

                return;
            }
        }

        if (element == CE_TabBarTab)
        {
            QProxyStyle::drawControl(element, option, painter, widget);
        }
    }
};
#endif // CUSTOMTABSTYLE_H
