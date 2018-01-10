#ifndef STAFF_H
#define STAFF_H

#include <string>
using namespace std;

enum StaffType{
    administrator, ordinary
};

//员工类
class Staff
{
public:
    Staff();
    int getNo();                //获取编号
    int getAge();               //获取年龄
    int getSalary();            //获取工资
    int getVacationLog();       //获取休假记录
    string getName();           //获取姓名
    StaffType getStaffType();   //获取员工类型
    void setNo(int no);         //设置编号
    void setAge(int age);       //设置年龄
    void setSalary(int salary); //设置薪水
    void setVacationLog(int vacationLog);   //设置休假记录
    void setName(string name);              //设置姓名
    void setStaffType(StaffType staffType); //设置员工类型
private:
    static int TotalNum;
    int no;             //员工编号
    int age;            //员工年龄
    int salary;         //员工工资
    int vacationLog;    //休假记录
    string name;        //员工姓名
    StaffType staffType;//员工类型（管理员OR普通员工）
};

#endif // STAFF_H
