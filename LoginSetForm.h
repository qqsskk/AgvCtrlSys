#ifndef LOGINSETFORM_H
#define LOGINSETFORM_H

#include <QWidget>
#include "Config.h"
#include "MsgBoxEx.h"

namespace Ui {
class LoginSetForm;
}

class LoginSetForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginSetForm(QWidget *parent = nullptr);
    ~LoginSetForm();

private slots:
    void on_pushButtonCancel_clicked();

    void on_pushButtonOk_clicked();

private:
    Ui::LoginSetForm *ui;
};

#endif // LOGINSETFORM_H
