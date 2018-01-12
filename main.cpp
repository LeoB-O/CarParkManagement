#include "carparkmanagement.h"
#include <QApplication>
#include <QTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CarParkManagement w;
    if(!w.isValid())
    {
        a.quit();
        return -1;
    }
    w.show();

    return a.exec();
}
