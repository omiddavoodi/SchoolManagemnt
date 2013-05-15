#ifndef SQLHANDLER_H
#define SQLHANDLER_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <vector>
#include <QStringList>
class sqlHandler
{
private:
    QSqlDatabase db;
public:
    int maxStudents;
    void initialize()
    {
        maxStudents = 0;
        bool isFirst = false;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("db.db");
        db.open();

        QSqlQuery query;

        if ( db.tables().size() == 0 )
        {
            isFirst = true;
        }

        query.exec("create table if not exists password(id int primary key, "
                "username TEXT, password TEXT, state INT)");
        query.exec("create table if not exists person(id int primary key, "
                "name TEXT, state INT, classID INT)");
        query.exec("create table if not exists student(id int primary key, "
                "name TEXT, mathScore FLOAT, physicsScore FLOAT,"
                " literatureScore FLOAT, theologyScore FLOAT, geographyScore FLOAT,"
                " chemestryScore FLOAT, disciplinaryScore FLOAT, classID INT)");
        query.exec("create table if not exists delay(studentId int, "
                "time FLOAT)");

        if (isFirst)
        {
            qDebug() << "First Iinitialize!";
            query.exec("insert into password values(0, 'admin', 'admin', 1)");
            query.exec("INSERT INTO person values(1, 'قولتوق', 2, -1)");
            query.exec("INSERT INTO person values(2, 'زالو', 2, -1)");
            query.exec("INSERT INTO person values(3, 'پشمک', 2, -1)");
            query.exec("INSERT INTO student values(0, 'هولن', 0, 0, 0, 0, 0, 0, 0, -1)");
            query.exec("INSERT INTO student values(1, 'بیل', 0, 0, 0, 0, 0, 0, 0, -1)");
            query.exec("INSERT INTO student values(2, 'قلیدون', 0, 0, 0, 0, 0, 0, 0, -1)");
            query.exec("INSERT INTO student values(3, 'اسلش', 0, 0, 0, 0, 0, 0, 0, -1)");
            query.exec("INSERT INTO student values(4, 'خرس خسته', 0, 0, 0, 0, 0, 0, 0, -1)");
            query.exec("INSERT INTO student values(5, 'سی شارپ', 0, 0, 0, 0, 0, 0, 0, -1)");
            query.exec("INSERT INTO student values(6, 'موزمار', 0, 0, 0, 0, 0, 0, 0, -1)");
            query.exec("INSERT INTO student values(7, 'زالو', 0, 0, 0, 0, 0, 0, 0, -1)");
            query.exec("INSERT INTO student values(8, 'پدر سگ', 0, 0, 0, 0, 0, 0, 0, -1)");
            query.exec("INSERT INTO student values(9, 'بی آر زد', 0, 0, 0, 0, 0, 0, 0, -1)");
            query.exec("INSERT INTO student values(10, 'سینا', 0, 0, 0, 0, 0, 0, 0, -1)");
            query.exec("INSERT INTO student values(11, 'وحید', 0, 0, 0, 0, 0, 0, 0, -1)");
            query.exec("INSERT INTO student values(12, 'رحمانی', 0, 0, 0, 0, 0, 0, 0, -1)");
            query.exec("INSERT INTO student values(13, 'بیژن', 0, 0, 0, 0, 0, 0, 0, -1)");
            query.exec("INSERT INTO student values(14, 'الاغ', 0, 0, 0, 0, 0, 0, 0, -1)");
            query.exec("INSERT INTO student values(15, 'مشنگ', 0, 0, 0, 0, 0, 0, 0, -1)");
            query.exec("INSERT INTO student values(16, 'یکی حالا دیگه', 0, 0, 0, 0, 0, 0, 0, -1)");
            db.commit();
        }

        /* copy in top of code and delete all tables. after that delete this code and tables define again.
        query.exec("drop table if exists password");
        query.exec("drop table if exists student");
        query.exec("drop table if exists person");
        query.exec("drop table if exists delay");
        */

        /* For testing sql values
        QSqlQuery query2("SELECT username FROM password");
        query2.first();

        while (query2.next())
        {
          QString country = query2.value(0).toString();
          qDebug() << country;
        }
        */
    }

    bool isPerson(QString username,QString password)
    {
        QSqlQuery query;

        query.exec("SELECT * FROM password WHERE username='" + username +"' AND password='"
                   + password + "'");
        query.first();

        qDebug() << query.isValid();
        return query.isValid();
    }


    void addPerson(int id,QString name,QString lastName,QString username,QString password)
    {
        QSqlQuery query;

        query.prepare("insert into password values(?, ?, ?, 2");
        query.addBindValue(id);
        query.addBindValue(username);
        query.addBindValue(password);
        query.exec();

        query.prepare("insert into person values(?, ?, ?, 2");
        query.addBindValue(id);
        query.addBindValue(name);
        query.addBindValue(lastName);
        query.exec();
    }

    void addStudent(int sId,QString name)
    {
        QSqlQuery query;
        query.prepare("insert into student values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
        query.addBindValue(sId);
        query.addBindValue(name);
        query.addBindValue(0);
        query.addBindValue(0);
        query.addBindValue(0);
        query.addBindValue(0);
        query.addBindValue(0);
        query.addBindValue(0);
        query.addBindValue(0);
        query.addBindValue(-1);
        query.exec();
    }

    void addDelay(int sId,float delayTime)
    {
        QSqlQuery query;

        query.prepare("insert into delay values(?, ?)");
        query.addBindValue(sId);
        query.addBindValue(delayTime);

        query.exec();
    }

    std::vector<float> getAllDelays(int sId)
    {
        std::vector<float> delays;

        QSqlQuery query;
        query.prepare("SELECT time FROM delay WHERE sId=?");
        query.addBindValue(sId);
        query.exec();

        query.first();
        delays.push_back(query.value(0).toFloat());
        while (query.next())
        {
            delays.push_back(query.value(0).toFloat());
        }

        return delays;
    }

    std::vector<QString> getTeacherNames()
    {
        std::vector<QString> names;

        QSqlQuery query;
        query.exec("SELECT name FROM person WHERE state=2");
        query.first();
        names.push_back(query.value(0).toString());
        while (query.next())
        {
            names.push_back(query.value(0).toString());
        }

        return names;
    }

    int getTeacherClass(QString name)
    {
        QSqlQuery query;
        query.prepare("SELECT classID FROM person WHERE state=2 and name=?");
        query.addBindValue(name);
        query.exec();
        query.first();
        return query.value(0).toInt();
    }

    bool setTecherClass(int tID, int cID)
    {
        QSqlQuery query;
        query.prepare("UPDATE person SET classID=? WHERE id=?");
        query.addBindValue(cID);
        query.addBindValue(tID);
        return query.exec();
    }

    std::vector<int> getStudentIDs()
    {
        std::vector<int> ids;

        QSqlQuery query;
        query.exec("SELECT id FROM student");
        query.first();
        int temp = query.value(0).toInt();
        ids.push_back(temp);
        if (maxStudents < temp)
            maxStudents = temp;
        while (query.next())
        {
            temp = query.value(0).toInt();
            ids.push_back(temp);
            if (maxStudents < temp)
                maxStudents = temp;
        }

        return ids;
    }

    std::vector<QString> getStudentNames()
    {
        std::vector<QString> names;

        QSqlQuery query;
        query.exec("SELECT name FROM student");
        query.first();
        names.push_back(query.value(0).toString());
        while (query.next())
        {
            names.push_back(query.value(0).toString());
        }

        return names;
    }

    int getStudentClass(QString name)
    {
        QSqlQuery query;
        query.prepare("SELECT classID FROM student WHERE name=?");
        query.addBindValue(name);
        query.exec();
        query.first();
        return query.value(0).toInt();
    }

    bool setStudentClass(int sID, int cID)
    {
        QSqlQuery query;
        query.prepare("UPDATE student SET classID=? WHERE id=?");
        query.addBindValue(cID);
        query.addBindValue(sID);
        return query.exec();
    }

    void removeStudent(int id)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM student WHERE id=?");
        query.addBindValue(id);
        query.exec();
    }

};

#endif
