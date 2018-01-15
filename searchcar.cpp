#include "searchcar.h"
#include "ui_searchcar.h"

SearchCar::SearchCar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchCar)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/icon/icon1/park.jpg"));
    setWindowTitle("车辆查询");
}

SearchCar::~SearchCar()
{
    delete ui;
}

string SearchCar::getCarNo()
{
    return ui->lineEdit->text().toStdString();
}
