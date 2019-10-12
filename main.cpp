#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QPalette pal(w.palette());
    pal.setColor(QPalette::Background, QColor("#484C55"));
    w.setAutoFillBackground(true);
    w.setPalette(pal);
   // w.showMaximized();
    w.show();

    return a.exec();
}
