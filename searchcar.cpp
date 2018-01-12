#include "searchcar.h"
#include "ui_searchcar.h"

SearchCar::SearchCar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchCar)
{
    ui->setupUi(this);
}

SearchCar::~SearchCar()
{
    delete ui;
}

string SearchCar::getCarNo()
{
    return ui->lineEdit->text().toStdString();
}
