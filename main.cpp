#include "carparkmanagement.h"
#include <QApplication>
#include <QTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CarParkManagement w;
    w.show();

    return a.exec();
}
