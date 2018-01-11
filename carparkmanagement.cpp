#include "carparkmanagement.h"
#include "ui_carparkmanagement.h"

CarParkManagement::CarParkManagement(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CarParkManagement)
{
    ui->setupUi(this);
    init();
}

CarParkManagement::~CarParkManagement()
{
    delete ui;
}

void CarParkManagement::on_carEnter_clicked()
{
    //TODO 更行数据库
    this->carenter = new CarEnter;
    this->carenter->exec();
    if(this->carenter->result()!=this->carenter->Accepted)
        return;
    management.carEnter(carenter->getCarNo(),carenter->getCarColor(),carenter->getCarType(),getCurrentTime(),0,management.findFreePos());
    updateVehicleTree();
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
     QStringList carInfoList;
     Vehicle tempVehicle;
     int x = management.getCarAmount();
     ui->carInfo->topLevelItem(0)->takeChildren();
     ui->carInfo->topLevelItem(1)->takeChildren();
     ui->carInfo->topLevelItem(2)->takeChildren();
     ui->carInfo->topLevelItem(3)->takeChildren();
     for(int i=0;i<ui->carInfo->topLevelItemCount();++i)
         ui->carInfo->topLevelItem(i)->takeChildren();;
     for(int i=0;i<management.getCarAmount();++i)
     {
         tempVehicle=management.getVehicleAtIndex(i);
         carInfoList.clear();
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
     for(int i=0;i<ui->carInfo->topLevelItemCount();++i)
     {
         QTreeWidgetItem *temp = new QTreeWidgetItem(QStringList("Double-Click to Add"));
         ui->carInfo->topLevelItem(i)->insertChild(ui->carInfo->topLevelItem(i)->childCount(),temp);
     }
 }

 void CarParkManagement::init()
 {
     myTime = new QTime();
     QTimer *timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
     timer->start(1000);
     updateVehicleTree();
 }

 time_t CarParkManagement::getCurrentTime()
 {
     time_t curTime;

     return time(&curTime);
 }
