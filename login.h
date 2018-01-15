#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <string>
#include <windows.h>
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

private slots:
    void on_lineEdit_2_textEdited(const QString &arg1);

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
