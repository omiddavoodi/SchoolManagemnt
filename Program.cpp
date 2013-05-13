#include "Program.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QTabBar>

Program::Program(QWidget *parent)
    : QWidget(parent)
{
    //setting program options
    this->setFixedSize(800, 600);
    this->setWindowTitle("IUST School!");

    this->userTab = new QTabBar();
    this->userTab->setLayoutDirection(Qt::RightToLeft);
    this->userTab->addTab("تعیین کلاس ها");
    this->userTab->addTab("ویرایش ناظم ها");
    this->userTab->addTab("ویرایش معلم ها");
    this->userTab->addTab("ویرایش دانش آموزان");
    this->userTab->addTab("نمایش وضعیت انظباطی");
    this->userTab->addTab("تغییر گذرواژه و نام کاربری");
    this->userTab->addTab("خروج");
    userTab->setParent(this);
    userTab->setGeometry(this->width()-userTab->width()-100,0,userTab->width()+100,23);
    //this->layout = new QGridLayout();
    //this->classLayout = new QGridLayout();
    //layout->addWidget(userTab,0,0);
    //layout->addLayout(classLayout,1,0,1,1);
    classCombo = new QComboBox();
    classCombo->addItem("1/1");
    classCombo->addItem("1/2");
    classCombo->addItem("2/1");
    classCombo->addItem("2/2");
    classCombo->addItem("3/1");
    classCombo->addItem("3/2");
    classCombo->addItem("4/1");
    classCombo->addItem("4/2");
    classCombo->addItem("5/1");
    classCombo->addItem("5/2");
    classCombo->addItem("6/1");
    classCombo->addItem("6/2");
    classCombo->setParent(this);
    //classLayout->addWidget(classCombo);
    //this->setLayout(layout);

}

Program::~Program()
{

}
