#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "TitleBarEx.h"
#include "CustomTabStyle.h"
#include "MapForm.h"
#include "TaskForm.h"
#include "DeviceStateForm.h"
#include "UserForm.h"
#include "HistoryForm.h"
#include "AbnormalForm.h"
#include "ConfigForm.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initWindow()
{
    // 窗口初始尺寸
    this->resize(QSize(1280, 800));
    this->setFixedSize(this->width(),this->height());

    // 窗口标题栏
    setWindowIcon(QIcon("./res/icon/devstate.png"));
    setWindowFlags(Qt::CustomizeWindowHint | Qt::Window | Qt::FramelessWindowHint);
    TitleBarEx *pTitle = new TitleBarEx(this);
    pTitle->setIcon("./res/icon/devstate.png");
    pTitle->setButtonType(MINI_MAX_BUTTON);
    pTitle->setTitle(QString::fromLocal8Bit("  AGV 调度系统"));


    // 主页
    // QTabBar::tab:!selected {border-image: url(./res/icon/devstate.png);}
    ui->tabWidget->setStyleSheet("QTabWidget::pane{border-left:1px solid #CCCCCC;}");
    ui->tabWidget->setTabPosition(QTabWidget::West);
    ui->tabWidget->tabBar()->setStyle(new CustomTabStyle);
    MapForm *pMapForm = new MapForm();
    ui->tabWidget->addTab(pMapForm, QString::fromLocal8Bit(" 布局图"));
    TaskForm *pTaskForm = new TaskForm();
    ui->tabWidget->addTab(pTaskForm, QString::fromLocal8Bit("任务信息"));
    HistoryForm *pHistoryForm = new HistoryForm();
    ui->tabWidget->addTab(pHistoryForm, QString::fromLocal8Bit("历史信息"));
    DeviceStateForm *pDeviceStateForm = new DeviceStateForm();
    ui->tabWidget->addTab(pDeviceStateForm, QString::fromLocal8Bit("设备状态"));
    UserForm *pUserForm = new UserForm();
    ui->tabWidget->addTab(pUserForm, QString::fromLocal8Bit("用户信息"));
    AbnormalForm *pAbnormalForm = new AbnormalForm();
    ui->tabWidget->addTab(pAbnormalForm, QString::fromLocal8Bit("异常信息"));
    ConfigForm *pSetForm = new ConfigForm();
    ui->tabWidget->addTab(pSetForm, QString::fromLocal8Bit("系统配置"));
    ui->tabWidget->setIconSize(QSize(32,32));
    ui->tabWidget->setCurrentIndex(2);

//    // 定义调色板
//    QPalette palette0;
//    QPalette palette1;
//    // 设定画刷
//    palette0.setColor(QPalette::Background, QColor::fromRgb(0,200,0));
//    palette1.setColor(QPalette::Background, QColor("#484C55"));
//    // 设定调色板
//    ui->tabWidget->setAutoFillBackground(true);
//    ui->tabWidget->setPalette(palette0);
//    ui->tabWidget->widget(0)->setAutoFillBackground(true);
//    ui->tabWidget->widget(0)->setPalette(palette1);


}


