#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <ctime>
using namespace std;

enum CarType{
    car,smallVan,middleVan,HugeVan
};

class Vehicle
{
public:
    Vehicle();
    Vehicle(string no, string color, CarType carType, time_t arriveTime, time_t leaveTime, int parkPos);
    int getParkPos();
    string getNo();         //获取车牌
    string getColor();      //获取车辆颜色
    CarType getCarType();   //获取车辆类型
    time_t getArriveTime(); //获取到达时间
    string getStrArriveTime();
    time_t getLeaveTime();  //获取离开时间
    string getStrLeaveTime();
    void setParkPos(int parkPos);
    void setNo(string no);  //设置车牌
    void setColor(string color);            //设置颜色
    void setCarType(CarType carType);       //设置类型
    void setArriveTime(time_t arriveTime);  //设置到达时间
    void setLeaveTime(time_t leaveTime);    //设置离开时间
private:
    int parkPos;        //停车位置
    string no;          //车牌号
    string color;       //车辆颜色
    CarType carType;    //车辆类型
    time_t arriveTime;  //到达时间
    time_t leaveTime;   //离开时间
};

#endif // VEHICLE_H
