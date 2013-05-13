#ifndef PROGRAM_H
#define PROGRAM_H

#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QTabBar>
#include <QComboBox>

class Program : public QWidget
{
    Q_OBJECT

public:
    Program(QWidget* parent = 0);
    QTabBar* userTab;
    QGridLayout* layout;
    QGridLayout* classLayout;
    QComboBox* classCombo;

    ~Program();
};

#endif // PROGRAM_H
