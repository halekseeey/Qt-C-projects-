#ifndef FORMULADECORATOR_H
#define FORMULADECORATOR_H

#include "Decorator.h"
#include <QRegularExpression>
#include <QRegularExpressionMatchIterator>

class FormulaDecorator : public Decorator {
public:
    using Decorator::Decorator;
    QString operation() const override;
};

#endif // FORMULADECORATOR_H
