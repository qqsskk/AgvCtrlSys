#ifndef LINEEDITEX_H
#define LINEEDITEX_H

#include <QLineEdit>

class LineEditEx : public QLineEdit
{
    Q_OBJECT
public:
   explicit LineEditEx(QWidget *parent = 0);
private:
    void init();
};

#endif // LINEEDITEX_H
