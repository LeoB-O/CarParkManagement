#include "carenter.h"
#include "ui_carenter.h"

CarEnter::CarEnter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CarEnter)
{
    ui->setupUi(this);
}

CarEnter::~CarEnter()
{
    delete ui;
}
