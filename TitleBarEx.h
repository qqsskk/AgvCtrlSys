#ifndef TITLEBAREX_H
#define TITLEBAREX_H

#include <QtWidgets>

enum ButtonType
{
	MINI_BUTTON, //最小化按钮和关闭按钮
	MINI_MAX_BUTTON, //最小化、最大化、还原和关闭按钮
	ONLY_CLOSE_BUTTON //关闭按钮
};

class TitleBarEx : public QWidget
{
	Q_OBJECT

public:
    explicit TitleBarEx(QWidget* parent = 0);
    ~TitleBarEx();
	
	void init(); //初始化
	void setButtonType(ButtonType buttontype); //设置按钮类型
    void setIcon(const QString& fileName); //设置标题栏Icon
    void setTitle(const QString& title); //设置标题栏标题

private:
	void setButtonStyle(); //设置按钮样式

	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);

private slots:
	void miniButtonClicked();
	void restoreButtonClicked();
	void maxButtonClicked();
	void closeButtonClicked();
signals:
    void windowClose();

private:
	QLabel *m_pIconLabel; //表示标题栏Icon
	QLabel *m_pTitleLabel; //表示标题栏标题
	
	QPushButton *m_pMiniButton; //表示最小化按钮
	QPushButton *m_pMaxButton; //表示最大化按钮
	QPushButton *m_pRestoreButton; //表示还原按钮
	QPushButton *m_pCloseButton; //表示关闭按钮

	bool m_isPressed; //鼠标按下flag
	QPoint m_startMovePos; //鼠标移动的初始位置
	ButtonType m_buttonType; //按钮类型
};

#endif //TITLEBAREX_H
