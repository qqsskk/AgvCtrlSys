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

                painter->drawImage(13, 36, QImage("./res/icon/tab_map.png"));
                painter->drawImage(15, 136, QImage("./res/icon/tab_task.png"));
                painter->drawImage(15, 236, QImage("./res/icon/tab_history.png"));
                painter->drawImage(15, 336, QImage("./res/icon/tab_devstate.png"));
                painter->drawImage(15, 436, QImage("./res/icon/tab_modules.png"));
                painter->drawImage(15, 536, QImage("./res/icon/tab_user.png"));
                painter->drawImage(15, 636, QImage("./res/icon/tab_config.png"));

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
