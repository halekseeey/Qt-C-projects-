#include "FormulaDecorator.h"

QString FormulaDecorator::operation() const {
    QString text = component->operation();
    QRegularExpression regex(R"((\d+)\s*([\+\-])\s*(\d+))");
    QRegularExpressionMatchIterator it = regex.globalMatch(text);
    QString result = text;
    int formulaCounter = 1;

    while (it.hasNext()) {
        QRegularExpressionMatch match = it.next();
        int num1 = match.captured(1).toInt();
        int num2 = match.captured(3).toInt();
        QString operation = match.captured(2);
        int calculationResult = (operation == "+") ? (num1 + num2) : (num1 - num2);

        result.replace(match.captured(0), QString::number(calculationResult) + " (Формула " + QString::number(formulaCounter++) + ")");
    }

    return result;
}
