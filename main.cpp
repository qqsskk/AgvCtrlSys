#include <QApplication>
#include "LoginForm.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginForm loginForm;
    loginForm.show();

    QSharedMemory shared("agv-ctrl-system");
    if(shared.attach()) { return 0; }
    shared.create(1);

    return a.exec();
}
