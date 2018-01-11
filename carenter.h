#ifndef CARENTER_H
#define CARENTER_H

#include <QDialog>
#include <string>
#include "vehicle.h"

namespace Ui {
class CarEnter;
}

class CarEnter : public QDialog
{
    Q_OBJECT

public:
    explicit CarEnter(QWidget *parent = 0);
    ~CarEnter();
    string getCarNo();
    string getCarColor();
    CarType getCarType();

private:
    Ui::CarEnter *ui;
};

#endif // CARENTER_H
