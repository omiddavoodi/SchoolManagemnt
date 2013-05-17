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

class addTeacher : public QWidget
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
    addTeacher(QWidget *parent = 0);
};

#endif // CHANGEPASSWORD_H