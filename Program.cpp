#include "Program.h"

Program::Program(QWidget *parent)
    : QWidget(parent)
{
    //setting program options
    this->setFixedSize(480, 255);
    this->setWindowTitle("IUST School!");

    StuData = new StudentData();

    grpTeachers = new QGroupBox(this);
    grpTeachers->setGeometry(245, 10, 233,240);

    teachersCombo = new QComboBox();
    teachersCombo->addItem("غلام");
    teachersCombo->addItem("شلغم");
    teachersCombo->addItem("تپل");
    teachersCombo->addItem("مرتضی");
    teachersCombo->addItem("قلیدون");
    teachersCombo->addItem("شاخ طلا");
    teachersCombo->setParent(grpTeachers);
    teachersCombo->setGeometry(10,2,140,24);

    label1 = new QLabel("معلم");
    label1->setGeometry(158, 2, 60, 24);
    label1->setParent(grpTeachers);

    label2 = new QLabel("نام:");
    label2->setGeometry(158, 30, 60, 24);
    label2->setParent(grpTeachers);

    label3 = new QLabel();
    label3->setGeometry(10, 30, 140, 24);
    label3->setAlignment(Qt::AlignLeft | Qt::AlignCenter);
    label3->setText(teachersCombo->itemText(teachersCombo->currentIndex()));
    label3->setParent(grpTeachers);

    label4 = new QLabel("کلاس فعلی:");
    label4->setGeometry(158, 60, 60, 24);
    label4->setParent(grpTeachers);

    label5 = new QLabel();
    label5->setGeometry(10, 60, 140, 24);
    label5->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    label5->setText("هیچ کدام");
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

    grpStudents = new QGroupBox(this);
    grpStudents->setGeometry(5, 10, 233,240);

    studentsCombo = new QComboBox();
    studentsCombo->addItem("علی");
    studentsCombo->addItem("قلی");
    studentsCombo->addItem("حسن");
    studentsCombo->addItem("حسین");
    studentsCombo->addItem("پشمک");
    studentsCombo->addItem("زردآلو");
    studentsCombo->setParent(grpStudents);
    studentsCombo->setGeometry(10,2,140,24);

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
    label5s->setText("هیچ کدام");
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
    classSCombo->setGeometry(10,90,140,24);

    btnAddStudentToClass = new QPushButton("تخصیص");
    btnAddStudentToClass->setGeometry(160, 90, 60, 24);
    btnAddStudentToClass->setParent(grpStudents);

    btnAddStudent = new QPushButton("اضافه کردن دانش آموز جدید");
    btnAddStudent->setGeometry(70, 120, 150, 24);
    btnAddStudent->setParent(grpStudents);

    btnRemoveStudent = new QPushButton("حذف کردن دانش آموز قدیمی");
    btnRemoveStudent->setGeometry(70, 150, 150, 24);
    btnRemoveStudent->setParent(grpStudents);

    btnShowStudentData = new QPushButton("مشاهده وضعیت دانش آموزان");
    btnShowStudentData->setGeometry(70, 180, 150, 24);
    btnShowStudentData->setParent(grpStudents);

    connect(btnShowStudentData,SIGNAL(clicked()),this,SLOT(ShowStuData()));

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

void Program::ShowStuData()
{
    StuData->show();
}


Program::~Program()
{

}
