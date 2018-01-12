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
    bool nameEdited();
    string getCarNo();
    string getCarColor();
    time_t getArriveTime();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::CarEdit *ui;
    bool edited;
};

#endif // CAREDIT_H
