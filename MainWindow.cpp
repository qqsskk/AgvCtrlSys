#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QString user, QString passwd, int level, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_userName = user;
    m_userPasswd = passwd;
    m_userLevel = level;

    initWindow();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initWindow()
{
    // 窗口背景
    QPalette pal(this->palette());
    pal.setColor(QPalette::Background, QColor("#484C55"));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    // 窗口初始尺寸
    this->resize(QSize(1280, 800));
    this->setFixedSize(this->width(),this->height());

    // 窗口标题栏
    setWindowIcon(QIcon("./res/icon/devstate.png"));
    setWindowFlags(Qt::CustomizeWindowHint | Qt::Window | Qt::FramelessWindowHint);
    TitleBarEx *pTitleBar = new TitleBarEx(this);
    pTitleBar->setIcon("./res/icon/devstate.png");
    pTitleBar->setButtonType(MINI_MAX_BUTTON);
    pTitleBar->setTitle(QString::fromLocal8Bit("  AGV 调度系统"));
    connect(pTitleBar, SIGNAL(windowClose()), this, SLOT(onWindowClose())); // 绑定信号槽


    // 主页
    // QTabBar::tab:!selected {border-image: url(./res/icon/devstate.png);}
    ui->tabWidget->setStyleSheet("QTabWidget::pane{border-left:1px solid #31343B;}");
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

    // 根据用户权限添加功能
    switch(m_userLevel)
    {
        case UserLevel::UserLevel_High:
        {
            ConfigForm *pSetForm = new ConfigForm();
            ui->tabWidget->addTab(pSetForm, QString::fromLocal8Bit("系统配置"));
        }
        break;
    }

    ui->tabWidget->setIconSize(QSize(32,32));
    ui->tabWidget->setCurrentIndex(6);

}

void MainWindow::onWindowClose()
{
    MsgBoxEx *msgBox = new MsgBoxEx();
    connect(msgBox, SIGNAL(btnOkClicked()), this, SLOT(onBtnOkClicked()));
    connect(msgBox, SIGNAL(btnCancelClicked()), this, SLOT(onBtnCancelClicked()));
    msgBox->setMsgBoxMode(QString::fromLocal8Bit("确定要退出系统吗？"),"hello", MsgBoxBtnType::MsgBoxBtnType_OkCancle);
}
void MainWindow::onBtnOkClicked()
{
    qApp->quit();
}

void MainWindow::onBtnCancelClicked()
{
}
