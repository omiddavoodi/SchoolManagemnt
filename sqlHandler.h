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
    void mycommit()
    {
        db.commit();
    }

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
        query.exec("create table if not exists delay(sId INT, time FLOAT)");

        if (isFirst)
        {
            qDebug() << "First Iinitialize!";
            query.exec("insert into password values(1, 'admin', 'admin', 1)");
            query.exec("insert into password values(2, 'gholtogh', 'pedar dar biar', 0)");
            query.exec("insert into password values(3, 'zaalooo', 'reza xerse xaste', 0)");
            query.exec("insert into password values(4, 'pashmak', 'golabi', 0)");
            query.exec("INSERT INTO delay values(0, 4.1)");
            query.exec("INSERT INTO person values(2, 'قولتوق', 2, -3)");
            query.exec("INSERT INTO person values(3, 'زالو', 2, -3)");
            query.exec("INSERT INTO person values(4, 'پشمک', 2, -3)");
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

    int isPerson(QString username,QString password)
    {
        QSqlQuery query;

        query.prepare("SELECT id FROM password WHERE username=? AND password=?");
        query.addBindValue(username);
        query.addBindValue(password);
        query.exec();
        query.first();


        if(query.isValid())
            return query.value(0).toInt();
        else
            return 0;
    }

    int isAdmin(int id)
    {
        QSqlQuery query;

        query.prepare("SELECT state FROM password WHERE id=?");
        query.addBindValue(id);
        query.exec();
        query.first();
        return query.value(0).toBool();
    }

    void addPerson(int id,QString name,QString username,QString password)
    {
        QSqlQuery query;

        query.prepare("insert into password values(?, ?, ?, 0)");
        query.addBindValue(id);
        query.addBindValue(username);
        query.addBindValue(password);
        query.exec();

        query.prepare("insert into person values(?, ?, 2, -3)");
        query.addBindValue(id);
        query.addBindValue(name);
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
        query.prepare("INSERT INTO delay values(?, ?)");
        query.addBindValue(sId);
        query.addBindValue(delayTime);
        query.exec();

        query.prepare("SELECT time FROM delay WHERE id=?");
        query.addBindValue(sId);
        query.exec();
        query.first();


    }

    std::vector<float> getAllDelays(int sId)
    {
        std::vector<float> delays;

        QSqlQuery query;
        query.prepare("SELECT time FROM delay WHERE sId=?");
        query.addBindValue(sId);
        query.exec();
        query.first();

        if (query.isValid())
        {
            delays.push_back(query.value(0).toFloat());
            while (query.next())
            {
                delays.push_back(query.value(0).toFloat());

            }
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
        if (query.isValid())
            return query.value(0).toInt();
        else
            return -2;
    }

    int getTeacherClass(int id)
    {
        if (id == 1)
            return -2;
        QSqlQuery query;
        query.prepare("SELECT classID FROM person WHERE state=2 AND id=?");
        query.addBindValue(id);
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

    std::vector<int> getStudentIDs(int current_class)
    {
        std::vector<int> ids;

        QSqlQuery query;
        if (current_class == -3)
            query.exec("SELECT id FROM student");
        else
        {
            query.prepare("SELECT id FROM student WHERE classID=?");
            query.addBindValue(current_class);
            query.exec();
        }
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

    std::vector<QString> getStudentNames(int current_class)
    {
        std::vector<QString> names;

        QSqlQuery query;
        if (current_class == -2)
        {
            query.exec("SELECT name FROM student");
        }
        else
        {
            query.prepare("SELECT name FROM student WHERE classID=?");
            query.addBindValue(current_class);
            query.exec();
        }
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

    void removeStudent(int id, bool is_admin)
    {
        QSqlQuery query;
        if (is_admin)
        {
            query.prepare("DELETE FROM student WHERE id=?");
        }
        else
        {
            query.prepare("UPDATE student SET classID=-1 WHERE id=?");
        }
        query.addBindValue(id);
        query.exec();
    }

    float getStudentScore(int id, int course)
    {
        QSqlQuery query;
        if (course == 0)
        {
            query.prepare("SELECT mathScore FROM student WHERE id=?");
            query.addBindValue(id);
            query.exec();
            query.first();
            return query.value(0).toFloat();
        }
        else if (course == 1)
        {
            query.prepare("SELECT physicsScore FROM student WHERE id=?");
            query.addBindValue(id);
            query.exec();
            query.first();
            return query.value(0).toFloat();
        }
        else if (course == 2)
        {
            query.prepare("SELECT literatureScore FROM student WHERE id=?");
            query.addBindValue(id);
            query.exec();
            query.first();
            return query.value(0).toFloat();
        }
        else if (course == 3)
        {
            query.prepare("SELECT theologyScore FROM student WHERE id=?");
            query.addBindValue(id);
            query.exec();
            query.first();
            return query.value(0).toFloat();
        }
        else if (course == 4)
        {
            query.prepare("SELECT geographyScore FROM student WHERE id=?");
            query.addBindValue(id);
            query.exec();
            query.first();
            return query.value(0).toFloat();
        }
        else if (course == 5)
        {
            query.prepare("SELECT chemestryScore FROM student WHERE id=?");
            query.addBindValue(id);
            query.exec();
            query.first();
            return query.value(0).toFloat();
        }
        else if (course == 6)
        {
            query.prepare("SELECT disciplinaryScore FROM student WHERE id=?");
            query.addBindValue(id);
            query.exec();
            query.first();
            return query.value(0).toFloat();
        }
    }

    void setStudentScore(int id, int course, float score)
    {
        QSqlQuery query;
        switch (course)
        {
            case 0:
                query.prepare("UPDATE student SET mathScore=? WHERE id=?");
                query.addBindValue(score);
                query.addBindValue(id);
                query.exec();
                break;
            case 1:
                query.prepare("UPDATE student SET physicsScore=? WHERE id=?");
                query.addBindValue(score);
                query.addBindValue(id);
                query.exec();
                break;
            case 2:
                query.prepare("UPDATE student SET literatureScore=? WHERE id=?");
                query.addBindValue(score);
                query.addBindValue(id);
                query.exec();
                break;
            case 3:
                query.prepare("UPDATE student SET theologyScore=? WHERE id=?");
                query.addBindValue(score);
                query.addBindValue(id);
                query.exec();
                break;
            case 4:
                query.prepare("UPDATE student SET geographyScore=? WHERE id=?");
                query.addBindValue(score);
                query.addBindValue(id);
                query.exec();
                break;
            case 5:
                query.prepare("UPDATE student SET chemestryScore=? WHERE id=?");
                query.addBindValue(score);
                query.addBindValue(id);
                query.exec();
                break;
            case 6:
                query.prepare("UPDATE student SET disciplinaryScore=? WHERE id=?");
                query.addBindValue(score);
                query.addBindValue(id);
                query.exec();
                break;
        }
    }

    void changePassword(int id,QString password)
    {
        QSqlQuery query;
        query.prepare("UPDATE password SET password=? WHERE id=?");
        query.addBindValue(password);
        query.addBindValue(id);
        query.exec();

    }

    int getTeacherNumber()
    {
        QSqlQuery query;
        query.exec("SELECT name FROM person");
        query.first();

        int max = 2;

        while (query.next())
        {
            max++;
        }

        return max;
    }

    bool isUser(QString user)
    {
        QSqlQuery query;
        qDebug() << user;
        query.exec("SELECT * FROM password WHERE id=2");
        //query.addBindValue(user);
        //query.exec();
        qDebug() << query.value(0).toString();

        return query.isValid();

    }
};

#endif
