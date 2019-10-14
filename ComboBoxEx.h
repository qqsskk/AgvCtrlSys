#ifndef COMBOBOXEX_H
#define COMBOBOXEX_H

#include <QComboBox>
#include <QListView>

class ComboBoxEx : public QComboBox
{
    Q_OBJECT
public:
    explicit ComboBoxEx(QWidget *parent = 0);
private:
    void init();
};

#endif // COMBOBOXEX_H
