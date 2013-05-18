#include "FirstPage.h"
#include "sqlHandler.h"
#include <QApplication>
#include <QDebug>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FirstPage p;
    sqlHandler sql;
    sql.initialize();

    p.show();
    return a.exec();
}
