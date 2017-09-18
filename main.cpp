#include "newton.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    newton w;
    w.show();

    return a.exec();
}
