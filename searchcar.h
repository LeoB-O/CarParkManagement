#ifndef SEARCHCAR_H
#define SEARCHCAR_H

#include <QDialog>

namespace Ui {
class SearchCar;
}

class SearchCar : public QDialog
{
    Q_OBJECT

public:
    explicit SearchCar(QWidget *parent = 0);
    ~SearchCar();

private:
    Ui::SearchCar *ui;
};

#endif // SEARCHCAR_H
