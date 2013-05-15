#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <QString>

class student
{
private:
    float mathScore;
    float physicsScore;
    float literatureScore;
    float theologyScore;
    float geographyScore;
    float chemestryScore;
    float disciplinaryScore;

    QString name;

    int id;

    std::vector<float> delay;
public:
    int getId(){return id;}

    void setName(QString name){this->name = name;}

    std::vector<float> getDelay(){return delay;}
    void addDelay(float delayTime);

    void setMathScore(float mathScore){this->mathScore = mathScore;}
    void setPhysicsScore(float physicsScore){this->physicsScore = physicsScore;}
    void setLiteratureScore(float literatureScore){this->literatureScore = literatureScore;}
    void setTheologyScore(float theologyScore){this->theologyScore = theologyScore;}
    void setGeographyScore(float geographyScore){this->geographyScore = geographyScore;}
    void setChemestryScore(float chemestryScore){this->chemestryScore = chemestryScore;}

    float getMathScore();
    float getPhysicsScore();
    float getLiteratureScore();
    float getTheologyScore();
    float getGeographyScore();
    float getChemestryScore();

    float getAverage();

    student();
};

#endif // STUDENT_H
