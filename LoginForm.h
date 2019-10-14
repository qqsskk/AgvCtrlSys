#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDebug>
#include <QTimer>
#include "MessageBoxEx.h"
#include "MainWindow.h"


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

private:
    Ui::LoginForm *ui;

    MainWindow *mainWindow;
};

#endif // LOGINFORM_H
