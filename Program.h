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
#include <QGroupBox>
#include "sqlHandler.h"
#include <QInputDialog>

struct SClass
{
    int teacherID;
    std::vector<int> studentID;
};

class Program : public QWidget
{
    Q_OBJECT

public:
    Program(QWidget* parent = 0);


    sqlHandler sql;
    std::vector<SClass> classes;

    QTabBar* userTab;
    QGridLayout* layout;
    QGridLayout* classLayout;
    QComboBox* classCombo;
    QComboBox* teachersCombo;
    QPushButton* btnAddTeacherToClass;
    QGroupBox* grpTeachers;
    QGroupBox* grpStudents;
    QLabel* label1;
    QLabel* label2;
    QLabel* label3;
    QLabel* label4;
    QLabel* label5;
    QLabel* label1s;
    QLabel* label2s;
    QLabel* label3s;
    QLabel* label4s;
    QLabel* label5s;
    QPushButton* btnAddStudentToClass;
    QComboBox* classSCombo;
    QComboBox* studentsCombo;
    QPushButton* btnAddStudent;
    QPushButton* btnRemoveStudent;
    QPushButton* btnScoring;
    QComboBox* coursesCombo;

    ~Program();

public slots:
    void UpdateTeacherData();
    void bindTeacher();
    void UpdateStudentData();
    void bindStudent();
    void addNewStudent();
    void removeCurrentStudent();
};

#endif // PROGRAM_H
