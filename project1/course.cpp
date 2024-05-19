#include "course.h"

Course::Course(const QString &name)
    : name(name) {}

QString Course::getName() const {
    return name;
}

QString Course::getGradingFormula() const {
    QString formula;
    for (auto type : coefficients.keys()) {
        QString typeName;
        switch (type) {
        case PracticalTasks:
            typeName = "Practical Tasks";
            break;
        case Seminars:
            typeName = "Seminars";
            break;
        case IndependendWorks:
            typeName = "Independent Works";
            break;
        case Homework:
            typeName = "Homework";
            break;
        case Exam:
            typeName = "Exam";
            break;
        }
        formula += typeName + ": " + QString::number(coefficients.value(type, 0)) + "\n";
    }
    return formula.isEmpty() ? "No grading formula defined." : formula;
}

void Course::setCoefficient(Course::GradeType type, int coefficient) {
    coefficients[type] = coefficient;
}

int Course::getCoefficient(Course::GradeType type) const {
    return coefficients.value(type, 0); // Возвращает 0, если оценка не найдена
}
