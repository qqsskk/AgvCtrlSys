#ifndef MAPFORM_H
#define MAPFORM_H

#include <QWidget>
#include <QDebug>
#include <QVBoxLayout>
#include "DrawingPaperEditor.h"
#include <QPainter>
#include <QMap>
#include <QSqlQuery>
#include <QMenu>
#include "graphic/GraphicMap.h"
#include "MsgBoxEx.h"


namespace Ui {
class MapForm;
}

class MapForm : public QWidget
{
    Q_OBJECT

public:
    explicit MapForm(QWidget *parent = nullptr);
    ~MapForm();

private:
    Ui::MapForm *ui;
    DrawingPaperEditor *m_paper;

    GraphicMap *m_pMap;
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private slots:
    void onUpdateMapMenuEvent();
    void onBtnOkClicked();
    void onBtnCancelClicked();
    void onCursorChange();

};

#endif // MAPFORM_H
