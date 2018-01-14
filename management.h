#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <vector>
#include <QString>
#include <QDateTime>
#include "winsock.h"
#include "mysql.h"
#include "vehicle.h"
#include "parkplace.h"
#include "staff.h"

using namespace std;

const int NOT_FOUND=-1;
const int ALREADY_EXITST=-2;

class Management
{
public:
    Management();
    int carEnter(string no, string color, CarType carType, time_t arriveTime, time_t leaveTime, int parkPos); //返回值为在vehicle中的索引
    int carLeave(string no);    //车辆离开 返回值为在vehicle中的索引
    int findFreePos();          //从头开始查找空闲车位
    int findFreePos(int pos);   //从pos开始查找空闲车位
    int findCar(string no);     //返回值为停车地点
    int getCarAmount();         //返回车辆数量
    Vehicle getVehicleAtIndex(int index);
    int setCurrentUser(int no);
    int setCarNo(string no, string toNo);       //修改车牌信息
    int setCarColor(string no, string color);   //修改车辆颜色
    int setCarType(string no, CarType carType); //修改车辆类型
    int setArriveTime(string no, time_t arriveTime);//修改到达时间
    int setLeaveTime(string no, time_t leaveTime);  //设置离开时间
    int getCarParkPlace();
    int getSmallVanParkPlace();
    int getMidVanParkPlace();
    int getHugeVanParkPlace();
    int setParkPos(string no, int parkPos);         //设置停车位置
    void setParkPlaceType(int no, CarType parkPlaceType);   //设置停车位类型
    int addStaff(string no, string name, int age);
    int getStaffNum();
    int getStaffNO(int index);
    string getStaffName(int index);
    int getStaffAge(int index);
    int deleteStaff(int no);
    int findStaff(int no);                          //查找员工
    int setStaffNo(int no, int toNo);               //设置员工工号
    int setStaffName(int no, string name);          //设置员工姓名
    int setStaffAge(int no, int age);               //设置员工年龄
    int setStaffSalary(int no, int salary);         //设置员工薪水
    int setStaffVacation(int no, int vacation);     //设置员工休假情况
    int setStaffType(int no, StaffType staffType);  //设置员工类型
    bool loadVehicleDB();
    bool updateVehicleDB();                         //更新车辆数据库，将当前内存中的车辆覆盖数据库
    bool updateVehicleDB(Vehicle vehicle);          //更新数据库，向数据库添加vehicle信息
    bool updateVehicleDB(string no, string color, CarType carType, time_t arriveTime, time_t leaveTime, int parkPos);//使用参数中的信息更新数据库
    bool deleteVehicleDB(string no);
    bool loadStaffDB();
    bool updateStaffDB();                           //使用内存中的员工信息覆盖整个数据库
    bool updateStaffDB(Staff staff);                //使用staff更新员工数据库
    bool updateStaffDB(int no, string name, int age, int salary, int vacation, StaffType staffType);    //使用参数中的信息更新员工数据库
    bool updateParkPlaceDB();                       //使用内存中的停车位信息覆盖数据库
    bool updateWorkLog(string userName);
private:
    vector<Vehicle> vehicle;
    vector<Staff> staff;
    vector<ParkPlace> parkplace;
    int carPlaceLeft;
    int smallVanPlaceLeft;
    int midVanPlaceLeft;
    int hugeVanPlaceLeft;
    int totalCarPlace;
    int totalSmallVanPlace;
    int totalMidVanPlace;
    int totalHugeVanPlace;
};

#endif // MANAGEMENT_H
