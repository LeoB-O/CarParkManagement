#ifndef CARENTER_H
#define CARENTER_H

#include <QDialog>

namespace Ui {
class CarEnter;
}

class CarEnter : public QDialog
{
    Q_OBJECT

public:
    explicit CarEnter(QWidget *parent = 0);
    ~CarEnter();

private:
    Ui::CarEnter *ui;
};

#endif // CARENTER_H
