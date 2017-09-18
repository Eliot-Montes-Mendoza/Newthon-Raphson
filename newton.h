#ifndef NEWTON_H
#define NEWTON_H

#include <QMainWindow>

namespace Ui {
class newton;
}

class newton : public QMainWindow
{
    Q_OBJECT

public:
    explicit newton(QWidget *parent = 0);
    ~newton();
    // in this part are declarated all the variables to use in the program
    double x;//variable for the initial value, the user intrude this value
    double xr; // this variable save the point x and agree 1
    double ea;  // this variable save the error what the user provides
    double ei; // error initial, whe dont know were is the root
    int i; //variable for the interactions
    int max; //this variable save the number of interactions what the user intrude
    double f(double z); //this function is the original
    double df(double w); // this function is the derivated of the function original

public slots:
     void ejecutar(); //this slot is for the button start
     void limpiar(); //this slot is for the button restart
     void activar(); //this slot is for activate and desactivated the buttons

private:
    Ui::newton *ui;
};

#endif // NEWTON_H
