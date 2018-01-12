#ifndef CARLEAVE_H
#define CARLEAVE_H

#include <QDialog>
#include <string>
using namespace std;

namespace Ui {
class CarLeave;
}

class CarLeave : public QDialog
{
    Q_OBJECT

public:
    explicit CarLeave(QWidget *parent = 0);
    ~CarLeave();
    void setAll(string strEnterTime, string strLeaveTime, string strStayTime, int intFee);

private:
    Ui::CarLeave *ui;
};

#endif // CARLEAVE_H
