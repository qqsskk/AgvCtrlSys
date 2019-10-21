﻿#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>
#include <QTimer>
#include "MsgBoxEx.h"
#include "MainWindow.h"
#include "LoginSetForm.h"
#include "Config.h"

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_exit_clicked();

    void onBtnOkClicked();
    void onBtnCancelClicked();

    void onLoginMainWindow();

    void onSetClicked();
private:
    Ui::LoginForm *ui;

    MainWindow *mainWindow;

    QString m_userName;
    QString m_userPasswd;
    int m_userLevel;
    LoginSetForm *m_loginSetForm;

private:
    bool linkdb();
};

#endif // LOGINFORM_H