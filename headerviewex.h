#ifndef HEADERVIEWEX_H
#define HEADERVIEWEX_H

#include <QHeaderView>
#include <QPainter>

class HeaderViewEx : public QHeaderView
{
public:
  HeaderViewEx(Qt::Orientation orientation, QWidget * parent = 0) : QHeaderView(orientation, parent)
  {}

protected:
  void paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const
  {
    painter->save();
    HeaderViewEx::paintSection(painter, rect, logicalIndex);
    painter->restore();
    if (logicalIndex == 0)
    {
      QStyleOptionButton option;
      option.rect = QRect(10,10,10,10);
      if (isOn)
        option.state = QStyle::State_On;
      else
        option.state = QStyle::State_Off;
      this->style()->drawPrimitive(QStyle::PE_IndicatorCheckBox, &option, painter);
    }

  }
  void mousePressEvent(QMouseEvent *event)
  {
    if (isOn)
      isOn = false;
    else
      isOn = true;
    this->update();
    QHeaderView::mousePressEvent(event);
  }
private:
  bool isOn;
};

#endif // HEADERVIEWEX_H
