#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include "Program.h"

class FirstPage : public QWidget
{
    Q_OBJECT

    //another window
    Program* programWindow;

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

private slots:
    void Enter();

public:
    FirstPage(QWidget *parent = 0);
    ~FirstPage();
};

#endif // MAINWINDOW_H
