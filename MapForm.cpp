﻿#include "MapForm.h"
#include "ui_MapForm.h"

#include <QStyleOption>
MapForm::MapForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapForm)
{
    ui->setupUi(this);


this->grabKeyboard();

   // updateMapRelateTable("");

    m_pMap = new GraphicMap(this);


}

MapForm::~MapForm()
{
    delete ui;

    if(m_pMap)
    {
        delete m_pMap;
        m_pMap = nullptr;
    }
}

void MapForm::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);

    QStyleOption opt;
    opt.initFrom(this);
    style()->drawPrimitive(QStyle::PE_FrameDefaultButton, &opt, &painter, this);


    m_pMap->drawMap(painter);
}


void MapForm::wheelEvent(QWheelEvent *event)
{
    // 鼠标中轮“缩放”操作
    if (m_pMap)
    {
        m_pMap->wheel(event->delta()>=0 ? false : true);
        event->accept();
        this->update();
    }
}

void MapForm::mousePressEvent(QMouseEvent *event)
{
    // 鼠标中键按下“选择”操作
    if(event->button() == Qt::MidButton)
    {
        if (m_pMap)
        {
            m_pMap->select(BUTTONCTRL_MDOWN, event->pos());
        }
        event->accept();
        this->update();
    }

    // Alt+鼠标右键弹出更新地图菜单
    else if(event->button() == Qt::RightButton && event->modifiers()==Qt::AltModifier)
    {
        QMenu *pMenu = new QMenu(this);
        pMenu->setStyleSheet("QMenu {background-color: #323334; border:none; font-size:12pt; font-family:Microsoft YaHei; color:#D0D0D0}\
                        QMenu::item {background-color: transparent; padding:8px 32px; margin:0px 0px;}\
                        QMenu::item:selected {background-color:#1E1F1F; color:#FFFFFF}\
                        QMenu::item:!selected {background-color:#323334; color:#D0D0D0}");
        QAction *pActionUpdateMap = new QAction(QString::fromLocal8Bit("更新地图"), this);
        pActionUpdateMap->setData(1);
        pMenu->addAction(pActionUpdateMap);
        connect(pActionUpdateMap, SIGNAL(triggered()), this, SLOT(onUpdateMapMenuEvent()));
        QPoint pos = cursor().pos();
        pos.setX(pos.x() + 5);
        pMenu->exec(pos);

        delete pActionUpdateMap;
        delete pMenu;
    }
}

void MapForm::mouseReleaseEvent(QMouseEvent *event)
{
    // 鼠标中键抬起“提交”操作
    if(event->button() == Qt::MidButton)
    {
        if (m_pMap)
        {
            m_pMap->confirm(BUTTONCTRL_MUP, event->pos());
            QCursor cursor = m_pMap->drag(event->pos()); // 完成拖拽需再调用一次
            this->setCursor(cursor);
        }
        event->accept();
        this->update();
    }
}

void MapForm::mouseMoveEvent(QMouseEvent *event)
{
    // 鼠标中键按下且移动为“拖拽”操作
    if(event->buttons() & Qt::MidButton)
    {
        if (m_pMap)
        {
           QCursor cursor = m_pMap->drag(event->pos());
           this->setCursor(cursor);
        }
        event->accept();
        this->update();
    }
}

void MapForm::onUpdateMapMenuEvent()
{
    MsgBoxEx *msgBox = new MsgBoxEx();
    connect(msgBox, SIGNAL(btnOkClicked()), this, SLOT(onBtnOkClicked()));
    connect(msgBox, SIGNAL(btnCancelClicked()), this, SLOT(onBtnCancelClicked()));
    msgBox->setMsgBoxMode(QString::fromLocal8Bit("与地图相关数据将会被新地图数据覆盖，\n此操作不可逆，确定更新吗？"), "", MsgBoxBtnType::MsgBoxBtnType_OkCancle);
}
void MapForm::onBtnOkClicked()
{
    QFile file("./res/set/map.map");
    if (!file.exists())
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("未找到 ./res/set/map.map 地图文件,请检查此文件是否在！"));
        return;
    }

    if(m_pMap->updateMapRelateTable("./res/set/map.map") == true)
    {
       m_pMap->loadMapElement();
    }
}

void MapForm::onBtnCancelClicked()
{
    // 无需实现
}
