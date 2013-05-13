#include "FirstPage.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FirstPage p;
    p.show();

    return a.exec();
}
