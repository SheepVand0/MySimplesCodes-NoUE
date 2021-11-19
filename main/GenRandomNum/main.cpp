#include "mainwindow.h"
#include "randomfromlist.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RandomFromList w;
    w.show();

    return a.exec();
}
