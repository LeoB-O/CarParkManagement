#ifndef CARPARKMANAGEMENT_H
#define CARPARKMANAGEMENT_H

#include <iostream>
#include <ctime>
#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QTreeWidgetItem>
#include <QMessageBox>
#include "otherfun.h"
#include "carenter.h"
#include "employee.h"
#include "searchcar.h"
#include "management.h"
#include "carleave.h"
#include "caredit.h"

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
    void updateStayTime();
    void updateParkPlaceNum();
    void on_carInfo_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_pushButton_clicked();

private:
    Ui::CarParkManagement *ui;
    QTime *myTime;
    CarEnter *carenter;
    CarLeave *carLeave;
    Employee *employee;
    SearchCar *searchcar;
    CarEdit *caredit;
    Management management;
    void init();
    time_t getCurrentTime();
};

#endif // CARPARKMANAGEMENT_H
