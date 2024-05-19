#include "Student.h"

Student::Student(const QString &name) : name(name) {}

void Student::enrollCourse(const QString &courseName) {
    // Убедимся, что для курса создана запись, если ее еще нет
    if (!coursesGrades.contains(courseName)) {
        coursesGrades[courseName] = QMap<Course::GradeType, QVector<int>>();
    }
}

void Student::addGrade(const QString &courseName, Course::GradeType type, int grade) {
    // Добавляем оценку в массив оценок для соответствующего типа задания
    if (coursesGrades.contains(courseName)) {
        coursesGrades[courseName][type].append(grade);
    }
}

QString Student::getName() const {
    return name;
}

QMap<QString, QMap<Course::GradeType, QVector<int>>> Student::getCoursesGrades() const {
    return coursesGrades;
}
