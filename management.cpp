#include "management.h"

Management::Management()
{
    //TODO parkplace初始化为一定长度（不可变）
    //vehicle长度为可变
    //employee长度可变
}

int Management::carEnter(string no, string color, CarType carType, time_t arriveTime, time_t leaveTime, int parkPos)
{
    //TODO 写入数据库 判重
}

int Management::carLeave(string no)
{
    //TODO 写入数据库
}

int Management::findFreePos()
{

}

int Management::findFreePos(int pos)
{

}

int Management::findCar(string no)
{

}

int Management::getCarAmount()
{

}

Vehicle Management::getVehicleAtIndex(int index)
{
    return this->vehicle[index];
}

int Management::setCarNo(string no, string toNo)
{
    //TODO 判重
}

int Management::setCarColor(string no, string color)
{

}

int Management::setCarType(string no, CarType carType)
{

}

int Management::setArriveTime(string no, time_t arriveTime)
{

}

int Management::setLeaveTime(string no, time_t leaveTime)
{

}

int Management::setParkPos(string no, int parkPos)
{

}

void Management::setParkPlaceType(CarType parkPlaceType)
{

}

int Management::findStaff(int no)
{

}

int Management::setStaffNo(int no, int toNo)
{

}

int Management::setStaffName(int no, string name)
{

}

int Management::setStaffAge(int no, int age)
{

}

int Management::setStaffSalary(int no, int salary)
{

}

int Management::setStaffVacation(int no, int vacation)
{

}

int Management::setStaffType(int no, StaffType staffType)
{

}

bool Management::updateVehicleDB()
{

}

bool Management::updateVehicleDB(Vehicle vehicle)
{
    //TODO 如果已经存在，那么只需要修改，不存在，那么需要插入
    //下同
}

bool Management::updateVehicleDB(string no, string color, CarType carType, time_t arriveTime, time_t leaveTime, int parkPos)
{

}

bool Management::updateStaffDB()
{

}

bool Management::updateStaffDB(Staff staff)
{

}

bool Management::updateStaffDB(int no, string name, int age, int salary, int vacation, StaffType staffType)
{

}

bool Management::updateParkPlaceDB()
{

}
