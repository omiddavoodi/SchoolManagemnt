#include <QMainWindow>
#include <QApplication>
#include <QTableView>

#ifndef STUDENTDATA_H
#define STUDENTDATA_H

class StudentData : public QWidget
{
    Q_OBJECT

public:
    StudentData(QWidget* parent = 0);
    QTableView* table;
    ~StudentData();
};

#endif
