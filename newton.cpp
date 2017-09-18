#include "newton.h"
#include "ui_newton.h"
#include <QDebug> //

newton::newton(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newton)
{
    ui->setupUi(this);
    //connection of all slots
    connect(ui->iniciar,SIGNAL(clicked()),this,SLOT(ejecutar())); //connection between the button iniciar and the slot ejecutar
    connect(ui->reiniciar,SIGNAL(clicked()),this,SLOT(limpiar())); //connection betweeon the button reiniciar and the slot limpiar
    connect(ui->inicial,SIGNAL(valueChanged(double)),this,SLOT(activar())); // the slot inicial and the slot error inactivate the buttons, if the user no are give the values
    connect(ui->error,SIGNAL(valueChanged(double)),this,SLOT(activar())); //
    ui->iniciar->setDisabled(true); //this is a condition for inactivate the button start when the program start
    ui->reiniciar->setDisabled(true); //this is a condition for inactivate the button restart when the program start
    ei=100;//initial error restart to 100

}
double newton::f(double z){//this function return the value of the original function
    return (sin(5*z));
}
double newton::df(double w){ //this function return the derivated original function
    return (5*cos(5*w));
}

void newton::activar(){ //
    ui->iniciar->setDisabled(false); //this is a function for inactivate the button when the program start
    ui->reiniciar->setDisabled(false); //this is a function for inactivate the button when the program start
}

void newton::ejecutar(){ //in ths section is where all the calculations are realized, and the method run
    ui->reiniciar->setDisabled(true); //when the method is running, the button restart is inactivated
    x=ui->inicial->value(); //set an initial value for the spinbox of the initial value
    ea=ui->error->value(); //set an initial value for the spinbox of the error acceptable
    max=ui->interacion->value(); //save the numbre of interactions what the user are provited
    while ((ei>ea)&(max>i)){ // when the error initial are more bigger
        xr=(x)-(f(x)/df(x)); //calculations of the new point
        ei=100*std::abs(xr-x)/xr; // calculation of the new error
        qDebug()<<ei; //this function is for calculate the error
        x=xr; //here ¨x¨ take the value of ¨xr¨
        i++; //this is a sum for the interactions
    }
    ui->raiz->display(x); //show the root in the display
    ui->errorcalculado->display(ei); //show the calculated error in display
    ui->interacciones->display(i);// show the numbre of interactions in a display
    ui->reiniciar->setDisabled(false); //the button restart is enabled again


}

void newton::limpiar(){ //this part clean all the program for a new interaction
    ui->inicial->setValue(0.0); //initial value is set to 0
    ui->error->setValue(0.0); // error is set to 0
    ui->interacion->setValue(0); // interactions are set to 0
    ui->raiz->display(0.0); // the root are set to 0
    ui->errorcalculado->display(0.0); // calculated error is set to 0
    ui->interacciones->display(0); //interactions are set to 0
    x=0; xr=0; ea=0; i=0; ei=100; //all the variables are clean again and the error initial is set to 100 again
    ui->iniciar->setDisabled(true); //the button start is inactivated again
    ui->reiniciar->setDisabled(true); // the button restart is inactivated again
}

newton::~newton()
{
    delete ui;

}
