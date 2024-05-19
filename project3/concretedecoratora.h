#ifndef CONCRETEDECORATORA_H
#define CONCRETEDECORATORA_H

#include "Decorator.h"

class ConcreteDecoratorA : public Decorator {
public:
    using Decorator::Decorator; // Используем конструктор базового класса
    QString operation() const override;
};

#endif // CONCRETEDECORATORA_H
