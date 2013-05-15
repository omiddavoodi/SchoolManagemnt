#include "student.h"

student::student()
{
    setChemestryScore(0);
    setGeographyScore(0);
    setLiteratureScore(0);
    setMathScore(0);
    setPhysicsScore(0);
    setTheologyScore(0);
}

void student::addDelay(float delayTime)
{
    delay.push_back(delayTime);
}

float student::getChemestryScore()
{
    return chemestryScore;
}

float student::getGeographyScore()
{
    return geographyScore;
}

float student::getLiteratureScore()
{
    return literatureScore;
}

float student::getMathScore()
{
    return mathScore;
}

float student::getPhysicsScore()
{
    return physicsScore;
}

float student::getTheologyScore()
{
    return theologyScore;
}

float student::getAverage()
{
    float ave=0;

    ave += getChemestryScore();
    ave += getGeographyScore();
    ave += getLiteratureScore();
    ave += getMathScore();
    ave += getPhysicsScore();
    ave += getTheologyScore();

    ave = ave/6;

    return ave;
}
