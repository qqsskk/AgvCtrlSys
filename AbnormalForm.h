#ifndef ABNORMALFORM_H
#define ABNORMALFORM_H

#include <QWidget>

namespace Ui {
class AbnormalForm;
}

class AbnormalForm : public QWidget
{
    Q_OBJECT

public:
    explicit AbnormalForm(QWidget *parent = nullptr);
    ~AbnormalForm();

private:
    Ui::AbnormalForm *ui;
};

#endif // ABNORMALFORM_H
