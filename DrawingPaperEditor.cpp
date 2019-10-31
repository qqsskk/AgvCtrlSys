#include "DrawingPaperEditor.h"
#include <QPainter>

DrawingPaperEditor::DrawingPaperEditor(QWidget *parent)
    : QWidget(parent)
{

    m_colorBg = QColor(54, 54, 54);
    m_colorPaperBg = QColor(27, 27, 27);

    m_paperX = 0;
    m_paperY = 0;
    m_paperWidth = 1000;
    m_paperHeight = 1000;

    m_scale = 0.9;

    m_isMouseLDown = false;
    m_isMouseRDown = false;


    UpdatePaperWidthOfPerPixel();

}

DrawingPaperEditor::~DrawingPaperEditor()
{

}

void DrawingPaperEditor::paintEvent(QPaintEvent *event)
{

    Q_UNUSED(event)
    QPainter painter(this);

    //draw bg
//    QRect frame_rect = this->rect();
//    painter.fillRect(frame_rect, QBrush(editor_bg_color_));

    DrawPaper(painter);
}

void DrawingPaperEditor::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    if(event->buttons() & Qt::LeftButton)
    {
        m_isMouseLDown = true;
    }
    else if(event->buttons() & Qt::RightButton)
    {
        m_pointMouseDown = event->pos();

        orginDifX = m_pointMouseDown.x() - m_paperX;
        orginDifY = m_pointMouseDown.y() - m_paperY;

        m_isMouseRDown = true;
    }





    m_startPoint = event->pos();
}

void DrawingPaperEditor::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    if(m_isMouseRDown == true) {

        m_paperX = event->pos().x() - orginDifX;
        m_paperY = event->pos().y() - orginDifY;
        update();
    }



    m_endPoint = event->pos();
}

void DrawingPaperEditor::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)

    m_isMouseLDown = false;
    m_isMouseRDown = false;




    m_endPoint = event->pos();
}

void DrawingPaperEditor::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    UpdatePaperWidthOfPerPixel();

    CenterThePaper();
}

void DrawingPaperEditor::enterEvent(QEvent *event)
{
    Q_UNUSED(event)
}

void DrawingPaperEditor::leaveEvent(QEvent *event)
{
    Q_UNUSED(event)
}

void DrawingPaperEditor::wheelEvent(QWheelEvent *event)
{
    Q_UNUSED(event)

    QPoint numPixels = event->pixelDelta();
    QPoint numDegrees = event->angleDelta() / 8;

    if (!numPixels.isNull()) {
        OnWheelValueChanged(event->pos(),numPixels);
    } else if (!numDegrees.isNull()) {
        QPoint numSteps = numDegrees / 15;
        OnWheelValueChanged(event->pos(), numSteps);
    }
    event->accept();
}

//scale_value : 0.5~ 20
//paper_width :
//widget_width :
double DrawingPaperEditor::CalcPaperWidthOfPerPixel(double scale, int paperWidth, int widgetWidth)
{
    int paper_width_of_final_show = paperWidth ;//+ static_cast<int>(static_cast<double>(paper_width )* 0.2);
    int scaled_widget_width = qRound(static_cast<double>(widgetWidth) * scale);

    double paper_width_of_per_pixel =  static_cast<double>(paper_width_of_final_show) / static_cast<double>(scaled_widget_width);

    //limit readable per-pixel value
    if(paper_width_of_per_pixel < 0.0005) paper_width_of_per_pixel = 0.0005;
    return paper_width_of_per_pixel;
}

//re-calc  "paper_width_of_per_pixel" only when : init, resize, scale_value changed
void DrawingPaperEditor::UpdatePaperWidthOfPerPixel()
{
    if(this->height() >= this->width())
    {
        m_paperWidthOfPerPixel = CalcPaperWidthOfPerPixel(m_scale, m_paperWidth, this->width());
    }
    else
    {
        m_paperWidthOfPerPixel = CalcPaperWidthOfPerPixel(m_scale, m_paperWidth, this->height());
    }
}

int DrawingPaperEditor::PaperWidth2DrawWidth(int paperWidth)
{
    double drawWidth = static_cast<double>(paperWidth) / m_paperWidthOfPerPixel;
    return qRound(drawWidth);
}

int DrawingPaperEditor::DrawWidth2PaperWidth(int drawWidth)
{
    double paperWidth = static_cast<double>(drawWidth) * m_paperWidthOfPerPixel;
    return static_cast<int>(qRound(paperWidth));
}

void DrawingPaperEditor::OnWheelValueChanged(QPoint mouse_pos, QPoint step)
{
    //if mouse point in paper
    if(m_rectPaper.contains(mouse_pos))
    {
        QPoint before_resize_mouse_point_at_paper =  MousePoint2PaperPoint(mouse_pos);
        int temp_paper_point_x = DrawWidth2PaperWidth(before_resize_mouse_point_at_paper.x());
        int temp_paper_point_y = DrawWidth2PaperWidth(before_resize_mouse_point_at_paper.y());

        //resize
        int step_value =  step.y();
        m_scale += static_cast<double>(step_value) /20.0;
        if(m_scale > SCALE_VALUE_MAX) m_scale = SCALE_VALUE_MAX;
        if(m_scale < SCALE_VALUE_MIN) m_scale = SCALE_VALUE_MIN;
        UpdatePaperWidthOfPerPixel();

        int temp_draw_point_x = PaperWidth2DrawWidth(temp_paper_point_x);
        int temp_draw_point_y = PaperWidth2DrawWidth(temp_paper_point_y);
        QPoint after_resize_mouse_point_at_paper(temp_draw_point_x, temp_draw_point_y);


        QPoint should_move_length = after_resize_mouse_point_at_paper - before_resize_mouse_point_at_paper;

        m_paperX -= should_move_length.x();
        m_paperY -= should_move_length.y();

        update();

    }
    else
    { //else using center resize
        int old_width = m_rectPaper.width();
        int old_height = m_rectPaper.height();

        //resize
        int step_value =  step.y();
        m_scale += static_cast<double>(step_value) /20.0;
        if(m_scale > SCALE_VALUE_MAX) m_scale = SCALE_VALUE_MAX;
        if(m_scale < SCALE_VALUE_MIN) m_scale = SCALE_VALUE_MIN;
        UpdatePaperWidthOfPerPixel();

        int new_width = PaperWidth2DrawWidth(m_paperWidth);
        int new_height = PaperWidth2DrawWidth(m_paperHeight);

        int adjusted_height = new_height - old_height;
        int adjusted_width = new_width - old_width;

        m_paperX -= adjusted_width/2;
        m_paperY -= adjusted_height/2;

        update();
    }
}

void DrawingPaperEditor::DrawPaper(QPainter &painter)
{
    int width = PaperWidth2DrawWidth(m_paperWidth);
    int height = PaperWidth2DrawWidth(m_paperHeight);

    m_rectPaper.setX(m_paperX);
    m_rectPaper.setY(m_paperY);
    m_rectPaper.setWidth(width);
    m_rectPaper.setHeight(height);
    painter.fillRect(m_rectPaper, QBrush(m_colorPaperBg));

    double stepWidth = static_cast<double>(width) / 100.0;

    painter.setPen(QPen(Qt::white));

    int startX = m_paperX + qRound(stepWidth / 2);
    int startY = m_paperY + qRound(stepWidth / 2);

    for(int y = 0; y < 100; y ++)
    {
        for(int x = 0; x < 100; x++)
        {
            int pointX = startX + qRound(x * stepWidth);
            int pointY = startY + qRound(y * stepWidth);
            painter.drawPoint(pointX, pointY);
        }
    }


//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.setBrush(QBrush(Qt::yellow));
//    QRect windowRect = painter.window();
//    painter.setWindow(windowRect.x(), windowRect.height(), windowRect.width(), -windowRect.height());
   painter.setPen(QPen(QColor(255,0,0), 5));
  painter.drawLine(m_startPoint, m_endPoint);

//   painter.drawLine(QPoint(-60,-10), QPoint(-60,-110));
//   painter.drawLine(QPoint(40,-40), QPoint(40,-60));
//   painter.drawLine(QPoint(-80,-110), QPoint(-80,-140));
   painter.drawLine(QPoint(60,110), QPoint(60,200));

}

QPoint DrawingPaperEditor::MousePoint2PaperPoint(QPoint point)
{
    QPoint ret;
    ret.setX(point.x() - m_paperX);
    ret.setY(point.y() - m_paperY);
    return ret;
}

void DrawingPaperEditor::CenterThePaper()
{

    m_paperWidthOfPerPixel = 0.9;
    UpdatePaperWidthOfPerPixel();
    int adjust_distance_x = (this->width() - PaperWidth2DrawWidth(m_paperWidth)) / 2;
    int adjust_distance_y = (this->height() - PaperWidth2DrawWidth(m_paperHeight)) / 2;

    m_paperX = adjust_distance_x;
    m_paperY = adjust_distance_y;
    update();
}


