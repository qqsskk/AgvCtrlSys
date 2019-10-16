#ifndef CONFIGFORM_H
#define CONFIGFORM_H

#include <QWidget>

namespace Ui {
class ConfigForm;
}

class ConfigForm : public QWidget
{
    Q_OBJECT

public:
    explicit ConfigForm(QWidget *parent = nullptr);
    ~ConfigForm();

private slots:
    void on_pushButtonSetDb_clicked();

    void on_pushButtonSetNet_clicked();

    void on_pushButtonAddDev_clicked();

private:
    Ui::ConfigForm *ui;
};

#endif // CONFIGFORM_H
