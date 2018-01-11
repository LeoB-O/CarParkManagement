#include "vehicle.h"

Vehicle::Vehicle()
{

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
   char buffer[40];
   tm *timeInfo;
   timeInfo = localtime(&(this->leaveTime));
   strftime(buffer, 40, "%Y-%m-%d %H:%M:%S", timeInfo);
   return string(buffer);
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
