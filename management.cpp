#include "management.h"

Management::Management()
{
    //TODO parkplace初始化为一定长度（不可变）
    //vehicle长度为可变
    //employee长度可变
    parkplace = vector<ParkPlace>(300);
}

int Management::carEnter(string no, string color, CarType carType, time_t arriveTime, time_t leaveTime, int parkPos)
{
    //TODO 写入数据库 判重
    vehicle.push_back(Vehicle(no, color, carType, arriveTime, 0, parkPos));
}

int Management::carLeave(string no)
{
    //TODO 写入数据库
}

int Management::findFreePos()
{
    for(int i=0;i<parkplace.size();++i)
    {
        if(!parkplace[i].isOccupied())
            return i;
    }
    return -1;
}

int Management::findFreePos(int pos)
{
    for(int i=pos;i<parkplace.size();++i)
    {
        if(!parkplace[i].isOccupied())
            return i;
    }
    return -1;
}

int Management::findCar(string no)
{
    for(int i=0;i<vehicle.size();i++)
    {
        if(vehicle[i].getNo()==no)
            return i;
    }
    return -1;
}

int Management::getCarAmount()
{
    return vehicle.size();
}

Vehicle Management::getVehicleAtIndex(int index)
{
    return this->vehicle[index];
}

int Management::setCarNo(string no, string toNo)
{
    //TODO 判重
    int pos = findCar(no);
    if(pos==-1)
        return pos;
    vehicle[pos].setNo(toNo);
    return pos;
}

int Management::setCarColor(string no, string color)
{
    int pos = findCar(no);
    if(pos==-1)
        return pos;
    vehicle[pos].setColor(color);
    return pos;
}

int Management::setCarType(string no, CarType carType)
{
    int pos = findCar(no);
    if(pos==-1)
        return pos;
    vehicle[pos].setCarType(carType);
    return pos;
}

int Management::setArriveTime(string no, time_t arriveTime)
{
    int pos = findCar(no);
    if(pos==-1)
        return pos;
    vehicle[pos].setArriveTime(arriveTime);
    return pos;
}

int Management::setLeaveTime(string no, time_t leaveTime)
{
    int pos = findCar(no);
    if(pos==-1)
        return pos;
    vehicle[pos].setLeaveTime(leaveTime);
    return pos;
}

int Management::setParkPos(string no, int parkPos)
{
    int pos = findCar(no);
    if(pos==-1)
        return pos;
    vehicle[pos].setParkPos(parkPos);
    return pos;
}

void Management::setParkPlaceType(int no, CarType parkPlaceType)
{
    if(no>=parkplace.size()||no<0)
        return;
    parkplace[no].setPlaceType(parkPlaceType);
}

int Management::findStaff(int no)
{
    for(int i=0;i<staff.size();i++)
    {
        if(staff[i].getNo()==no)
            return i;
    }
    return -1;
}

int Management::setStaffNo(int no, int toNo)
{
    int pos=findStaff(no);
    if(pos==-1)
        return pos;
    staff[pos].setNo(toNo);
    return pos;
}

int Management::setStaffName(int no, string name)
{
    int pos=findStaff(no);
    if(pos==-1)
        return pos;
    staff[pos].setName(name);
    return pos;
}

int Management::setStaffAge(int no, int age)
{
    int pos=findStaff(no);
    if(pos==-1)
        return pos;
    staff[pos].setAge(age);
    return pos;
}

int Management::setStaffSalary(int no, int salary)
{
    int pos=findStaff(no);
    if(pos==-1)
        return pos;
    staff[pos].setSalary(salary);
    return pos;
}

int Management::setStaffVacation(int no, int vacation)
{
    int pos=findStaff(no);
    if(pos==-1)
        return pos;
    staff[pos].setVacationLog(vacation);
    return pos;
}

int Management::setStaffType(int no, StaffType staffType)
{
    int pos=findStaff(no);
    if(pos==-1)
        return pos;
    staff[pos].setStaffType(staffType);
    return pos;
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
