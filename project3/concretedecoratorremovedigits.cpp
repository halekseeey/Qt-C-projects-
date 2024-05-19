#include "ConcreteDecoratorRemoveDigits.h"

QString ConcreteDecoratorRemoveDigits::operation() const {
    QString result;
    QString original = component->operation();
    for (const QChar &ch : original) {
        if (ch.isDigit() && ch != '0') continue;
        result.append(ch);
    }
    return result;
}
