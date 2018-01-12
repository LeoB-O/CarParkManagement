#include "management.h"


Management::Management()
{
    //TODO parkplace初始化为一定长度（不可变）
    //vehicle长度为可变
    //employee长度可变
    parkplace = vector<ParkPlace>(300);
    totalCarPlace=200;
    totalSmallVanPlace=25;
    totalMidVanPlace=25;
    totalHugeVanPlace=50;
}

int Management::carEnter(string no, string color, CarType carType, time_t arriveTime, time_t leaveTime, int parkPos)
{
    //TODO 写入数据库 判重
    int pos = findCar(no);
    if(pos==NOT_FOUND)
    {
        vehicle.push_back(Vehicle(no, color, carType, arriveTime, leaveTime, parkPos));
        parkplace[parkPos].setOccupied(true);
        if(leaveTime==0)
        {
            switch (carType)
            {
            case car:
                totalCarPlace--;
                break;
            case smallVan:
                totalSmallVanPlace--;
                break;
            case middleVan:
                totalMidVanPlace--;
                break;
            case HugeVan:
                    totalHugeVanPlace--;
                break;
            default:
                break;
            }
        }
        
        updateVehicleDB();
        return vehicle.size()-1;
    }
    else
    {
        updateVehicleDB();
        return ALREADY_EXITST;
    }

}

int Management::carLeave(string no)
{
    //TODO 写入数据库
    int pos = findCar(no);
    switch (vehicle[pos].getCarType())
    {
    case car:
        totalCarPlace++;
        break;
    case smallVan:
        totalSmallVanPlace++;
        break;
    case middleVan:
        totalMidVanPlace++;
        break;
    case HugeVan:
            totalHugeVanPlace++;
        break;
    default:
        break;
    }
    vehicle[pos].getStrLeaveTime();
    updateVehicleDB();
    vehicle.erase(vehicle.begin()+pos);
    return pos;
}

int Management::findFreePos()
{
    for(int i=0;i<parkplace.size();++i)
    {
        if(!parkplace[i].isOccupied())
            return i;
    }
    return NOT_FOUND;
}

int Management::findFreePos(int pos)
{
    for(int i=pos;i<parkplace.size();++i)
    {
        if(!parkplace[i].isOccupied())
            return i;
    }
    return NOT_FOUND;
}

int Management::findCar(string no)
{
    for(int i=0;i<vehicle.size();i++)
    {
        if(vehicle[i].getNo()==no)
            return i;
    }
    return NOT_FOUND;
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
        return NOT_FOUND;
    pos = findCar(toNo);
    if(pos==-1)
    {
        vehicle[pos].setNo(toNo);
        return pos;
    }
    else
    {
        return ALREADY_EXITST;
    }
}

int Management::setCarColor(string no, string color)
{
    int pos = findCar(no);
    if(pos==-1)
        return NOT_FOUND;
    vehicle[pos].setColor(color);
    return pos;
}

int Management::setCarType(string no, CarType carType)
{
    int pos = findCar(no);
    if(pos==-1)
        return NOT_FOUND;
    vehicle[pos].setCarType(carType);
    return pos;
}

int Management::setArriveTime(string no, time_t arriveTime)
{
    int pos = findCar(no);
    if(pos==-1)
        return NOT_FOUND;
    vehicle[pos].setArriveTime(arriveTime);
    return pos;
}

int Management::setLeaveTime(string no, time_t leaveTime)
{
    int pos = findCar(no);
    if(pos==-1)
        return NOT_FOUND;
    vehicle[pos].setLeaveTime(leaveTime);
    return pos;
}

int Management::getCarParkPlace()
{
    return this->totalCarPlace;
}

int Management::getSmallVanParkPlace()
{
    return this->totalSmallVanPlace;
}

int Management::getMidVanParkPlace()
{
    return this->totalMidVanPlace;
}

int Management::getHugeVanParkPlace()
{
    return this->totalHugeVanPlace;
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

bool Management::loadVehicleDB()
{
    MYSQL sqlCon;
    string sqlQuery;
    string carNo, color, carType;
    long int arriveTime, leaveTime, parkPos;
    char buffer[80];
    mysql_init(&sqlCon);
    mysql_real_connect(&sqlCon, "120.24.228.41", "root", "BslLbbMjl5482()$", "carpark", 3306, NULL, 0);
    mysql_options(&sqlCon, MYSQL_SET_CHARSET_NAME, "utf-8");
    sqlQuery="SELECT * FROM `vehicle`;";
    mysql_real_query(&sqlCon, sqlQuery.c_str(), sqlQuery.length());
    MYSQL_RES* result = mysql_store_result(&sqlCon);
    MYSQL_ROW row;
    unsigned int num_fields;
    num_fields = mysql_num_fields(result);
    while(row = mysql_fetch_row(result))
    {
        carNo=row[0];
        color=row[1];
        carType=row[2];
        arriveTime=atoi(row[3]);
        leaveTime=atoi(row[4]);
        parkPos=atoi(row[5]);
        carEnter(carNo, color, (CarType)atoi(carType.c_str()), (time_t)arriveTime, (time_t)leaveTime, parkPos);
    }
    mysql_close(&sqlCon);
    return true;
}

bool Management::updateVehicleDB()
{
    MYSQL sqlCon;
    string sqlQuery;
    char buffer[80];
    mysql_init(&sqlCon);
    mysql_real_connect(&sqlCon, "120.24.228.41", "root", "BslLbbMjl5482()$", "carpark", 3306, NULL, 0);
    sqlQuery="DELETE FROM `vehicle`;";
    mysql_real_query(&sqlCon, sqlQuery.c_str(),sqlQuery.length());
    for(int i=0;i<vehicle.size();i++)
    {
        sqlQuery.clear();
        sqlQuery.append("INSERT INTO `carpark`.`vehicle` (`number`, `color`, `type`, `arriveTime`, `leaveTime`, `parkPos`) VALUES ('");
        sqlQuery.append(vehicle[i].getNo());
        sqlQuery.append("', '");
        sqlQuery.append(vehicle[i].getColor());
        sqlQuery.append("', '");
        sqlQuery.append(itoa(vehicle[i].getCarType(),buffer,10));
        sqlQuery.append("', '");
        sqlQuery.append(itoa((long)vehicle[i].getArriveTime(),buffer,10));
        sqlQuery.append("', '");
        sqlQuery.append(itoa((long)vehicle[i].getLeaveTime(),buffer,10));
        sqlQuery.append("', '");
        sqlQuery.append(itoa(vehicle[i].getParkPos(),buffer,10));
        sqlQuery.append("');");
        mysql_real_query(&sqlCon, sqlQuery.c_str(), sqlQuery.length());
    }
    mysql_close(&sqlCon);
    return true;
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
