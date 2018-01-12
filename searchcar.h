#ifndef SEARCHCAR_H
#define SEARCHCAR_H

#include <QDialog>
#include <string>
using namespace std;

namespace Ui {
class SearchCar;
}

class SearchCar : public QDialog
{
    Q_OBJECT

public:
    explicit SearchCar(QWidget *parent = 0);
    ~SearchCar();
    string getCarNo();

private:
    Ui::SearchCar *ui;
};

#endif // SEARCHCAR_H
