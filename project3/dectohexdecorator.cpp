#include "DecToHexDecorator.h"
#include <QRegularExpression>

QString DecToHexDecorator::operation() const {
    QString text = component->operation();
    QRegularExpression regex(R"(\b\d+\b)");
    QRegularExpressionMatchIterator it = regex.globalMatch(text);

    while (it.hasNext()) {
        QRegularExpressionMatch match = it.next();
        int decValue = match.captured(0).toInt();
        text.replace(match.captured(0), QString("0x") + QString::number(decValue, 16).toUpper());
    }

    return text;
}
