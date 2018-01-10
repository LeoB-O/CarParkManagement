#include "parkplace.h"

int ParkPlace::TotalNum=0;

ParkPlace::ParkPlace()
{
    ++TotalNum;
    no=TotalNum;
    placeType=car;
    occupied=false;
}

ParkPlace::ParkPlace(int no, CarType placeType, bool occupied)
{
    ++TotalNum;
    this->no=TotalNum;
    this->placeType=placeType;
    this->occupied=occupied;
}

int ParkPlace::getNo()
{
    return this->no;
}

int ParkPlace::getCharge()
{
    int carCharge=10;
    int smallVanCharge=12;
    int middleVanCharge=15;
    int hugeVanCharge=20;
    switch (placeType)
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

CarType ParkPlace::getPlaceType()
{
    return this->placeType;
}

bool ParkPlace::isOccupied()
{
    return this->occupied;
}

void ParkPlace::setNo(int no)
{
    this->no=no;
}

void ParkPlace::setPlaceType(CarType placeType)
{
    this->placeType=placeType;
}

void ParkPlace::setOccupied(bool occupied)
{
    this->occupied=occupied;
}
