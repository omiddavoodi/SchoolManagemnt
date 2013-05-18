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

Program::Program(bool isadmin, int userid,int _id, QWidget *parent)
    : QWidget(parent)
{

    QString tempTeacherName;
    QString tempStudentName;

    this->is_admin = isadmin;
    this->user_id = userid;
    this->ID = _id;
    //setting program options
    if (this->is_admin)
        this->setFixedSize(480, 275);
    else
        this->setFixedSize(240, 245);
    this->setWindowTitle("IUST School!");
    std::vector<QString> names;
    if (is_admin)
    {
        grpTeachers = new QGroupBox(this);
        grpTeachers->setGeometry(245, 3, 233,100);

        teachersCombo = new QComboBox();

        names = sql.getTeacherNames();
        int numTeachers = names.size();
        for (int i = 0; i < numTeachers; ++i)
        {
            teachersCombo->addItem(names[i],i);
        }
        teachersCombo->setParent(grpTeachers);
        teachersCombo->setGeometry(10,2,140,20);

        tempTeacherName = teachersCombo->itemText(teachersCombo->currentIndex());

        connect(teachersCombo,SIGNAL(currentIndexChanged(int)),this,SLOT(UpdateTeacherData()));

        label1 = new QLabel("معلم");
        label1->setGeometry(158, 2, 60, 20);
        label1->setParent(grpTeachers);

        label2 = new QLabel("نام:");
        label2->setGeometry(158, 24, 60, 20);
        label2->setParent(grpTeachers);

        label3 = new QLabel();
        label3->setGeometry(10, 24, 140, 20);
        label3->setAlignment(Qt::AlignLeft | Qt::AlignCenter);
        label3->setText(tempTeacherName);
        label3->setParent(grpTeachers);

        label4 = new QLabel("کلاس فعلی:");
        label4->setGeometry(158, 48, 60, 20);
        label4->setParent(grpTeachers);

        label5 = new QLabel();
        label5->setGeometry(10, 48, 140, 20);
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
        classCombo->setGeometry(10,72,140,20);

        btnAddTeacherToClass = new QPushButton("تخصیص");
        btnAddTeacherToClass->setGeometry(160, 71, 60, 22);
        btnAddTeacherToClass->setParent(grpTeachers);

        connect(btnAddTeacherToClass, SIGNAL(clicked()), this, SLOT(bindTeacher()));

        grpDelays = new QGroupBox(this);
        grpDelays->setGeometry(245, 107, 233,100);

        btnFileDelayForStudent = new QPushButton("ثبت تاخیر برای دانش آموز", grpDelays);
        btnFileDelayForStudent->setGeometry(10, 5, 220, 24);

        connect(btnFileDelayForStudent, SIGNAL(clicked()), this, SLOT(addDelay()));

        delaysList = new QListWidget(grpDelays);
        delaysList->setGeometry(10, 35, 220, 60);

        grpAdminPanel = new QGroupBox(this);
        grpAdminPanel->setGeometry(245, 210, 233,54);

        btnAdminChangePassword = new QPushButton("تغییر رمز", grpAdminPanel);
        btnAdminChangePassword->setGeometry(10,1,213,22);

        connect(btnAdminChangePassword, SIGNAL(clicked()), this, SLOT(adminChangePassword()));

        btnAddTeacher = new QPushButton("اضافه کردن معلم", grpAdminPanel);
        btnAddTeacher->setGeometry(10,27,213,22);

        connect(btnAddTeacher, SIGNAL(clicked()), this, SLOT(addTeacher()));
    }

    grpStudents = new QGroupBox(this);
    if (is_admin)
        grpStudents->setGeometry(5, 3, 233,260);
    else
        grpStudents->setGeometry(5, 3, 233,230);
    studentsCombo = new QComboBox();

    std::vector<int> ids = sql.getStudentIDs(this->user_id);
    names = sql.getStudentNames(this->user_id);
    int numStudents = names.size();
    for (int i = 0; i < numStudents; ++i)
    {
        studentsCombo->addItem(names[i],ids[i]);
    }
    studentsCombo->setParent(grpStudents);
    studentsCombo->setGeometry(10,2,140,20);

    tempStudentName = studentsCombo->itemText(studentsCombo->currentIndex());

    connect(studentsCombo,SIGNAL(currentIndexChanged(int)),this,SLOT(UpdateStudentData()));

    label1s = new QLabel("دانش آموز");
    label1s->setGeometry(158, 2, 60, 20);
    label1s->setParent(grpStudents);

    label2s = new QLabel("نام:");
    label2s->setGeometry(188, 22, 30, 18);
    label2s->setParent(grpStudents);

    label3s = new QLabel();
    label3s->setGeometry(10, 22, 190, 18);
    label3s->setAlignment(Qt::AlignLeft | Qt::AlignCenter);
    label3s->setText(studentsCombo->itemText(studentsCombo->currentIndex()));
    label3s->setParent(grpStudents);

    label4s = new QLabel("کلاس فعلی:");
    label4s->setGeometry(158, 40, 60, 18);
    label4s->setParent(grpStudents);

    label5s = new QLabel();
    label5s->setGeometry(80, 40, 70, 18);
    label5s->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    label5s->setText(getClassName(sql.getStudentClass(tempStudentName)));
    label5s->setParent(grpStudents);

    label6s = new QLabel("ریاضی:");
    label6s->setGeometry(180, 58, 40, 18);
    label6s->setParent(grpStudents);

    label7s = new QLabel();
    label7s->setGeometry(110, 58, 50, 18);
    label7s->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    label7s->setParent(grpStudents);

    label8s = new QLabel("فیزیک:");
    label8s->setGeometry(70, 58, 40, 18);
    label8s->setParent(grpStudents);

    label9s = new QLabel();
    label9s->setGeometry(10, 58, 50, 18);
    label9s->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    label9s->setParent(grpStudents);

    label10s = new QLabel("فارسی:");
    label10s->setGeometry(180, 76, 40, 18);
    label10s->setParent(grpStudents);

    label11s = new QLabel();
    label11s->setGeometry(110, 76, 50, 18);
    label11s->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    label11s->setParent(grpStudents);

    label12s = new QLabel("دینی:");
    label12s->setGeometry(70, 76, 40, 18);
    label12s->setParent(grpStudents);

    label13s = new QLabel();
    label13s->setGeometry(10, 76, 50, 18);
    label13s->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    label13s->setParent(grpStudents);

    label14s = new QLabel("جغرافی:");
    label14s->setGeometry(180, 94, 40, 18);
    label14s->setParent(grpStudents);

    label15s = new QLabel();
    label15s->setGeometry(110, 94, 50, 18);
    label15s->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    label15s->setParent(grpStudents);

    label16s = new QLabel("شیمی:");
    label16s->setGeometry(70, 94, 40, 18);
    label16s->setParent(grpStudents);

    label17s = new QLabel();
    label17s->setGeometry(10, 94, 50, 18);
    label17s->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    label17s->setParent(grpStudents);

    label18s = new QLabel("انظباط:");
    label18s->setGeometry(180, 112, 40, 18);
    label18s->setParent(grpStudents);

    label19s = new QLabel();
    label19s->setGeometry(110, 112, 50, 18);
    label19s->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    label19s->setParent(grpStudents);

    label20s = new QLabel("معدل:");
    label20s->setGeometry(70, 112, 40, 18);
    label20s->setParent(grpStudents);

    label21s = new QLabel();
    label21s->setGeometry(10, 112, 50, 18);
    label21s->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    label21s->setParent(grpStudents);

    update_student_scores();

    if (is_admin)
    {

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
        classSCombo->setGeometry(10,140,140,24);

        btnAddStudentToClass = new QPushButton("تخصیص");
        btnAddStudentToClass->setGeometry(160, 140, 60, 24);
        btnAddStudentToClass->setParent(grpStudents);

        connect(btnAddStudentToClass, SIGNAL(clicked()), this, SLOT(bindStudent()));

        btnAddStudent = new QPushButton("اضافه کردن دانش آموز جدید");
        btnAddStudent->setGeometry(70, 170, 150, 24);
        btnAddStudent->setParent(grpStudents);

        connect(btnAddStudent, SIGNAL(clicked()), this, SLOT(addNewStudent()));

        btnRemoveStudent = new QPushButton("حذف کردن دانش آموز کنونی");
        btnRemoveStudent->setGeometry(70, 200, 150, 24);
        btnRemoveStudent->setParent(grpStudents);

        connect(btnRemoveStudent, SIGNAL(clicked()), this, SLOT(removeCurrentStudent()));

        btnScoring = new QPushButton("نمره دهی");
        btnScoring->setGeometry(140, 230, 80, 24);
        btnScoring->setParent(grpStudents);

        connect(btnScoring, SIGNAL(clicked()), this, SLOT(setStudentScore()));

        coursesCombo = new QComboBox();

        coursesCombo->addItem("انظباط", 6);

        coursesCombo->setParent(grpStudents);
        coursesCombo->setGeometry(10,230,120,24);

        update_delays();
    }
    else
    {

        btnRemoveStudent = new QPushButton("اخراج دانش آموز کنونی");
        btnRemoveStudent->setGeometry(70, 140, 150, 24);
        btnRemoveStudent->setParent(grpStudents);

        connect(btnRemoveStudent, SIGNAL(clicked()), this, SLOT(removeCurrentStudent()));

        btnScoring = new QPushButton("نمره دهی");
        btnScoring->setGeometry(140, 170, 80, 24);
        btnScoring->setParent(grpStudents);

        connect(btnScoring, SIGNAL(clicked()), this, SLOT(setStudentScore()));

        coursesCombo = new QComboBox();

        coursesCombo->addItem("ریاضی", 0);
        coursesCombo->addItem("فیزیک", 1);
        coursesCombo->addItem("فارسی", 2);
        coursesCombo->addItem("دینی", 3);
        coursesCombo->addItem("جغرافی", 4);
        coursesCombo->addItem("شیمی", 5);

        coursesCombo->setParent(grpStudents);
        coursesCombo->setGeometry(10,170,120,24);

        btnTeacherChangePassword = new QPushButton("تغییر رمز", grpStudents);
        btnTeacherChangePassword->setGeometry(70, 200, 150, 24);

        connect(btnTeacherChangePassword, SIGNAL(clicked()), this, SLOT(changeTeacherPassword()));
    }
}


void Program::UpdateTeacherData()
{
    QString tempName = teachersCombo->itemText(teachersCombo->currentIndex());
    label3->setText(tempName);
    label5->setText(getClassName(sql.getTeacherClass(tempName)));
    update_student_scores();
}

void Program::bindTeacher()
{
    bool result = sql.setTecherClass(teachersCombo->currentIndex()+2,classCombo->currentIndex());
    if (!result)
        qDebug() << "Hoooooy";
    UpdateTeacherData();
}

void Program::UpdateStudentData()
{
    QString tempName = studentsCombo->itemText(studentsCombo->currentIndex());
    label3s->setText(tempName);
    label5s->setText(getClassName(sql.getStudentClass(tempName)));
    update_delays();
    update_student_scores();
}

void Program::bindStudent()
{
    sql.setStudentClass(studentsCombo->itemData(studentsCombo->currentIndex()).toInt(),classSCombo->currentIndex());
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
        std::vector<int> ids = sql.getStudentIDs(user_id);
        std::vector<QString>names = sql.getStudentNames(user_id);
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
    sql.removeStudent(studentsCombo->itemData(studentsCombo->currentIndex()).toInt(), is_admin);
    studentsCombo->clear();
    std::vector<int> ids = sql.getStudentIDs(user_id);
    std::vector<QString>names = sql.getStudentNames(user_id);
    int numStudents = names.size();
    for (int i = 0; i < numStudents; ++i)
    {
        studentsCombo->addItem(names[i],ids[i]);
    }
    update_delays();
}

void Program::update_student_scores()
{
    int id = studentsCombo->itemData(studentsCombo->currentIndex()).toInt();
    float a1 = sql.getStudentScore(id, 0),
          a2 = sql.getStudentScore(id, 1),
          a3 = sql.getStudentScore(id, 2),
          a4 = sql.getStudentScore(id, 3),
          a5 = sql.getStudentScore(id, 4),
          a6 = sql.getStudentScore(id, 5),
          a7 = sql.getStudentScore(id, 6), a8;
    a8 = (a1+a2+a3+a4+a5+a6+a7)/7;
    label7s->setText(QVariant(a1).toString());
    label9s->setText(QVariant(a2).toString());
    label11s->setText(QVariant(a3).toString());
    label13s->setText(QVariant(a4).toString());
    label15s->setText(QVariant(a5).toString());
    label17s->setText(QVariant(a6).toString());
    label19s->setText(QVariant(a7).toString());
    label21s->setText(QVariant(a8).toString());
}

void Program::setStudentScore()
{
    QInputDialog message;
    bool ok;
    float score = message.getDouble(this, "نمره دهی",
                                   "نمره را وارد کنید",0,0,20,2 ,&ok);
    if (ok == true)
    {
        sql.setStudentScore(studentsCombo->itemData(studentsCombo->currentIndex()).toInt(),coursesCombo->itemData(coursesCombo->currentIndex()).toInt(),score);
        update_student_scores();
    }
}

void Program::addDelay()
{
    QInputDialog message;
    bool ok;
    float score = message.getDouble(this, "تاخیر",
                                   "مقدار زمان تاخیر را وارد کنید",0,0,200,2 ,&ok);
    if (ok == true)
    {
        sql.addDelay(studentsCombo->itemData(studentsCombo->currentIndex()).toInt(),score);
        update_delays();
    }
}

void Program::update_delays()
{
    if (is_admin)
    {
        delaysList->clear();
        if (studentsCombo->count() != 0)
        {
            std::vector<float> temp = sql.getAllDelays(studentsCombo->itemData(studentsCombo->currentIndex()).toInt());
            for (int i = 0; i < temp.size(); ++i)
            {
                delaysList->addItem(QVariant(temp[i]).toString());
            }
        }
    }
}

Program::~Program()
{
    sql.mycommit();
    delete layout;
    delete classLayout;
    delete classCombo;
    delete teachersCombo;
    delete btnAddTeacherToClass;
    delete grpTeachers;
    delete grpStudents;
    delete grpDelays;
    delete grpAdminPanel;
    delete label1;
    delete label2;
    delete label3;
    delete label4;
    delete label5;
    delete label1s;
    delete label2s;
    delete label3s;
    delete label4s;
    delete label5s;
    delete label6s;
    delete label7s;
    delete label8s;
    delete label9s;
    delete label10s;
    delete label11s;
    delete label12s;
    delete label13s;
    delete label14s;
    delete label15s;
    delete label16s;
    delete label17s;
    delete label18s;
    delete label19s;
    delete label20s;
    delete label21s;
    delete btnAddStudentToClass;
    delete btnFileDelayForStudent;
    delete classSCombo;
    delete studentsCombo;
    delete btnAddStudent;
    delete btnRemoveStudent;
    delete btnScoring;
    delete coursesCombo;
    delete delaysList;
    delete btnTeacherChangePassword;
    delete btnAdminChangePassword;
    delete btnAddTeacher;
    delete addTeach;
    delete changePass;
}

void Program::changeTeacherPassword()
{
    changePass = new changePassword(this->ID);
    changePass->show();
}

void Program::adminChangePassword()
{
    changePass = new changePassword(this->ID);
    changePass->show();
}


void Program::addTeacher()
{
    addTeach = new AddTeacher();
    addTeach->show();
}

