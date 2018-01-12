#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QDialog>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QMessageBox>
#include "management.h"
#include "addstaff.h"
#include "worklog.h"

//员工管理图形界面
namespace Ui {
class Employee;
}

class Employee : public QDialog
{
    Q_OBJECT

public:
    explicit Employee(QWidget *parent = 0);
    explicit Employee(Management *management, QWidget *parent = 0);
    ~Employee();
    void setManagement(Management *management);

private slots:
    void on_addStaff_clicked();
    void updateStaffINFO();

    void on_deleteStaff_clicked();

    void on_worklog_clicked();

private:
    Ui::Employee *ui;
    Management *management;
    AddStaff *addStaff;
    WorkLog *workLog;
};

#endif // EMPLOYEE_H
