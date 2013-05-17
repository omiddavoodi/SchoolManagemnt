#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include "sqlHandler.h"

class changePassword : public QWidget
{
    Q_OBJECT

    int id;

    //layouts
    QVBoxLayout* mainLayout;
    QHBoxLayout* buttonLayout;
    QGridLayout* layout;

    //labels
    QLabel* userLabel;
    QLabel* passwordLabel;

    //line edits
    QLineEdit* userEdit;
    QLineEdit* passwordEdit;

    //push buttons
    QPushButton* enterButton;
    QPushButton* exitButton;

public slots:
    void submit();

public:
    changePassword(int id,QWidget *parent = 0);
};

#endif // CHANGEPASSWORD_H
