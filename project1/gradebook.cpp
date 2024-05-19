#include "Gradebook.h"

void Gradebook::addCourse(const Course &course) {
    courses.append(course);
}

void Gradebook::addStudent(const Student &student) {
    students.append(student);
}

void Gradebook::enrollStudentToCourse(const QString &studentName, const QString &courseName) {
    for (Student &student : students) {
        if (student.getName() == studentName) {
            student.enrollCourse(courseName);
            break;
        }
    }
}

void Gradebook::addGradeToStudent(const QString &studentName, const QString &courseName, Course::GradeType type, int grade) {
    for (Student &student : students) {
        if (student.getName() == studentName) {
            student.addGrade(courseName, type, grade);
            break;
        }
    }
}

QList<Student> Gradebook::getStudents() const {
    return students;
}

QList<Course> Gradebook::getCourses() const {
    return courses;
}
