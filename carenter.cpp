#include "carenter.h"
#include "ui_carenter.h"

CarEnter::CarEnter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CarEnter)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/icon/icon1/park.jpg"));
    setWindowTitle("车辆进场");
}

CarEnter::~CarEnter()
{
    delete ui;
}

string CarEnter::getCarNo()
{
    QString QCarNo;
    QCarNo = ui->lineEdit->text();
    return QCarNo.toStdString();
}

string CarEnter::getCarColor()
{
    QString QCarColor;
    QCarColor = ui->lineEdit_2->text();
    return QCarColor.toStdString();
}

CarType CarEnter::getCarType()
{
    int curIndex = ui->comboBox->currentIndex();
    return (CarType)curIndex;
}
