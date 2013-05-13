#ifndef DESC_H
#define DESC_H

#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>

class Desc : public QWidget
{
    Q_OBJECT

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
    Desc(QWidget *parent = 0);
    ~Desc();
};

#endif // DESC_H
