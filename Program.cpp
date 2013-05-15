#include "Program.h"

QString getClassName(int id)
{
    switch (id)
    {
        case 0:
            return "1/1";
        case 1:
            return "1/2";
        case 2:
            return "2/1";
        case 3:
            return "2/2";
        case 4:
            return "3/1";
        case 5:
            return "3/2";
        case 6:
            return "4/1";
        case 7:
            return "4/2";
        case 8:
            return "5/1";
        case 9:
            return "5/2";
        case 10:
            return "6/1";
        case 11:
            return "6/2";
    }
    return "هیچ کدام";
}

Program::Program(QWidget *parent)
    : QWidget(parent)
{

    QString tempTeacherName;
    QString tempStudentName;

    //setting program options
    this->setFixedSize(480, 255);
    this->setWindowTitle("IUST School!");

    for (int i = 0; i < 12; ++i)
    {
        SClass s;
        s.teacherID = -1;
        classes.push_back(s);
    }

    grpTeachers = new QGroupBox(this);
    grpTeachers->setGeometry(245, 10, 233,240);

    teachersCombo = new QComboBox();

    std::vector<QString> names = sql.getTeacherNames();
    int numTeachers = names.size();
    for (int i = 0; i < numTeachers; ++i)
    {
        teachersCombo->addItem(names[i],i);
    }
    teachersCombo->setParent(grpTeachers);
    teachersCombo->setGeometry(10,2,140,24);

    tempTeacherName = teachersCombo->itemText(teachersCombo->currentIndex());

    connect(teachersCombo,SIGNAL(currentIndexChanged(int)),this,SLOT(UpdateTeacherData()));

    label1 = new QLabel("معلم");
    label1->setGeometry(158, 2, 60, 24);
    label1->setParent(grpTeachers);

    label2 = new QLabel("نام:");
    label2->setGeometry(158, 30, 60, 24);
    label2->setParent(grpTeachers);

    label3 = new QLabel();
    label3->setGeometry(10, 30, 140, 24);
    label3->setAlignment(Qt::AlignLeft | Qt::AlignCenter);
    label3->setText(tempTeacherName);
    label3->setParent(grpTeachers);

    label4 = new QLabel("کلاس فعلی:");
    label4->setGeometry(158, 60, 60, 24);
    label4->setParent(grpTeachers);

    label5 = new QLabel();
    label5->setGeometry(10, 60, 140, 24);
    label5->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    label5->setText(getClassName(sql.getTeacherClass(tempTeacherName)));
    label5->setParent(grpTeachers);

    classCombo = new QComboBox();
    classCombo->addItem("1/1");
    classCombo->addItem("1/2");
    classCombo->addItem("2/1");
    classCombo->addItem("2/2");
    classCombo->addItem("3/1");
    classCombo->addItem("3/2");
    classCombo->addItem("4/1");
    classCombo->addItem("4/2");
    classCombo->addItem("5/1");
    classCombo->addItem("5/2");
    classCombo->addItem("6/1");
    classCombo->addItem("6/2");
    classCombo->setParent(grpTeachers);
    classCombo->setGeometry(10,90,140,24);

    btnAddTeacherToClass = new QPushButton("تخصیص");
    btnAddTeacherToClass->setGeometry(160, 90, 60, 24);
    btnAddTeacherToClass->setParent(grpTeachers);

    connect(btnAddTeacherToClass, SIGNAL(clicked()), this, SLOT(bindTeacher()));

    grpStudents = new QGroupBox(this);
    grpStudents->setGeometry(5, 10, 233,240);

    studentsCombo = new QComboBox();
    std::vector<int> ids = sql.getStudentIDs();
    names = sql.getStudentNames();
    int numStudents = names.size();
    for (int i = 0; i < numStudents; ++i)
    {
        studentsCombo->addItem(names[i],ids[i]);
    }
    studentsCombo->setParent(grpStudents);
    studentsCombo->setGeometry(10,2,140,24);

    tempStudentName = studentsCombo->itemText(studentsCombo->currentIndex());

    connect(studentsCombo,SIGNAL(currentIndexChanged(int)),this,SLOT(UpdateStudentData()));

    label1s = new QLabel("دانش آموز");
    label1s->setGeometry(158, 2, 60, 24);
    label1s->setParent(grpStudents);

    label2s = new QLabel("نام:");
    label2s->setGeometry(158, 30, 60, 24);
    label2s->setParent(grpStudents);

    label3s = new QLabel();
    label3s->setGeometry(10, 30, 140, 24);
    label3s->setAlignment(Qt::AlignLeft | Qt::AlignCenter);
    label3s->setText(studentsCombo->itemText(studentsCombo->currentIndex()));
    label3s->setParent(grpStudents);

    label4s = new QLabel("کلاس فعلی:");
    label4s->setGeometry(158, 60, 60, 24);
    label4s->setParent(grpStudents);

    label5s = new QLabel();
    label5s->setGeometry(10, 60, 140, 24);
    label5s->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    label5s->setText(getClassName(sql.getStudentClass(tempStudentName)));
    label5s->setParent(grpStudents);

    classSCombo = new QComboBox();
    classSCombo->addItem("1/1");
    classSCombo->addItem("1/2");
    classSCombo->addItem("2/1");
    classSCombo->addItem("2/2");
    classSCombo->addItem("3/1");
    classSCombo->addItem("3/2");
    classSCombo->addItem("4/1");
    classSCombo->addItem("4/2");
    classSCombo->addItem("5/1");
    classSCombo->addItem("5/2");
    classSCombo->addItem("6/1");
    classSCombo->addItem("6/2");
    classSCombo->setParent(grpStudents);
    classSCombo->setGeometry(10,120,140,24);

    btnAddStudentToClass = new QPushButton("تخصیص");
    btnAddStudentToClass->setGeometry(160, 120, 60, 24);
    btnAddStudentToClass->setParent(grpStudents);

    connect(btnAddStudentToClass, SIGNAL(clicked()), this, SLOT(bindStudent()));

    btnAddStudent = new QPushButton("اضافه کردن دانش آموز جدید");
    btnAddStudent->setGeometry(70, 150, 150, 24);
    btnAddStudent->setParent(grpStudents);

    connect(btnAddStudent, SIGNAL(clicked()), this, SLOT(addNewStudent()));

    btnRemoveStudent = new QPushButton("حذف کردن دانش آموز کنونی");
    btnRemoveStudent->setGeometry(70, 180, 150, 24);
    btnRemoveStudent->setParent(grpStudents);

    connect(btnRemoveStudent, SIGNAL(clicked()), this, SLOT(removeCurrentStudent()));

    btnScoring = new QPushButton("نمره دهی");
    btnScoring->setGeometry(140, 210, 80, 24);
    btnScoring->setParent(grpStudents);

    coursesCombo = new QComboBox();
    coursesCombo->addItem("ریاضی");
    coursesCombo->addItem("علوم");
    coursesCombo->addItem("فارسی");
    coursesCombo->addItem("دینی");
    coursesCombo->addItem("جغرافی");
    coursesCombo->setParent(grpStudents);
    coursesCombo->setGeometry(10,210,120,24);
}


void Program::UpdateTeacherData()
{
    QString tempName = teachersCombo->itemText(teachersCombo->currentIndex());
    label3->setText(tempName);
    label5->setText(getClassName(sql.getTeacherClass(tempName)));
}

void Program::bindTeacher()
{
    bool result = sql.setTecherClass(teachersCombo->currentIndex()+1,classCombo->currentIndex());
    if (!result)
        qDebug() << "Hoooooy";
    UpdateTeacherData();
}

void Program::UpdateStudentData()
{
    QString tempName = studentsCombo->itemText(studentsCombo->currentIndex());
    label3s->setText(tempName);
    label5s->setText(getClassName(sql.getStudentClass(tempName)));
}

void Program::bindStudent()
{
    bool result = sql.setStudentClass(studentsCombo->itemData(studentsCombo->currentIndex()).toInt(),classSCombo->currentIndex());
    if (!result)
        qDebug() << "Hoooooy";
    UpdateStudentData();
}

void Program::addNewStudent()
{
    QInputDialog message;
    bool ok;
    QString name = message.getText(this, "اضافه کردن دانش آموز",
                                   "نام دانش آموز را وارد کنید", QLineEdit::Normal,
                                   "", &ok);
    if (ok == true && name != "")
    {
        sql.addStudent(sql.maxStudents+1,name);
        std::vector<int> ids = sql.getStudentIDs();
        std::vector<QString>names = sql.getStudentNames();
        studentsCombo->clear();
        int numStudents = names.size();
        for (int i = 0; i < numStudents; ++i)
        {
            studentsCombo->addItem(names[i],ids[i]);
        }
    }
}

void Program::removeCurrentStudent()
{
    sql.removeStudent(studentsCombo->itemData(studentsCombo->currentIndex()).toInt());
    studentsCombo->clear();
    std::vector<int> ids = sql.getStudentIDs();
    std::vector<QString>names = sql.getStudentNames();
    int numStudents = names.size();
    for (int i = 0; i < numStudents; ++i)
    {
        studentsCombo->addItem(names[i],ids[i]);
    }
}

Program::~Program()
{

}
