#include "carleave.h"
#include "ui_carleave.h"

CarLeave::CarLeave(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CarLeave)
{
    ui->setupUi(this);
}

CarLeave::~CarLeave()
{
    delete ui;
}

void CarLeave::setAll(string strEnterTime, string strLeaveTime, string strStayTime, int intFee)
{
    char buffer[40];
    ui->enterTime->setText(QString::fromStdString(strEnterTime));
    ui->leaveTime->setText(QString::fromStdString(strLeaveTime));
    ui->stayTime->setText(QString::fromStdString(strStayTime));
    itoa(intFee, buffer, 10);
    string temp(buffer);
    ui->fee->setText(QString::fromStdString(temp));
}
