#include "carparkmanagement.h"
#include "ui_carparkmanagement.h"

CarParkManagement::CarParkManagement(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CarParkManagement)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/icon/icon1/park.jpg"));
    setWindowTitle("停车场管理系统");
    init();
}

CarParkManagement::~CarParkManagement()
{
    delete ui;
}

bool CarParkManagement::isValid()
{
    return isValidUser;
}

void CarParkManagement::on_carEnter_clicked()
{
    bool inputIsRight=false;
    this->carenter = new CarEnter;
    this->carenter->exec();
    if(this->carenter->result()!=this->carenter->Accepted)
        return;
    if(carenter->getCarNo()!="")
        inputIsRight=true;
    while(!inputIsRight)
    {
        QMessageBox alertBox;
        alertBox.setText("输入有误！请重新输入！");
        alertBox.exec();
        this->carenter = new CarEnter;
        this->carenter->exec();
        if(this->carenter->result()!=this->carenter->Accepted)
            return;
        if(carenter->getCarNo()!="")
            inputIsRight=true;
    }
    int carTp=carenter->getCarType();
    if(carTp==0&&management.getCarParkPlace()<=0||carTp==1&&management.getSmallVanParkPlace()<=0||carTp==2&&management.getMidVanParkPlace()<=0||carTp==3&&management.getHugeVanParkPlace()<=0)
    {
        QMessageBox alertMess;
        alertMess.setText("车位已满！");
        alertMess.exec();
        return;
    }
    int result = management.carEnter(carenter->getCarNo(),carenter->getCarColor(),carenter->getCarType(),getCurrentTime(),0,management.findFreePos());
    if(result==ALREADY_EXITST)
    {
        QMessageBox alreadyExist;
        alreadyExist.setText("车辆已存在！");
        alreadyExist.exec();
    }
    updateVehicleTree();
    updateParkPlaceNum();
    management.updateVehicleDB();
}

void CarParkManagement::on_employeeManage_clicked()
{
    this->employee = new Employee(&management);
    this->employee->exec();
}

void CarParkManagement::on_retriveCar_clicked()
{
    string carNo;
    int pos=-1;
    this->searchcar = new SearchCar;
    this->searchcar->exec();
    if(this->searchcar->result()!=this->searchcar->Accepted)
        return;
    carNo=this->searchcar->getCarNo();
    pos=management.findCar(carNo);
    if(pos==NOT_FOUND)
    {
        QMessageBox notFound;
        notFound.setText("未找到车辆！");
        notFound.exec();
        return;
    }
    for(int i=0;i<ui->carInfo->topLevelItemCount();i++)
    {
        for(int j=0;j<ui->carInfo->topLevelItem(i)->childCount();j++)
        {
            if(ui->carInfo->topLevelItem(i)->child(j)->text(0)==QString::fromStdString(carNo))
            {
                ui->carInfo->setCurrentItem(ui->carInfo->topLevelItem(i)->child(j));
            }
        }
    }
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
     for(int i=0;i<ui->carInfo->topLevelItemCount();++i)
         ui->carInfo->topLevelItem(i)->takeChildren();
     for(int i=0;i<management.getCarAmount();++i)
     {
         tempVehicle=management.getVehicleAtIndex(i);
         if(tempVehicle.getLeaveTime()!=0)
             continue;
         carInfoList.clear();
         carInfoList.append(QString::fromStdString(tempVehicle.getNo()));
         carInfoList.append(QString::fromStdString(tempVehicle.getColor()));
         carInfoList.append(QString::fromStdString(tempVehicle.getStrArriveTime()));
         carInfoList.append(QString::fromStdString(tempVehicle.getStrStayTime()));
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
         QTreeWidgetItem *temp = new QTreeWidgetItem(QStringList("Double-Click to Leave"));
         ui->carInfo->topLevelItem(i)->insertChild(ui->carInfo->topLevelItem(i)->childCount(),temp);
     }
 }

 void CarParkManagement::updateStayTime()
 {
     int pos=0;
     if(management.getCarAmount()<=0)
         return;
     Vehicle tempVehicle=management.getVehicleAtIndex(0);
     for(int i=0;i<ui->carInfo->topLevelItemCount();i++)
     {
         for(int j=0;j<ui->carInfo->topLevelItem(i)->childCount()-1;j++)
         {
            pos=management.findCar(ui->carInfo->topLevelItem(i)->child(j)->text(0).toStdString());
            tempVehicle=management.getVehicleAtIndex(pos);
            ui->carInfo->topLevelItem(i)->child(j)->setText(3, QString::fromStdString(tempVehicle.getStrStayTime()));
         }
     }
 }

 void CarParkManagement::updateParkPlaceNum()
 {
     ui->carRest->setText(QString::number(management.getCarParkPlace()));
     ui->smallVanRest->setText(QString::number(management.getSmallVanParkPlace()));
     ui->middleVanRest->setText(QString::number(management.getMidVanParkPlace()));
     ui->hugeVanRest->setText(QString::number(management.getHugeVanParkPlace()));
 }

 void CarParkManagement::init()
 {
     isValidUser=false;
     this->login = new Login;
     login->exec();
     management.loadStaffDB();
     if(login->result()!=login->Accepted)
         return;
     if(management.findStaff(atoi(login->getUserName().c_str()))==NOT_FOUND)
     {
         QMessageBox alertMess;
         alertMess.setText("用户不存在！");
         alertMess.exec();
         return;
     }
     management.loadVehicleDB();
     management.updateWorkLog(login->getUserName());
     isValidUser=true;
     myTime = new QTime();
     QTimer *timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
     connect(timer, SIGNAL(timeout()), this, SLOT(updateStayTime()));
     timer->start(1000);
     updateVehicleTree();
     updateParkPlaceNum();
 }

 time_t CarParkManagement::getCurrentTime()
 {
     time_t curTime;
     return time(&curTime);
 }

void CarParkManagement::on_carInfo_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    QString QStrCarNo = item->text(0);
    string strCarNo = QStrCarNo.toStdString();
    int pos = management.findCar(strCarNo);
    if(pos==NOT_FOUND)
        return;
    Vehicle tempVehicle = management.getVehicleAtIndex(pos);
    carLeave = new CarLeave;
    carLeave->setAll(tempVehicle.getStrArriveTime(), tempVehicle.getStrLeaveTime(), tempVehicle.getStrStayTime(),tempVehicle.getCharge()*tempVehicle.getIntStayHour());
    carLeave->exec();
    if(carLeave->result()!=carLeave->Accepted)
        return;
    management.carLeave(strCarNo);
    updateVehicleTree();
    updateParkPlaceNum();
    management.updateVehicleDB();
}

void CarParkManagement::on_pushButton_clicked()
{
    QString QStrCarNo = ui->carInfo->currentItem()->text(0);
    string strCarNo = QStrCarNo.toStdString();
    int pos = management.findCar(strCarNo);
    if(pos==-1)
        return;
    Vehicle tempVehicle = management.getVehicleAtIndex(pos);
    caredit = new CarEdit;
    time_t temp = tempVehicle.getArriveTime();
    caredit->setAll(tempVehicle.getNo(),tempVehicle.getColor(),(long long)(tempVehicle.getArriveTime()), tempVehicle.getCarType());
    caredit->exec();
    if(caredit->result()!=caredit->Accepted)
        return;
    if(caredit->nameEdited()&&management.findCar(caredit->getCarNo())!=NOT_FOUND)
    {
        QMessageBox alertMess;
        alertMess.setText("车辆已存在！");
        alertMess.exec();
        return;
    }
    if(caredit->getArriveTime()>QDateTime::currentSecsSinceEpoch())
    {
        QMessageBox alertMess;
        alertMess.setText("时间设置错误！");
        alertMess.exec();
        return;
    }
    management.setCarNo(strCarNo, caredit->getCarNo());
    management.setCarColor(strCarNo, caredit->getCarColor());
    management.setArriveTime(strCarNo, caredit->getArriveTime());
    management.setCarType(strCarNo, caredit->getCarType());
    updateVehicleTree();
    management.updateVehicleDB();
}
