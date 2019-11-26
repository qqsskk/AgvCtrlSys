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
    this->resize(QSize(1600, 900));
    this->setFixedSize(this->width(),this->height());

    // 窗口标题栏
    setWindowIcon(QIcon("./res/icon/sys.png"));
    setWindowTitle(QString::fromLocal8Bit("AGV调度系统"));
    setWindowFlags(Qt::CustomizeWindowHint | Qt::Window | Qt::FramelessWindowHint);
    TitleBarEx *pTitleBar = new TitleBarEx(this);
    pTitleBar->setIcon("./res/icon/main.png");
    pTitleBar->setButtonType(MINI_MAX_BUTTON);
    pTitleBar->setTitle(QString::fromLocal8Bit("  AGV 调度系统"));
    connect(pTitleBar, SIGNAL(windowClose()), this, SLOT(onWindowClose())); // 绑定信号槽


    // 主页
    ui->tabWidget->setStyleSheet("QTabWidget::pane{border-left:1px solid #31343B;}\
            QTabBar::tab:last:!selected {border-image: url(./res/icon/error_normal.png);}\
            QTabBar::tab:last:selected {border-image: url(./res/icon/error_pressed.png);}");
    ui->tabWidget->setTabPosition(QTabWidget::West);
    ui->tabWidget->tabBar()->setStyle(new CustomTabStyle);
    MapForm *pMapForm = new MapForm();
    ui->tabWidget->addTab(pMapForm, QString::fromLocal8Bit("地图信息"));
    connect(this, SIGNAL(showAgv(quint32,QString,quint32,bool,bool,bool,bool)), pMapForm, SLOT(onShowAgv(quint32,QString,quint32,bool,bool,bool,bool)));
    connect(this, SIGNAL(hideAgv(quint32)), pMapForm, SLOT(onHideAgv(quint32)));
    TaskForm *pTaskForm = new TaskForm();
    ui->tabWidget->addTab(pTaskForm, QString::fromLocal8Bit("任务信息"));
    connect(pTaskForm, SIGNAL(createTask(QString,QString)), this, SLOT(onCreateTask(QString,QString)));
    HistoryForm *pHistoryForm = new HistoryForm();
    ui->tabWidget->addTab(pHistoryForm, QString::fromLocal8Bit("历史信息"));
    DeviceStateForm *pDeviceStateForm = new DeviceStateForm();
    ui->tabWidget->addTab(pDeviceStateForm, QString::fromLocal8Bit("设备状态"));
    ModulesForm *pModulesForm = new ModulesForm();
    ui->tabWidget->addTab(pModulesForm, QString::fromLocal8Bit("模块信息"));
    connect(pModulesForm, SIGNAL(callerEnable(int, bool)), this, SLOT(onCallerEnable(int, bool)));
    connect(this, SIGNAL(updateCallerData()), pModulesForm, SLOT(onUpdateCallerData()));
    UserForm *pUserForm = new UserForm(m_userName, m_userPasswd, m_userLevel);
    ui->tabWidget->addTab(pUserForm, QString::fromLocal8Bit("用户信息"));
    // 根据用户权限添加功能
    ConfigForm *pConfigForm = new ConfigForm();
    ui->tabWidget->addTab(pConfigForm, QString::fromLocal8Bit("系统配置"));
    connect(this, SIGNAL(netServerStateChange(QString)), pConfigForm, SLOT(onNetServerStateChange(QString)));
    connect(this, SIGNAL(serialPortStateChange(QString)), pConfigForm, SLOT(onSerialPortStateChange(QString)));
    switch(m_userLevel)
    {
        case UserLevel::UserLevel_High:
        // 只有最高权限需显示用户信息页的用户设置组
        pUserForm->visibleUsersetGroup();
        break;
    }
    AbnormalForm *pAbnormalForm = new AbnormalForm();
    connect(pAbnormalForm, SIGNAL(updateAbnormalExist(bool)), this, SLOT(onUpdateAbnormalExist(bool)));
    ui->tabWidget->addTab(pAbnormalForm, QString::fromLocal8Bit("                 ")); // 异常信息

    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::onWindowClose()
{
    MsgBoxEx *msgBox = new MsgBoxEx();
    connect(msgBox, SIGNAL(btnOkClicked()), this, SLOT(onBtnOkClicked()));
    connect(msgBox, SIGNAL(btnCancelClicked()), this, SLOT(onBtnCancelClicked()));
    msgBox->setMsgBoxMode(QString::fromLocal8Bit("确定要退出系统吗？"), "", MsgBoxBtnType::MsgBoxBtnType_OkCancle);
    delete msgBox;
}
void MainWindow::onBtnOkClicked()
{
    delete this;
    qApp->quit();
}

void MainWindow::onBtnCancelClicked(){}

void MainWindow::onUpdateAbnormalExist(bool exist)
{
    if(exist)
    {
        ui->tabWidget->setStyleSheet("QTabWidget::pane{border-left:1px solid #31343B;}\
                                      QTabBar::tab:last:!selected {border-image: url(./res/icon/error_normal_corner.png);}\
                                      QTabBar::tab:last:selected {border-image: url(./res/icon/error_pressed_corner.png);}");

    }
    else
    {
        ui->tabWidget->setStyleSheet("QTabWidget::pane{border-left:1px solid #31343B;}\
                                       QTabBar::tab:last:!selected {border-image: url(./res/icon/error_normal.png);}\
                                       QTabBar::tab:last:selected {border-image: url(./res/icon/error_pressed.png);}");
    }
}

void MainWindow::onCallerEnable(int id, bool enable)
{
    emit callerEnable(id, enable);
}

void MainWindow::onCreateTask(QString workName, QString taskDetails)
{
    emit createTask(workName, taskDetails);
}
