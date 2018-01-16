#include "caredit.h"
#include "ui_caredit.h"

CarEdit::CarEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CarEdit)
{
    ui->setupUi(this);
    this->edited=false;
    setWindowIcon(QIcon(":/icon/icon1/park.jpg"));
    setWindowTitle("编辑车辆");
}

CarEdit::~CarEdit()
{
    delete ui;
}

void CarEdit::setAll(string carNo, string carColor, long long carEnterTime, CarType CarType)
{
    ui->lineEdit->setText(QString::fromStdString(carNo));
    ui->lineEdit_2->setText(QString::fromStdString(carColor));
    ui->comboBox->setCurrentIndex((int)CarType);
    QDateTime enterTime;
    qint64 qintEnterTime = carEnterTime;
    enterTime.setSecsSinceEpoch(qintEnterTime);
    ui->dateTimeEdit->setDateTime(enterTime);
    this->edited=false;
}

bool CarEdit::nameEdited()
{
    return edited;
}

string CarEdit::getCarNo()
{
    return ui->lineEdit->text().toStdString();
}

string CarEdit::getCarColor()
{
    return ui->lineEdit_2->text().toStdString();
}

time_t CarEdit::getArriveTime()
{
    return ui->dateTimeEdit->dateTime().toSecsSinceEpoch();
}

void CarEdit::on_lineEdit_textChanged(const QString &arg1)
{
    this->edited=true;
}

CarType CarEdit::getCarType()
{
    return (CarType)(ui->comboBox->currentIndex());
}
