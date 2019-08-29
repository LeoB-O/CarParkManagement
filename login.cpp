#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/icon/icon1/park.jpg"));
    setWindowTitle("登陆");
}

Login::~Login()
{
    delete ui;
}

string Login::getUserName()
{
    return ui->lineEdit->text().toStdString();
}

void Login::on_lineEdit_2_textEdited(const QString &arg1)
{
    LoadKeyboardLayout((wchar_t*)"0x0409", KLF_ACTIVATE);
}
