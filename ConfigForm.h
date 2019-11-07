#ifndef CONFIGFORM_H
#define CONFIGFORM_H

#include <QWidget>
#include <QRegExpValidator>
#include <QSqlQuery>
#include "Config.h"
#include "MsgBoxEx.h"

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

private:
    Ui::ConfigForm *ui;

private:
    void init();
};

#endif // CONFIGFORM_H
