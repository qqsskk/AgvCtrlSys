#include "TitleBarEx.h"

#define BUTTON_WIDTH  50 //按钮宽度
#define BUTTON_HEIGHT 50 //按钮高度
#define TITLE_HEIGHT  50 //标题栏高度

TitleBarEx::TitleBarEx(QWidget* parent)
: QWidget(parent)
, m_isPressed(false)
{
	init();
}

TitleBarEx::~TitleBarEx()
{

}

void TitleBarEx::init()
{
	m_pIconLabel = new QLabel;
	m_pTitleLabel = new QLabel;
    m_pTitleLabel->setContentsMargins(5, 0, 0, 0);
    m_pTitleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	m_pMiniButton = new QPushButton;
	m_pMaxButton = new QPushButton;
	m_pRestoreButton = new QPushButton;
	m_pCloseButton = new QPushButton;

	//按钮大小固定
	m_pMiniButton->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    m_pMaxButton->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);
	m_pRestoreButton->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);
	m_pCloseButton->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);
	
	setButtonStyle();

	//对Icon、标题和按钮使用水平布局
	QHBoxLayout *pHLayout = new QHBoxLayout;
	pHLayout->addWidget(m_pIconLabel);
	pHLayout->addWidget(m_pTitleLabel);
	pHLayout->addWidget(m_pMiniButton);
	pHLayout->addWidget(m_pMaxButton);
	pHLayout->addWidget(m_pRestoreButton);
	pHLayout->addWidget(m_pCloseButton);

    pHLayout->setContentsMargins(0, 0, 0, 0);
    pHLayout->setSpacing(0);

	this->setLayout(pHLayout);
	this->setFixedHeight(TITLE_HEIGHT); //标题栏高度固定
	
	//按钮的信号槽连接
	connect(m_pMiniButton, SIGNAL(clicked()), this, SLOT(miniButtonClicked()));
	connect(m_pMaxButton, SIGNAL(clicked()), this, SLOT(maxButtonClicked()));
	connect(m_pRestoreButton, SIGNAL(clicked()), this, SLOT(restoreButtonClicked()));
	connect(m_pCloseButton, SIGNAL(clicked()), this, SLOT(closeButtonClicked()));
}

void TitleBarEx::setButtonType(ButtonType buttontype)
{
	m_buttonType = buttontype;
	switch (buttontype)
	{
	case MINI_BUTTON:
		m_pMaxButton->setVisible(false);
		m_pRestoreButton->setVisible(false);
		break;
	case MINI_MAX_BUTTON:
        m_pRestoreButton->setVisible(false);
		break;
	case ONLY_CLOSE_BUTTON:
		m_pMiniButton->setVisible(false);
		m_pMaxButton->setVisible(false);
		m_pRestoreButton->setVisible(false);
		break;
	}
}

void TitleBarEx::setButtonStyle()
{
    m_pMiniButton->setStyleSheet("QPushButton{border: transparent; border-radius: none; background-color:#31343B;}"
        "QPushButton{border-image:url(./res/icon/min.png);}"
        "QPushButton:hover{border-image:url(./res/icon/min_hover.png);}"
        "QPushButton:pressed{border-image:url(./res/icon/min_pressed.png);}");
    m_pMaxButton->setStyleSheet("QPushButton{border: transparent; border-radius: none; background-color:#31343B;}"
        "QPushButton{border-image:url(./res/icon/max.png);}"
        "QPushButton:hover{border-image:url(./res/icon/max_hover.png);}"
        "QPushButton:pressed{border-image:url(./res/icon/max_pressed.png);}");
    m_pRestoreButton->setStyleSheet("QPushButton{border: transparent; border-radius: none; background-color:#31343B;}"
        "QPushButton{border-image:url(./res/icon/restore.png);}"
        "QPushButton:hover{border-image:url(./res/icon/restore_hover.png);}"
        "QPushButton:pressed{border-image:url(./res/icon/restore_pressed.png);}");
    m_pCloseButton->setStyleSheet("QPushButton{border: transparent; border-radius: none; background-color:#31343B;}"
        "QPushButton{border-image:url(./res/icon/close.png);}"
        "QPushButton:hover{border-image:url(./res/icon/close_hover.png);}"
        "QPushButton:pressed{border-image:url(./res/icon/close_pressed.png);}");
}

void TitleBarEx::setIcon(const QString& fileName)
{
	QPixmap pixmap(fileName);
    m_pIconLabel->setPixmap(pixmap.scaled(55, 35));
    m_pIconLabel->setStyleSheet("QLabel{background-color: #31343B; padding-left: 10px}");
}

void TitleBarEx::setTitle(const QString& title)
{
	m_pTitleLabel->setText(title);
    m_pTitleLabel->setStyleSheet("QLabel{color: #4EB485; background-color: #31343B; font-size: 18pt; font-family: Microsoft YaHei;}");
}

void TitleBarEx::mousePressEvent(QMouseEvent *event)
{
	if (MINI_MAX_BUTTON == m_buttonType)
	{
		if (m_pMaxButton->isVisible())  //窗口处于非最大化状态时
		{
			m_isPressed = true;
			m_startMovePos = event->globalPos();
		}
	}
	else
	{
		m_isPressed = true;
		m_startMovePos = event->globalPos();
	}

	return QWidget::mousePressEvent(event);
}

void TitleBarEx::mouseReleaseEvent(QMouseEvent *event)
{
	m_isPressed = false;

	return QWidget::mouseReleaseEvent(event);
}

void TitleBarEx::mouseDoubleClickEvent(QMouseEvent *event)
{
	if (MINI_MAX_BUTTON == m_buttonType)
	{
		if (m_pMaxButton->isVisible())
		{
			maxButtonClicked();
		}
		else
		{
			restoreButtonClicked();
		}
	}

	return QWidget::mouseDoubleClickEvent(event);
}

void TitleBarEx::mouseMoveEvent(QMouseEvent *event)
{
	if (m_isPressed)
	{
		QPoint moveOffset = event->globalPos() - m_startMovePos;
		QPoint widgetPos = this->parentWidget()->pos();
		m_startMovePos = event->globalPos();
		this->parentWidget()->move(widgetPos.x() + moveOffset.x(), widgetPos.y() + moveOffset.y());
	}
}

void TitleBarEx::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	QPainterPath pathBack;
	pathBack.setFillRule(Qt::WindingFill);
	pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 0, 0);
	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.fillPath(pathBack, QBrush(QColor(255, 255, 255, 0)));

	if (this->width() != this->parentWidget()->width())
	{
		this->setFixedWidth(this->parentWidget()->width());
	}

	update();

	return QWidget::paintEvent(event);
}

void TitleBarEx::miniButtonClicked()
{
	window()->showMinimized();
}

void TitleBarEx::restoreButtonClicked()
{
	window()->showNormal();
	m_pRestoreButton->setVisible(false);
    m_pMaxButton->setVisible(true);
}

void TitleBarEx::maxButtonClicked()
{
	window()->showMaximized();
    m_pRestoreButton->setVisible(true);
	m_pMaxButton->setVisible(false);
}

void TitleBarEx::closeButtonClicked()
{
    emit windowClose();
}
