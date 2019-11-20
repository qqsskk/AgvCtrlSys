#ifndef LOGINSETFORM_H
#define LOGINSETFORM_H

#include <QWidget>
#include "Config.h"
#include "MsgBoxEx.h"
#include <QSerialPort>
#include <QSerialPortInfo>

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
    void onEyeToggled(bool checked);

    void on_pushButtonCancel_clicked();

    void on_pushButtonOk_clicked();

    void onCloseLoginSetForm();
    void on_comboBoxComName_currentTextChanged(const QString &arg1);

signals:
    void setFormClosed();


private:
    Ui::LoginSetForm *ui;
    QMap<QString, QString> m_mapSerialPort;
    void init();
};

#endif // LOGINSETFORM_H
