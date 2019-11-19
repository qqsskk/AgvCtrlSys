#ifndef MAPFORM_H
#define MAPFORM_H

#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QMap>
#include <QSqlQuery>
#include <QMenu>
#include <QFile>
#include <QMouseEvent>
#include <QStyleOption>
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
public slots:
    // 显示AGV
    void onShowAgv(quint32 unNo, QString strType, quint32 unCurMark, bool bRun, bool bUnVol, bool bObs, bool bError);

    // 隐藏AGV
    void onHideAgv(quint32 unNo);
};

#endif // MAPFORM_H
