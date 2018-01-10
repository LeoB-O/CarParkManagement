#include "carparkmanagement.h"
#include "ui_carparkmanagement.h"

CarParkManagement::CarParkManagement(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CarParkManagement)
{
    ui->setupUi(this);
    ui->lcdNumber->setDigitCount(9);
    myTime = new QTime();
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start(1000);
    updateVehicleTree();
}

CarParkManagement::~CarParkManagement()
{
    delete ui;
}

void CarParkManagement::on_carEnter_clicked()
{
    this->carenter = new CarEnter;
    this->carenter->exec();
}

void CarParkManagement::on_employeeManage_clicked()
{
    this->employee = new Employee;
    this->employee->exec();
}

void CarParkManagement::on_retriveCar_clicked()
{
    this->searchcar = new SearchCar;
    this->searchcar->exec();
}

void CarParkManagement::updateTime()
{
    QString curTime;
    curTime = myTime->currentTime().toString("hh:mm:ss");
    this->ui->lcdNumber->display(curTime);
}

 void CarParkManagement::updateVehicleTree()
 {
     //TODO not finished yet
     QStringList carInfoList;
     Vehicle tempVehicle;
     int x = management.getCarAmount();
     for(int i=0;i<management.getCarAmount();++i)
     {
         tempVehicle=management.getVehicleAtIndex(i);
         carInfoList.append(QString::fromStdString(tempVehicle.getNo()));
         carInfoList.append(QString::fromStdString(tempVehicle.getColor()));
         carInfoList.append(QString::fromStdString(tempVehicle.getStrArriveTime()));
         carInfoList.append(QString::fromStdString(tempVehicle.getStrLeaveTime()));
         switch (tempVehicle.getCarType())
         {
         case car:
             ui->carInfo->topLevelItem(0)->insertChild(0, new QTreeWidgetItem(carInfoList));
             break;
         case smallVan:
             ui->carInfo->topLevelItem(1)->insertChild(0, new QTreeWidgetItem(carInfoList));
             break;
         case middleVan:
             ui->carInfo->topLevelItem(2)->insertChild(0, new QTreeWidgetItem(carInfoList));
             break;
         case HugeVan:
             ui->carInfo->topLevelItem(3)->insertChild(0, new QTreeWidgetItem(carInfoList));
             break;
         default:
             ui->carInfo->topLevelItem(0)->insertChild(0, new QTreeWidgetItem(carInfoList));
             break;
         }
     }
 }
