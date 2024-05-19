#ifndef DECTOHEXDECORATOR_H
#define DECTOHEXDECORATOR_H

#include "Decorator.h"

class DecToHexDecorator : public Decorator {
public:
    using Decorator::Decorator;
    QString operation() const override;
};

#endif // DECTOHEXDECORATOR_H
