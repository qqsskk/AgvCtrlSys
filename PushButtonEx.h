#ifndef PUSHBUTTONEX_H
#define PUSHBUTTONEX_H

#include <QPushButton>

class PushButtonEx : public QPushButton
{
    Q_OBJECT
public:
    explicit PushButtonEx(QWidget *parent = 0);


private:
    void init();
};

#endif // PUSHBUTTONEX_H
