#ifndef COURSE_H
#define COURSE_H

#include <QString>
#include <QMap>

class Course {
public:
    enum GradeType {
        PracticalTasks,
        Seminars,
        IndependendWorks,
        Homework,
        Exam
    };

    Course(const QString &name);

    QString getName() const;
    QString getGradingFormula() const;

    // Функции для работы с оценками
    void setCoefficient(GradeType type, int coefficient);
    int getCoefficient(GradeType type) const;

private:
    QString name;
    QString gradingFormula;
    QMap<GradeType, int> coefficients; // Словарь для хранения оценок
};

#endif // COURSE_H
