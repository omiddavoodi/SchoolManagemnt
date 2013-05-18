#include "FirstPage.h"
#include "sqlHandler.h"
#include <QDebug>
#include <QHBoxLayout>

FirstPage::FirstPage(QWidget *parent)
    : QWidget(parent)
{
    //setting program options
    this->setFixedSize(200,100);
    this->setWindowTitle("authentication");

    //create layouts
    mainLayout = new QVBoxLayout(this);
    layout = new QGridLayout();
    buttonLayout = new QHBoxLayout();

    //intialize objects
    userLabel = new QLabel("نام کاربری ");
    userEdit = new QLineEdit();
    passwordLabel = new QLabel("گذرواژه");
    passwordEdit = new QLineEdit();
    //setting passwrod mode for the edit text
    passwordEdit->setEchoMode(QLineEdit::Password);

    //push buttons
    enterButton = new QPushButton("ورود");
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
    connect(enterButton,SIGNAL(clicked()),this,SLOT(Enter()));
}

void FirstPage::Enter()
{
    sqlHandler sql;

    int result = sql.isPerson(userEdit->text(), passwordEdit->text());
    if (result > 0)
    {
        qDebug() << result;
        //creat antoher window
        programWindow = new Program(sql.isAdmin(result),sql.getTeacherClass(result),result);
        //show another window
        programWindow->show();
        //close FirstPage window
        this->close();
    }
}

FirstPage::~FirstPage()
{

}
