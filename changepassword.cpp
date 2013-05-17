#include "changepassword.h"


changePassword::changePassword(int id,QWidget *parent)
    : QWidget(parent)
{
    this->id = id;
    //setting program options

    this->setFixedSize(200,100);
    this->setWindowTitle("تغییر گذرواژه");

    //create layouts
    mainLayout = new QVBoxLayout(this);
    layout = new QGridLayout();
    buttonLayout = new QHBoxLayout();

    //intialize objects
    userLabel = new QLabel("گذرواژه جدید");
    userEdit = new QLineEdit();
    passwordLabel = new QLabel("تکرار");
    passwordEdit = new QLineEdit();
    //setting passwrod mode for the edit text
    userEdit->setEchoMode(QLineEdit::Password);
    passwordEdit->setEchoMode(QLineEdit::Password);

    //push buttons
    enterButton = new QPushButton("ثبت");
    enterButton->setDefault(true);
    exitButton = new QPushButton("خروج");

    //place the object
    layout->addWidget(userLabel,0,1);
    layout->addWidget(userEdit,0,0);
    layout->addWidget(passwordLabel,1,1);
    layout->addWidget(passwordEdit,1,0);
    buttonLayout->addWidget(enterButton);
    buttonLayout->addWidget(exitButton);

    //add layout to the main layout
    mainLayout->addLayout(layout);
    mainLayout->addLayout(buttonLayout);

    //managing buttons
    connect(exitButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(enterButton,SIGNAL(clicked()),this,SLOT(submit()));
}

void changePassword::submit()
{
    sqlHandler sql;
    qDebug() << "HAHsa";

    if (userEdit->text() == passwordEdit->text())
    {
        sql.changePassword(id,userEdit->text());
        this->close();
    }
}
