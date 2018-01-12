#ifndef ADDSTAFF_H
#define ADDSTAFF_H

#include <QDialog>
#include <string>
using namespace std;

namespace Ui {
class AddStaff;
}

class AddStaff : public QDialog
{
    Q_OBJECT

public:
    explicit AddStaff(QWidget *parent = 0);
    ~AddStaff();
    string getStaffNo();
    string getStaffName();
    int getStaffAge();

private:
    Ui::AddStaff *ui;
};

#endif // ADDSTAFF_H
