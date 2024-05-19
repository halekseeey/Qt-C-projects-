#ifndef CONCRETEMEDIATOR_H
#define CONCRETEMEDIATOR_H

#include "Mediator.h"
#include <QString>

class WindowA;
class WindowB;
class WindowC;
class WindowD;

class ConcreteMediator : public Mediator {
public:
    ConcreteMediator();

    void copyText() override;
    void pasteText() override;
    void clearText() override;
    void checkForbiddenWords(const QString& textBefore, const QString& SelectedText, const QString& TextAfter) override;
    void updateClearButtonVisibility(bool textPresent) override;

    void setWindowA(WindowA *window);
    void setWindowB(WindowB *window);
    void setWindowC(WindowC *window);
    void setWindowD(WindowD *window);

private:
    WindowA *windowA = nullptr;
    WindowB *windowB = nullptr;
    WindowC *windowC = nullptr;
    WindowD *windowD = nullptr;
    QString clipboard;
};

#endif // CONCRETEMEDIATOR_H
