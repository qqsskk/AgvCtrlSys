#ifndef MSGBOXEX_H
#define MSGBOXEX_H

#include <QMessageBox>
#include <QTimer>
#include <QIcon>
#include <QAbstractButton>
#include <QDebug>
#include <QPushButton>

enum MsgBoxMode {
    MsgBoxMode_OnlyHint,
    MsgBoxMode_Normal
};

enum MsgBoxBtnType {
    MsgBoxBtnType_Ok,
    MsgBoxBtnType_OkCancle
};

class MsgBoxEx : public QMessageBox
{
    Q_OBJECT
public:
    explicit MsgBoxEx(QWidget *parent = 0);

private:
    MsgBoxMode m_msgBoxMode;
    QString m_strTitle;
    QString m_strContent;
    int m_nDelayTime;
    MsgBoxBtnType m_msgBoxBtnType;

    QPushButton *m_pBtnOk;
    QPushButton *m_pBtnCancel;
public:
    void setMsgBoxMode(QString content, int delayTime=1500);
    void setMsgBoxMode(QString content, QString title, MsgBoxBtnType btnType = MsgBoxBtnType::MsgBoxBtnType_Ok);
    void updateMsgBoxMode();

signals:
    void btnOkClicked();
    void btnCancelClicked();

private slots:
    void onOkClicked();
    void onCancelClicked();

};



#endif // MSGBOXEX_H
