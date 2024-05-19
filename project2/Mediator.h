#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QString>

// Предварительные объявления классов, чтобы избежать циклических зависимостей
class WindowA;
class WindowB;
class WindowC;
class WindowD;

class Mediator {
public:
    virtual ~Mediator() {}

    // Виртуальные методы для взаимодействия с окнами
    virtual void copyText() = 0;
    virtual void pasteText() = 0;
    virtual void clearText() = 0;
    virtual void checkForbiddenWords(const QString& textBefore, const QString& SelectedText, const QString& TextAfter) = 0;
    virtual void updateClearButtonVisibility(bool textPresent) = 0;
};

#endif // MEDIATOR_H
