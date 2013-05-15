#ifndef ADMIN_H
#define ADMIN_H

#include <QString>
#include "sqlHandler.h"

class Admin
{
private:
    QString name;
    QString lastName;
    QString userName;
    sqlHandler sql;

public:
    void setTeacher(int teacherId,int classId);
    void addStudent(QString name  ,int studentId ,int classId);

    void removeStudent(int studentId ,int classId);

    void addDelay(int id ,float dealyTime);

    void setName(QString name){this->name = name;}
    void setLastName(QString lastName){this->lastName = lastName;}

    void setPassword(QString pass);

    Admin();
};

#endif // ADMIN_H
