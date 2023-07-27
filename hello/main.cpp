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

    //    qDebug() << app.metaObject()->className();
    //    qDebug() << lbl.metaObject()->className();
    //    qDebug() << cmd.metaObject()->className();
    //    qDebug() << counter.metaObject()->className();

    lbl.show();
    cmd.move(lbl.x(), lbl.y() + 50);
    cmd.show();

    return app.exec();
}
