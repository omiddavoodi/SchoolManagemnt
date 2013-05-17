#include "addTeacher.h"


addTeacher::addTeacher(QWidget *parent)
    : QWidget(parent)
{
    //setting program options
    this->setFixedSize(250,125);
    this->setWindowTitle("اضافه کردن معلم");

    //create layouts
    mainLayout = new QVBoxLayout(this);
    layout = new QGridLayout();
    buttonLayout = new QHBoxLayout();

    //intialize objects
    nameLabel = new QLabel("نام و نام خوانوادگی");
    nameEdit = new QLineEdit();
    userLabel = new QLabel("نام کاربری");
    userEdit = new QLineEdit();
    passwordLabel = new QLabel("گذرواژه");
    passwordEdit = new QLineEdit();
    //setting passwrod mode for the edit text
    passwordEdit->setEchoMode(QLineEdit::Password);

    //push buttons
    enterButton = new QPushButton("ثبت");
    enterButton->setDefault(true);
    exitButton = new QPushButton("خروج");

    //place the object
    layout->addWidget(nameLabel,0,1);
    layout->addWidget(nameEdit,0,0);
    layout->addWidget(userLabel,1,1);
    layout->addWidget(userEdit,1,0);
    layout->addWidget(passwordLabel,2,1);
    layout->addWidget(passwordEdit,2,0);
    buttonLayout->addWidget(enterButton);
    buttonLayout->addWidget(exitButton);

    //add layout to the main layout
    mainLayout->addLayout(layout);
    mainLayout->addLayout(buttonLayout);

    //managing buttons
    connect(exitButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(enterButton,SIGNAL(clicked()),this,SLOT(submit()));
}

void addTeacher::submit()
{
    sqlHandler sql;

    if (userEdit->text().size() > 0 && passwordEdit->text().size() > 0 && nameEdit->text().size() > 0)
    {
        qDebug() << sql.getTeacherNumber() + 1;
        sql.addPerson(sql.getTeacherNumber() + 1,nameEdit->text(),userEdit->text(),passwordEdit->text());
        sql.mycommit();
        this->close();
    }
}
