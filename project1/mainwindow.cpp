#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFormLayout>
#include "Course.h"
#include "gradebook.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создаем виджет, который будет центральным виджетом
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget); // Устанавливаем его как центральный виджет

    // Создаем компоновку
    QWidget *formCourseWidget = new QWidget(this);
    QFormLayout *layout = new QFormLayout(formCourseWidget);

    layout->addRow(tr("Course Name:"), ui->courseName);
    layout->addRow(tr("Practical Tasks:"), ui->PracticalTasks);
    layout->addRow(tr("Independed Works:"), ui->IndependedWorks);
    layout->addRow(tr("Homework:"), ui->Homework);
    layout->addRow(tr("Seminars:"), ui->Seminars);
    layout->addRow(tr("Exam:"), ui->Exam);
    layout->addRow(tr(""), ui->AddCourse);
    layout->addRow(tr(""), ui->CloseButton);

    formCourseWidget->setLayout(layout);

    QWidget *mainWidget = new QWidget(this);
    QFormLayout *mainLayout = new QFormLayout(mainWidget);

    mainLayout->addRow(tr("Courses:"), ui->Courses);
    mainLayout->addRow(tr(""), ui->AddCourseMain);
    mainLayout->addRow(tr(""), ui->ShowCourseInfo);
    mainLayout->addRow(tr("Students:"), ui->Students);
    mainLayout->addRow(tr(""), ui->AddStudentMain);
    mainLayout->addRow(tr(""), ui->ShowStudentInfo);

    ui->tableView->setModel(model);
    ui->tableView->setShowGrid(true);

    stackedWidget->addWidget(mainWidget);
    stackedWidget->addWidget(formCourseWidget);


    // stackedWidget->addWidget(secondWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AddCourse_clicked()
{
    QString courseName = ui->courseName->text();
    Course newCourse(courseName);

    int practicalTasksCoefficient = ui->PracticalTasks->text().toInt();
    newCourse.setCoefficient(Course::PracticalTasks, practicalTasksCoefficient);

    int independedWorksCoefficient = ui->IndependedWorks->text().toInt();
    newCourse.setCoefficient(Course::IndependendWorks, independedWorksCoefficient);

    int homeworkCoefficient = ui->Homework->text().toInt();
    newCourse.setCoefficient(Course::Homework, homeworkCoefficient);

    int seminarsCoefficient = ui->Seminars->text().toInt();
    newCourse.setCoefficient(Course::Seminars, seminarsCoefficient);

    int examCoefficient = ui->Exam->text().toInt();
    newCourse.setCoefficient(Course::Exam, examCoefficient);

    gradebook.addCourse(newCourse);
    ui->Courses->addItem(newCourse.getName());

    ui->courseName->clear();
    ui->PracticalTasks->clear();
    ui->IndependedWorks->clear();
    ui->Homework->clear();
    ui->Seminars->clear();
    ui->Exam->clear();
}


void MainWindow::on_CloseButton_clicked()
{
    stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_AddCourseMain_clicked()
{
    stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_AddStudentMain_clicked()
{
        stackedWidget->setCurrentIndex(2);
}

