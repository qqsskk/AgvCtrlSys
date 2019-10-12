#ifndef HISTORYFORM_H
#define HISTORYFORM_H

#include <QWidget>

namespace Ui {
class HistoryForm;
}

class HistoryForm : public QWidget
{
    Q_OBJECT

public:
    explicit HistoryForm(QWidget *parent = nullptr);
    ~HistoryForm();

private:
    Ui::HistoryForm *ui;
};

#endif // HISTORYFORM_H
