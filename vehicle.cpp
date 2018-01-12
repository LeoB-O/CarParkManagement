#include "vehicle.h"

CarType fromStrToCarType(string carType)
{
    if(carType=="小型客车")
        return car;
    else if(carType=="小型货车")
        return smallVan;
    else if(carType=="中型货车")
        return middleVan;
    else
        return HugeVan;
}

Vehicle::Vehicle()
{
    this->leaveTime=(time_t)0;
}

Vehicle::Vehicle(string no, string color, CarType carType, time_t arriveTime, time_t leaveTime, int parkPos)
{
    this->no = no;
    this->color = color;
    this->carType = carType;
    this->arriveTime = arriveTime;
    this->leaveTime = leaveTime;
    this->parkPos = parkPos;
}

int Vehicle::getParkPos()
{
    return this->parkPos;
}

string Vehicle::getNo()
{
    return this->no;
}

string Vehicle::getColor()
{
    return this->color;
}

CarType Vehicle::getCarType()
{
    return this->carType;
}

string Vehicle::getStrCarType()
{
    switch (carType)
    {
    case car:
        return string("小型客车");
    case smallVan:
        return string("小型货车");
    case middleVan:
        return string("中型货车");
    case HugeVan:
        return string("大型货车");
    default:
        return string("小型客车");
        break;
    }
}

time_t Vehicle::getArriveTime()
{
    return this->arriveTime;
}

string Vehicle::getStrArriveTime()
{
    char buffer[40];
    tm *timeInfo;
    timeInfo = localtime(&(this->arriveTime));
    strftime(buffer, 40, "%Y-%m-%d %H:%M:%S", timeInfo);
    return string(buffer);
}

time_t Vehicle::getLeaveTime()
{
    return this->leaveTime;
}

string Vehicle::getStrLeaveTime()
{
   time(&(this->leaveTime));
   char buffer[40];
   tm *timeInfo;
   timeInfo = localtime(&(this->leaveTime));
   strftime(buffer, 40, "%Y-%m-%d %H:%M:%S", timeInfo);
   return string(buffer);
}

string Vehicle::getStrStayTime()
{
    time_t now;
    time(&now);
    double timeGap=difftime(now, this->arriveTime);
    int hour=timeGap/3600;
    timeGap-=3600*hour;
    int minute=timeGap/60;
    timeGap-=minute*60;
    int second=timeGap;
    char buffer[40];
    string result="";
    itoa(hour,buffer,10);
    result.append(buffer);
    result.append(":");
    itoa(minute, buffer, 10);
    result.append(buffer);
    result.append(":");
    itoa(second, buffer, 10);
    result.append(buffer);
    return result;
}

int Vehicle::getIntStayHour()
{
    time_t now;
    time(&now);
    double timeGap=difftime(now, this->arriveTime);
    int intTimeGap=(int)timeGap;
    int hour=timeGap/3600;
    if(intTimeGap%3600==0)
        return hour;
    else
        return hour+1;
}

int Vehicle::getCharge()
{
    int carCharge=10;
    int smallVanCharge=12;
    int middleVanCharge=15;
    int hugeVanCharge=20;
    switch (carType)
    {
    case car:
        return carCharge;
    case smallVan:
        return smallVanCharge;
    case middleVan:
        return middleVanCharge;
    case HugeVan:
        return hugeVanCharge;
    default:
        return 0;
    }
}

void Vehicle::setParkPos(int parkPos)
{
    this->parkPos=parkPos;
}

void Vehicle::setNo(string no)
{
    this->no=no;
}

void Vehicle::setColor(string color)
{
    this->color=color;
}

void Vehicle::setCarType(CarType carType)
{
    this->carType=carType;
}

void Vehicle::setArriveTime(time_t arriveTime)
{
    this->arriveTime=arriveTime;
}

void Vehicle::setLeaveTime(time_t leaveTime)
{
    this->leaveTime=leaveTime;
}
