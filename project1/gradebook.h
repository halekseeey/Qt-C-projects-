#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <QList>
#include "Student.h"
#include "Course.h"

class Gradebook {
public:
    void addCourse(const Course &course);
    void addStudent(const Student &student);
    void enrollStudentToCourse(const QString &studentName, const QString &courseName);
    void addGradeToStudent(const QString &studentName, const QString &courseName, Course::GradeType type, int grade);
    QList<Student> getStudents() const;
    QList<Course> getCourses() const;

private:
    QList<Student> students;
    QList<Course> courses;
};

#endif // GRADEBOOK_H
