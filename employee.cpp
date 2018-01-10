#include "employee.h"
#include "ui_employee.h"

//员工管理图形界面

Employee::Employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Employee)
{
    ui->setupUi(this);
}

Employee::~Employee()
{
    delete ui;
}
