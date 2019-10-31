#ifndef DRAWINGPAPEREDITOR_H
#define DRAWINGPAPEREDITOR_H

#include <QWidget>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QPoint>


class DrawingPaperEditor : public QWidget
{
    Q_OBJECT
public:
    explicit DrawingPaperEditor(QWidget *parent);
    ~DrawingPaperEditor() override;


protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private:
    // 按像素计算纸张宽度
    double CalcPaperWidthOfPerPixel(double scale, int paperWidth, int widgetWidth);

    // 按像素更新纸张宽度
    void UpdatePaperWidthOfPerPixel();

    // 画画纸
    void DrawPaper(QPainter &painter);

    // 纸张宽度转绘图宽度
    int PaperWidth2DrawWidth(int paperWidth);

    // 绘图宽度转纸张宽度
    int DrawWidth2PaperWidth(int drawWidth);

    // 响应鼠标中轮值改变
    void OnWheelValueChanged(QPoint mouse_pos, QPoint step);

    // 鼠标点转纸张点
    QPoint MousePoint2PaperPoint(QPoint point);

    // 中心纸张
    void CenterThePaper();


private:
    QColor m_colorBg;           // 背景色
    QColor m_colorPaperBg;      // 画布背景色

    int m_paperX;               // 画布x点
    int m_paperY;               // 画布y点
    int m_paperWidth;           // 画布宽度
    int m_paperHeight;           // 画布高度


    double m_scale;             // 缩放比例
    double m_paperWidthOfPerPixel;  // 画布宽度像素

    bool m_isMouseLDown;   // 鼠标左键按下
    bool m_isMouseRDown;    // 鼠标右键按下

    QPoint m_pointMouseDown;    // 鼠标按下时的坐标
    int orginDifX;      // 原点x的差值
    int orginDifY;      // 原点y的差值

    const double SCALE_VALUE_MAX = 20.0;
    const double SCALE_VALUE_MIN = 0.5;

    QRect m_rectPaper;    // 画布


    QPoint m_startPoint;
    QPoint m_endPoint;

};

#endif // DRAWINGPAPEREDITOR_H
