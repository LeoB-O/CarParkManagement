#include "addstaff.h"
#include "ui_addstaff.h"

AddStaff::AddStaff(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStaff)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/icon/icon1/park.jpg"));
    setWindowTitle("添加员工");
}

AddStaff::~AddStaff()
{
    delete ui;
}

string AddStaff::getStaffNo()
{
    return this->ui->lineEdit->text().toStdString();
}

string AddStaff::getStaffName()
{
    return this->ui->lineEdit_2->text().toStdString();
}

int AddStaff::getStaffAge()
{
    return this->ui->lineEdit_3->text().toInt();
}
