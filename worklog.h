#ifndef WORKLOG_H
#define WORKLOG_H

#include <QWidget>
#include "winsock.h"
#include "mysql.h"
#include <string>
using namespace std;

namespace Ui {
class WorkLog;
}

class WorkLog : public QWidget
{
    Q_OBJECT

public:
    explicit WorkLog(QWidget *parent = 0);
    ~WorkLog();

private:
    Ui::WorkLog *ui;
};

#endif // WORKLOG_H
