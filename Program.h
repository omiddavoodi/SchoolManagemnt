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
#include "addTeacher.h"
#include "changepassword.h"
#include <QInputDialog>
#include <QListWidget>

class Program : public QWidget
{
    Q_OBJECT

public:
    Program(bool isadmin, int userid,int ID, QWidget* parent = 0);


    sqlHandler sql;
    bool is_admin;
    int user_id;
    int ID;

    changePassword* changePass;

    QGridLayout* layout;
    QGridLayout* classLayout;
    QComboBox* classCombo;
    QComboBox* teachersCombo;
    QPushButton* btnAddTeacherToClass;
    QGroupBox* grpTeachers;
    QGroupBox* grpStudents;
    QGroupBox* grpDelays;
    QGroupBox* grpAdminPanel;
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
    QLabel* label6s;
    QLabel* label7s;
    QLabel* label8s;
    QLabel* label9s;
    QLabel* label10s;
    QLabel* label11s;
    QLabel* label12s;
    QLabel* label13s;
    QLabel* label14s;
    QLabel* label15s;
    QLabel* label16s;
    QLabel* label17s;
    QLabel* label18s;
    QLabel* label19s;
    QLabel* label20s;
    QLabel* label21s;
    QPushButton* btnAddStudentToClass;
    QPushButton* btnFileDelayForStudent;
    QComboBox* classSCombo;
    QComboBox* studentsCombo;
    QPushButton* btnAddStudent;
    QPushButton* btnRemoveStudent;
    QPushButton* btnScoring;
    QComboBox* coursesCombo;
    QListWidget* delaysList;
    QPushButton* btnTeacherChangePassword;
    QPushButton* btnAdminChangePassword;
    QPushButton* btnAddTeacher;
    AddTeacher* addTeach;


    void update_student_scores();
    void update_delays();
    ~Program();

public slots:
    void UpdateTeacherData();
    void bindTeacher();
    void UpdateStudentData();
    void bindStudent();
    void addNewStudent();
    void removeCurrentStudent();
    void setStudentScore();
    void changeTeacherPassword();
    void addDelay();
    void addTeacher();
    void adminChangePassword();
};

#endif // PROGRAM_H
