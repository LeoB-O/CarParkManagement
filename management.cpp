#include "management.h"
#include "otherdefinition.h"

//const char* HOST_NAME = "localhost";
//const char* USER_NAME = "root";
//const char* PASSWORD = "";

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
        return vehicle.size()-1;
    }
    else
    {
        //updateVehicleDB();
        return ALREADY_EXITST;
    }

}

int Management::carLeave(string no)
{
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
        if(vehicle[i].getNo()==no&&vehicle[i].getLeaveTime()==0)
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

int Management::setCurrentUser(int no)
{
    MYSQL sqlCon;
    string sqlQuery;
    mysql_init(&sqlCon);
    char buffer[40];
    mysql_real_connect(&sqlCon, HOST_NAME, USER_NAME, PASSWORD, "carpark", 3306, NULL, 0);
    sqlQuery = "INSERT INTO `carpark`.`worklog` (`id`, `date`, `staffname`) VALUES ('";
    //3', '2018.1.1', 'tset');"
    int pos = findStaff(no);
    if(pos==-1)
        return -1;
    sqlQuery.append(itoa(staff[pos].getNo(),buffer,10));
    sqlQuery.append("','");
    sqlQuery.append(QDate::currentDate().toString().toStdString());
    sqlQuery.append("','");
    sqlQuery.append(staff[pos].getName());
    sqlQuery.append("');");
    mysql_real_query(&sqlCon, sqlQuery.c_str(), sqlQuery.length());
    //INSERT INTO `carpark`.`worklog` (`id`, `date`, `staffname`) VALUES ('4', 'test', 'tset');
    mysql_close(&sqlCon);
    return pos;
}

int Management::setCarNo(string no, string toNo)
{
    //TODO 判重
    int pos = findCar(no);
    if(pos==-1)
        return NOT_FOUND;
    int pos2 = findCar(toNo);
    if(pos2==-1)
    {
        deleteVehicleDB(no);
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

int Management::addStaff(string no, string name, int age)
{
    Staff temp;
    temp.setNo(atoi(no.c_str()));
    temp.setName(name);
    temp.setAge(age);
    staff.push_back(temp);
    return staff.size()-1;
}

int Management::getStaffNum()
{
    return this->staff.size();
}

int Management::getStaffNO(int index)
{
    return this->staff[index].getNo();
}

string Management::getStaffName(int index)
{
    return this->staff[index].getName();
}

int Management::getStaffAge(int index)
{
    return this->staff[index].getAge();
}

int Management::deleteStaff(int no)
{
    int pos = findStaff(no);
    if(pos==-1)
        return NOT_FOUND;
    staff.erase(staff.begin()+pos);
    return pos;
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
    mysql_real_connect(&sqlCon, HOST_NAME, USER_NAME, PASSWORD, "carpark", 3306, NULL, 0);
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
    mysql_real_connect(&sqlCon, HOST_NAME, USER_NAME, PASSWORD, "carpark", 3306, NULL, 0);
    for(int i=0;i<vehicle.size();i++)
    {
        sqlQuery="DELETE FROM `vehicle` WHERE `number`= '";
        sqlQuery.append(vehicle[i].getNo());
        sqlQuery.append("';");
        mysql_real_query(&sqlCon, sqlQuery.c_str(), sqlQuery.length());
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

bool Management::deleteVehicleDB(string no)
{
    MYSQL sqlCon;
    string sqlQuery;
    mysql_init(&sqlCon);
    mysql_real_connect(&sqlCon, HOST_NAME, USER_NAME, PASSWORD, "carpark", 3306, NULL, 0);
    sqlQuery="DELETE FROM `vehicle` WHERE `number` = '";
    sqlQuery.append(no);
    sqlQuery.append("';");
    mysql_real_query(&sqlCon, sqlQuery.c_str(), sqlQuery.length());
}

bool Management::loadStaffDB()
{
    MYSQL sqlCon;
    string no, name;
    int age;
    string sqlQuery;
    mysql_init(&sqlCon);
    mysql_real_connect(&sqlCon, HOST_NAME, USER_NAME, PASSWORD, "carpark", 3306, NULL, 0);
    mysql_options(&sqlCon, MYSQL_SET_CHARSET_NAME, "utf-8");
    sqlQuery="SELECT * FROM `staff`;";
    mysql_real_query(&sqlCon, sqlQuery.c_str(), sqlQuery.length());
    MYSQL_RES* result = mysql_store_result(&sqlCon);
    MYSQL_ROW row;
    unsigned int num_fields;
    num_fields = mysql_num_fields(result);
    while(row = mysql_fetch_row(result))
    {
        no = row[0];
        name = row[1];
        age = atoi(row[2]);
        addStaff(no, name, age);
    }
    mysql_close(&sqlCon);
    return true;
}

bool Management::updateStaffDB()
{
    MYSQL sqlCon;
    string sqlQuery;
    char buffer[80];
    mysql_init(&sqlCon);
    mysql_real_connect(&sqlCon, HOST_NAME, USER_NAME, PASSWORD, "carpark", 3306, NULL, 0);
    sqlQuery="DELETE FROM `staff`;";
    mysql_real_query(&sqlCon, sqlQuery.c_str(), sqlQuery.length());
    for(int i=0;i<staff.size();i++)
    {
        sqlQuery.clear();
        sqlQuery.append("INSERT INTO `carpark`.`staff` (`NO`, `name`, `age`) VALUES ('");
        sqlQuery.append(itoa(staff[i].getNo(),buffer,10));
        sqlQuery.append("', '");
        sqlQuery.append(staff[i].getName());
        sqlQuery.append("', '");
        sqlQuery.append(itoa(staff[i].getAge(),buffer,10));
        sqlQuery.append("');");
        mysql_real_query(&sqlCon, sqlQuery.c_str(), sqlQuery.length());
    }
    mysql_close(&sqlCon);
    return true;
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

bool Management::updateWorkLog(string userName)
{
    MYSQL sqlCon;
    string sqlQuery;
    char buffer[80];
    mysql_init(&sqlCon);
    mysql_real_connect(&sqlCon, HOST_NAME, USER_NAME, PASSWORD, "carpark", 3306, NULL, 0);
    //INSERT INTO `carpark`.`worklog` (`id`, `date`, `staffname`) VALUES ('2', '2018.1.1', 'leo');
//    sqlQuery="DELETE FROM `worklog` WHERE `id`='";
//    sqlQuery.append(userName);
//    sqlQuery.append("';");
//    mysql_real_query(&sqlCon, sqlQuery.c_str(), sqlQuery.length());
    int pos=findStaff(atoi(userName.c_str()));
    sqlQuery.clear();
    sqlQuery.append("INSERT INTO `carpark`.`worklog` (`id`, `date`, `staffname`) VALUES ('");
    sqlQuery.append(itoa(staff[pos].getNo(),buffer,10));
    sqlQuery.append("', '");
    sqlQuery.append(QDateTime::currentDateTime().toString().toStdString());
    sqlQuery.append("', '");
    sqlQuery.append(staff[pos].getName());
    sqlQuery.append("');");
    mysql_real_query(&sqlCon, sqlQuery.c_str(), sqlQuery.length());
    mysql_close(&sqlCon);
    return true;
}
