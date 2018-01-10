#ifndef CARPARKMANAGEMENT_H
#define CARPARKMANAGEMENT_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include "carenter.h"
#include "employee.h"
#include "searchcar.h"
#include "management.h"

namespace Ui {
class CarParkManagement;
}

class CarParkManagement : public QMainWindow
{
    Q_OBJECT

public:
    explicit CarParkManagement(QWidget *parent = 0);
    ~CarParkManagement();

private slots:
    void on_carEnter_clicked();
    void on_employeeManage_clicked();
    void on_retriveCar_clicked();
    void updateTime();
    void updateVehicleTree();

private:
    Ui::CarParkManagement *ui;
    QTime *myTime;
    CarEnter *carenter;
    Employee *employee;
    SearchCar *searchcar;
    Management management;
};

#endif // CARPARKMANAGEMENT_H
