#include "staff.h"

//员工类

int Staff::TotalNum=0;

Staff::Staff()
{
    ++TotalNum;
    this->no=TotalNum;
    this->staffType=ordinary;
}

int Staff::getNo()
{
    return this->no;
}

int Staff::getAge()
{
    return this->age;
}

int Staff::getSalary()
{
    return this->salary;
}

int Staff::getVacationLog()
{
    return this->vacationLog;
}

string Staff::getName()
{
    return this->name;
}

StaffType Staff::getStaffType()
{
    return this->staffType;
}

void Staff::setNo(int no)
{
    this->no=no;
}

void Staff::setAge(int age)
{
    this->age=age;
}

void Staff::setSalary(int salary)
{
    this->salary=salary;
}

void Staff::setVacationLog(int vacationLog)
{
    this->vacationLog=vacationLog;
}

void Staff::setName(string name)
{
    this->name=name;
}

void Staff::setStaffType(StaffType staffType)
{
    this->staffType=staffType;
}
