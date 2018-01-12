#include "otherfun.h"

void testPerformance()
{
    MYSQL sqlCon;
    string sqlQuery;
    char buffer[80];
    mysql_init(&sqlCon);
    mysql_real_connect(&sqlCon, "localhost", "root", "", "carpark", 3306, NULL, 0);
    sqlQuery="DELETE FROM `vehicle`;";
    mysql_real_query(&sqlCon, sqlQuery.c_str(),sqlQuery.length());
    for(int i=0;i<20000;i++)
    {
        sqlQuery.clear();
        sqlQuery.append("INSERT INTO `carpark`.`vehicle` (`number`, `color`, `type`, `arriveTime`, `leaveTime`, `parkPos`) VALUES ('");
        sqlQuery.append(itoa(i, buffer, 10));
        sqlQuery.append("', '");
        sqlQuery.append("1");
        sqlQuery.append("', '");
        sqlQuery.append("1");
        sqlQuery.append("', '");
        sqlQuery.append("2");
        sqlQuery.append("', '");
        sqlQuery.append("1");
        sqlQuery.append("', '");
        sqlQuery.append("2");
        sqlQuery.append("');");
        mysql_real_query(&sqlCon, sqlQuery.c_str(), sqlQuery.length());
        cout<<sqlQuery<<endl;
    }
    mysql_close(&sqlCon);
}
