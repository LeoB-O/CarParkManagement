#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QDialog>

//员工管理图形界面
namespace Ui {
class Employee;
}

class Employee : public QDialog
{
    Q_OBJECT

public:
    explicit Employee(QWidget *parent = 0);
    ~Employee();

private:
    Ui::Employee *ui;
};

#endif // EMPLOYEE_H
