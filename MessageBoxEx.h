#ifndef MESSAGEBOXEX_H
#define MESSAGEBOXEX_H

#include <QMessageBox>
#include <QTimer>
#include <QIcon>
#include <QAbstractButton>
#include <QDebug>
#include <QPushButton>

enum MessageBoxMode {
    MessageBoxMode_OnlyHint,
    MessageBoxMode_Normal
};

enum MessageBoxBtnType {
    MessageBoxBtnType_Ok,
    MessageBoxBtnType_OkCancle
};

class MessageBoxEx : public QMessageBox
{
    Q_OBJECT
public:
    explicit MessageBoxEx(QWidget *parent = 0);

private:
    MessageBoxMode m_msgBoxMode;
    QString m_strTitle;
    QString m_strContent;
    MessageBoxBtnType m_msgBoxBtnType;

    QPushButton *m_pBtnOk;
    QPushButton *m_pBtnCancel;
public:
    void setMessageBoxMode(QString content);
    void setMessageBoxMode(QString content, QString title, MessageBoxBtnType btnType = MessageBoxBtnType::MessageBoxBtnType_Ok);
    void updateMessageBoxMode();

signals:
    void btnOkClicked();
    void btnCancelClicked();

private slots:
    void onOkClicked();
    void onCancelClicked();

};

#endif // MESSAGEBOXEX_H
