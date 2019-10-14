#include "MessageBoxEx.h"

MessageBoxEx::MessageBoxEx(QWidget *parent) : QMessageBox(parent)
{
    m_pBtnOk = addButton(QString::fromLocal8Bit("确定"), QMessageBox::AcceptRole);
    m_pBtnCancel = addButton(QString::fromLocal8Bit("取消"), QMessageBox::AcceptRole);

    // 按钮建立信号槽
    connect(m_pBtnOk, SIGNAL(clicked()), this, SLOT(onOkClicked()));
    connect(m_pBtnCancel, SIGNAL(clicked()), this, SLOT(onCancelClicked()));
}


void MessageBoxEx::setMessageBoxMode(QString content)
{
    m_strContent = content;
    m_msgBoxMode = MessageBoxMode::MessageBoxMode_OnlyHint;

    updateMessageBoxMode();
}
void MessageBoxEx::setMessageBoxMode(QString content, QString title, MessageBoxBtnType btnType)
{
    m_strContent = content;
    m_strTitle = title;
    m_msgBoxBtnType = btnType;
    m_msgBoxMode = MessageBoxMode::MessageBoxMode_Normal;

    updateMessageBoxMode();
}
void MessageBoxEx::updateMessageBoxMode()
{
    setWindowFlags(Qt::FramelessWindowHint);
    setText("\n"+m_strContent);
    //setIconPixmap(QPixmap("./res/icon/waring.png"));
    switch (m_msgBoxMode)
    {
        case MessageBoxMode::MessageBoxMode_OnlyHint:
        {
            removeButton(m_pBtnOk);
            removeButton(m_pBtnCancel);
            setStyleSheet("QMessageBox{background-color:#484C55}\
                           QLabel{font: 12pt Microsoft YaHei; font-weight: bold; color:#FFFFFF}");
            addButton(QMessageBox::Ok);
            button(QMessageBox::Ok)->hide();
            show();
            QTimer::singleShot(1500, this, SLOT(close()));
        }
            break;
        case MessageBoxMode::MessageBoxMode_Normal:
        {
            setStyleSheet("QMessageBox{background-color:#484C55}\
                           QLabel{font: 12pt Microsoft YaHei; font-weight: bold; color:#FFFFFF}\
                           QPushButton{background:#FFFFFF; border-radius:5px; font-size:10pt; \
                            font-family:Microsoft YaHei; color:#000000; width:65; height:25} \
                            QPushButton::hover{background:#4EB485; color:#FFFFFF} \
                            QPushButton::pressed{background:#34373E; color:#FFFFFF}");

            switch(m_msgBoxBtnType)
            {
                case MessageBoxBtnType_Ok:
                     removeButton(m_pBtnCancel);
                break;
                case MessageBoxBtnType_OkCancle:
                break;
            }
              exec();
        }
            break;
    }
}

void MessageBoxEx::onOkClicked()
{
    emit btnOkClicked();
}
void MessageBoxEx::onCancelClicked()
{
    emit btnCancelClicked();
}
