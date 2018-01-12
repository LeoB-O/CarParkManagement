#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <string>
using namespace std;

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    string getUserName();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
