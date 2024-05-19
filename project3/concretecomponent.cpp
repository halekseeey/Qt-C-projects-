#include "ConcreteComponent.h"
#include <QFile>
#include <QTextStream>

ConcreteComponent::ConcreteComponent(const QString &filePath) : filePath(filePath) {}

QString ConcreteComponent::operation() const {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return "Error opening file";

    QTextStream in(&file);
    return in.readAll();
}

QString ConcreteComponent::getFilePath() const {
    return filePath;
}
