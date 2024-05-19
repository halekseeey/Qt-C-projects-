#ifndef CONCRETECOMPONENT_H
#define CONCRETECOMPONENT_H

#include "Component.h"

class ConcreteComponent : public Component {
private:
    QString filePath;
public:
    explicit ConcreteComponent(const QString &filePath);
    QString operation() const override;
    QString getFilePath() const;
};

#endif // CONCRETECOMPONENT_H
