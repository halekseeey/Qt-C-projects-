#ifndef CONCRETEDECORATORREMOVEDIGITS_H
#define CONCRETEDECORATORREMOVEDIGITS_H

#include "Decorator.h"

class ConcreteDecoratorRemoveDigits : public Decorator {
public:
    using Decorator::Decorator;
    QString operation() const override;
};

#endif // CONCRETEDECORATORREMOVEDIGITS_H
