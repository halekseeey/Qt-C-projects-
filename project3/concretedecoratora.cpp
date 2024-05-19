#include "ConcreteDecoratorA.h"
#include <algorithm>

QString ConcreteDecoratorA::operation() const {
    QString original = component->operation();
    std::reverse(original.begin(), original.end());
    return original;
}
