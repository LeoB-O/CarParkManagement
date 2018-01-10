#ifndef PARKPLACE_H
#define PARKPLACE_H

#include "vehicle.h"

//停车位类
class ParkPlace
{
public:
    ParkPlace();
    ParkPlace(int no, CarType placeType, bool occupied);
    int getNo();            //获取车位编号
    int getCharge();        //获取车位收费标准
    CarType getPlaceType(); //获取车位类型
    bool isOccupied();      //获取车位是否被占用
    void setNo(int no);     //设置车位编号
    void setPlaceType(CarType placeType);   //设置车位类型
    void setOccupied(bool occupied);        //设置车位是否被占用
private:
    static int TotalNum;
    int no;             //车位编号
    CarType placeType;  //车位类型
    bool occupied;      //车位是否被占用
};

#endif // PARKPLACE_H
