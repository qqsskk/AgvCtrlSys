#include "MsgBoxEx.h"

MsgBoxEx::MsgBoxEx(QWidget *parent) : QMessageBox(parent)
{
    setWindowIcon(QIcon("./res/icon/sys.png"));
    setWindowTitle(QString::fromLocal8Bit("系统提示"));
    m_pBtnCancel = addButton(QString::fromLocal8Bit("取消"), QMessageBox::AcceptRole);
    m_pBtnOk = addButton(QString::fromLocal8Bit("确定"), QMessageBox::AcceptRole);

    // 按钮建立信号槽
    connect(m_pBtnOk, SIGNAL(clicked()), this, SLOT(onOkClicked()));
    connect(m_pBtnCancel, SIGNAL(clicked()), this, SLOT(onCancelClicked()));
}


void MsgBoxEx::setMsgBoxMode(QString content, int delayTime)
{
    m_strContent = content;
    m_nDelayTime = delayTime;
    m_msgBoxMode = MsgBoxMode::MsgBoxMode_OnlyHint;

    updateMsgBoxMode();
}
void MsgBoxEx::setMsgBoxMode(QString content, QString title, MsgBoxBtnType btnType)
{
    m_strContent = content;
    m_strTitle = title;
    m_msgBoxBtnType = btnType;
    m_msgBoxMode = MsgBoxMode::MsgBoxMode_Normal;

    updateMsgBoxMode();
}
void MsgBoxEx::updateMsgBoxMode()
{
    setWindowFlags(Qt::FramelessWindowHint);
    setText("\n"+m_strContent);
    switch (m_msgBoxMode)
    {
        case MsgBoxMode::MsgBoxMode_OnlyHint:
        {
            removeButton(m_pBtnOk);
            removeButton(m_pBtnCancel);
            setStyleSheet("QMessageBox{background-color:#000000}\
                           QLabel{font: 12pt Microsoft YaHei; font-weight: bold; color:#FFFFFF}");
            addButton(QMessageBox::Ok);
            button(QMessageBox::Ok)->hide();
            show();
            QTimer::singleShot(m_nDelayTime, this, SLOT(close()));

            exec();
        }
            break;
        case MsgBoxMode::MsgBoxMode_Normal:
        {
            setStyleSheet("QMessageBox{background-color:#000000}\
                           QLabel{font: 12pt Microsoft YaHei; font-weight: bold; color:#FFFFFF}\
                           QPushButton{background:#FFFFFF; border-radius:5px; font-size:10pt; \
                            font-family:Microsoft YaHei; color:#000000; width:65; height:25} \
                            QPushButton::hover{background:#4EB485; color:#FFFFFF} \
                            QPushButton::pressed{background:#34373E; color:#FFFFFF}");

            switch(m_msgBoxBtnType)
            {
                case MsgBoxBtnType_Ok:
                     removeButton(m_pBtnCancel);
                break;
                case MsgBoxBtnType_OkCancle:
                break;
            }
              exec();
        }
            break;
    }
}

void MsgBoxEx::onOkClicked()
{
    emit btnOkClicked();
}
void MsgBoxEx::onCancelClicked()
{
    emit btnCancelClicked();
}
