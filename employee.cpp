#include "employee.h"
#include "ui_employee.h"

//员工管理图形界面

Employee::Employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Employee)
{
    ui->setupUi(this);

}

Employee::Employee(Management *management, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Employee)
{
    ui->setupUi(this);
    this->management=management;
    updateStaffINFO();
}

Employee::~Employee()
{
    delete ui;
}

void Employee::setManagement(Management *management)
{
    this->management=management;
}
void Employee::on_addStaff_clicked()
{
    this->addStaff=new AddStaff;
    addStaff->exec();
    if(addStaff->result()!=addStaff->Accepted)
        return;
    if(addStaff->getStaffNo()==""||addStaff->getStaffName()=="")
    {
        QMessageBox alertMess;
        alertMess.setText("输入有误！");
        return;
    }
    management->addStaff(addStaff->getStaffNo(), addStaff->getStaffName(), addStaff->getStaffAge());
    updateStaffINFO();
    management->updateStaffDB();
}

void Employee::updateStaffINFO()
{
    QStringList templist;
    ui->treeWidget->clear();
    for(int i=0;i<management->getStaffNum();i++)
    {
        templist.clear();
        templist.append(QString::number(management->getStaffNO(i)));
        templist.append(QString::fromStdString(management->getStaffName(i)));
        templist.append(QString::number(management->getStaffAge(i)));
        ui->treeWidget->insertTopLevelItem(0, new QTreeWidgetItem(templist));
    }
}

void Employee::on_deleteStaff_clicked()
{
    QMessageBox alertMess;
    alertMess.setText("确定删除吗？");
    alertMess.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    int result = alertMess.exec();
    if(result!=QMessageBox::Ok)
        return;
    management->deleteStaff(ui->treeWidget->currentItem()->text(0).toInt());
    updateStaffINFO();
    management->updateStaffDB();
}

void Employee::on_worklog_clicked()
{
    workLog = new WorkLog;
    workLog->show();
    this->accept();
}
