#ifndef COMPONENT_H
#define COMPONENT_H

#include <QString>

class Component {
public:
    virtual ~Component() {}
    virtual QString operation() const = 0;
};

#endif // COMPONENT_H
