#include <QtWidgets>
#include "Counter.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QLabel lbl("0");
    QPushButton cmd("ADD");
    Counter counter;

    QObject::connect(&cmd, SIGNAL(clicked()), &counter, SLOT(slotInc()));

    QObject::connect(&counter, SIGNAL(counterChanged(int)), &lbl, SLOT(setNum(int)));

    QObject::connect(&counter, SIGNAL(goodbye()), &app, SLOT(quit()));

    lbl.show();
    cmd.show();

    return app.exec();
}
