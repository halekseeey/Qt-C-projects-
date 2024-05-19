#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QMap>
#include <QVector>
#include "Course.h" // Для использования Course::GradeType

class Student {
public:
    Student(const QString &name);

    void enrollCourse(const QString &courseName);
    void addGrade(const QString &courseName, Course::GradeType type, int grade);
    QString getName() const;
    // Обновленный тип для хранения нескольких оценок по каждому типу заданий
    QMap<QString, QMap<Course::GradeType, QVector<int>>> getCoursesGrades() const;

private:
    QString name;
    // Используем QVector<int> для хранения массива оценок
    QMap<QString, QMap<Course::GradeType, QVector<int>>> coursesGrades;
};

#endif // STUDENT_H
