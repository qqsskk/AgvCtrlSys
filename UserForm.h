#ifndef USERFORM_H
#define USERFORM_H

#include <QWidget>
#include "CustomData.h"
#include "MsgBoxEx.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include "CustomTableModel.h"

namespace Ui {
class UserForm;
}

class UserForm : public QWidget
{
    Q_OBJECT

public:
    explicit UserForm(QString user, QString passwd, int level, QWidget *parent = nullptr);
    ~UserForm();
private:
    void init();
    void updateModel();

private slots:
    void on_pushButtonChangePasswd_clicked();

    void on_pushButtonChangePwdCancel_clicked();
    void on_pushButtonChangePwdOk_clicked();

    void on_pushButtonLogoutUser_clicked();

    void onBtnOkClickedLogout();
    void onBtnCancelClickedLogout();

    void onClickedUserList(const QModelIndex&);
    void on_pushButtonUserAdd_clicked();

    void on_pushButtonUserChange_clicked();

    void on_pushButtonUserDel_clicked();

    void onExitProgress();
private:
    Ui::UserForm *ui;
    QSqlQueryModel *m_modelUser;
    QString m_userName;
    QString m_userPasswd;
    int m_userLevel;

public:
    void visibleUsersetGroup();

};

#endif // USERFORM_H
