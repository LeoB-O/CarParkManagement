#ifndef CAREDIT_H
#define CAREDIT_H

#include <QDialog>
#include <string>
using namespace std;

namespace Ui {
class CarEdit;
}

class CarEdit : public QDialog
{
    Q_OBJECT

public:
    explicit CarEdit(QWidget *parent = 0);
    ~CarEdit();
    void setAll(string carNo, string carColor, long long carEnterTime);
    string getCarNo();
    string getCarColor();
    time_t getArriveTime();

private:
    Ui::CarEdit *ui;
};

#endif // CAREDIT_H
