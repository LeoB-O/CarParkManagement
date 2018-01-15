#include "worklog.h"
#include "ui_worklog.h"
//#include "otherdefinition.h"

//const char* HOST_NAME = "localhost";"120.24.228.41
//const char* USER_NAME = "root";
//const char* PASSWORD = "";BslLbbMjl5482()$

WorkLog::WorkLog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkLog)
{
    ui->setupUi(this);
    MYSQL sqlCon;
    mysql_init(&sqlCon);
    mysql_real_connect(&sqlCon, "120.24.228.41", "root", "BslLbbMjl5482()$", "carpark", 3306, NULL, 0);
    string sqlQuery = "SELECT * FROM `worklog`;";
    mysql_real_query(&sqlCon, sqlQuery.c_str(),sqlQuery.length());
    MYSQL_RES* result = mysql_store_result(&sqlCon);
    MYSQL_ROW row;
    unsigned int num_fields;
    num_fields = mysql_num_fields(result);
    QStringList templist;
    while(row = mysql_fetch_row(result))
    {
        templist.clear();
        templist.append(row[1]);
        templist.append(row[0]);
        templist.append(row[2]);
        ui->treeWidget->insertTopLevelItem(0, new QTreeWidgetItem(templist));
    }
    mysql_close(&sqlCon);
}

WorkLog::~WorkLog()
{
    delete ui;
}
