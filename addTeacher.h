#ifndef ADDTEACHER_H
#define ADDTEACHER_H

#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include "sqlHandler.h"

class AddTeacher : public QWidget
{
    Q_OBJECT
    //layouts
    QVBoxLayout* mainLayout;
    QHBoxLayout* buttonLayout;
    QGridLayout* layout;

    //labels
    QLabel* userLabel;
    QLabel* passwordLabel;
    QLabel* nameLabel;

    //line edits
    QLineEdit* userEdit;
    QLineEdit* passwordEdit;
    QLineEdit* nameEdit;

    //push buttons
    QPushButton* enterButton;
    QPushButton* exitButton;

public slots:
    void submit();

public:
    AddTeacher(QWidget *parent = 0);

    ~AddTeacher()
    {
        delete mainLayout;
        delete buttonLayout;
        delete layout;
        delete userLabel;
        delete passwordLabel;
        delete nameLabel;
        delete userEdit;
        delete passwordEdit;
        delete nameEdit;
        delete enterButton;
        delete exitButton;
    };
};

#endif // CHANGEPASSWORD_H
