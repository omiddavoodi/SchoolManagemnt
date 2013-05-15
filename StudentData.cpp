#include "StudentData.h"

StudentData::StudentData(QWidget *parent)
    : QWidget(parent)
{
    //setting program options
    this->setFixedSize(400, 300);
    this->setWindowTitle("وضعیت دانش آموزان");

    table = new QTableView(this);
    table->setGeometry(this->geometry());

}

StudentData::~StudentData()
{

}
