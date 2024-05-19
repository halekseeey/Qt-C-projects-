#ifndef HEXTODECDECORATOR_H
#define HEXTODECDECORATOR_H

#include "Decorator.h"

class HexToDecDecorator : public Decorator {
public:
    using Decorator::Decorator;
    QString operation() const override;
};

#endif // HEXTODECDECORATOR_H
