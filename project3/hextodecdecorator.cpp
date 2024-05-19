#include "HexToDecDecorator.h"
#include <QRegularExpression>

QString HexToDecDecorator::operation() const {
    QString text = component->operation();
    QRegularExpression regex(R"(0x[0-9A-Fa-f]+)");
    QRegularExpressionMatchIterator it = regex.globalMatch(text);

    while (it.hasNext()) {
        QRegularExpressionMatch match = it.next();
        bool ok;
        int decValue = match.captured(0).toInt(&ok, 16);
        if (ok) {
            text.replace(match.captured(0), QString::number(decValue));
        }
    }

    return text;
}
