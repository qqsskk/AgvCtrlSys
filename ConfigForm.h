#ifndef CONFIGFORM_H
#define CONFIGFORM_H

#include <QWidget>
#include <QRegExpValidator>
#include <QSqlQuery>
#include "Config.h"
#include "MsgBoxEx.h"
#include <QSerialPort>
#include <QSerialPortInfo>


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

    void onNetServerStateChange(bool isLink);
    void onSerialPortStateChange(bool isOpen);
    void on_pushButtonSetCom_clicked();

    void on_comboBoxComName_currentTextChanged(const QString &arg1);

    void on_pushButtonRefresh_clicked();

private:
    Ui::ConfigForm *ui;

    QMap<QString, QString> m_mapSerialPort;

private:
    void init();
    void updatePort();

};

#endif // CONFIGFORM_H
