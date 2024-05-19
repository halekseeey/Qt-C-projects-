#include "ConcreteMediator.h"
#include "WindowA.h"
#include "WindowB.h"
#include "WindowC.h"
#include "WindowD.h"

ConcreteMediator::ConcreteMediator() {}

void ConcreteMediator::copyText() {

    clipboard = windowA->getText();
    if(windowB) windowB->enablePasteButton(true);
    if(windowC) windowC->enableClearButton(true);
}

void ConcreteMediator::pasteText() {
    if(windowA && !clipboard.isEmpty()) {
        windowA->setText(clipboard);
    }
}

void ConcreteMediator::clearText() {
    clipboard.clear();
    if(windowA) windowA->clearText();
    if(windowC) windowC->enableClearButton(false);
    if(windowB) windowB->enablePasteButton(false);
}

void ConcreteMediator::checkForbiddenWords(const QString& textBefore, const QString& SelectedText, const QString& TextAfter) {
    if(!windowD) return;
    QStringList forbiddenWords = windowD->getForbiddenWords();
    QString modifiedText = SelectedText;
    for(const auto &word : forbiddenWords) {
        modifiedText.replace(word, "***");
    }

    if(windowA) {
        windowA->clearText();
        windowA->setText(textBefore+modifiedText+TextAfter);
    }
}

void ConcreteMediator::updateClearButtonVisibility(bool textPresent) {
    if (windowC) {
        windowC->enableClearButton(textPresent);
    }
}

void ConcreteMediator::setWindowA(WindowA *window) {
    windowA = window;
}

void ConcreteMediator::setWindowB(WindowB *window) {
    windowB = window;
}

void ConcreteMediator::setWindowC(WindowC *window) {
    windowC = window;
}

void ConcreteMediator::setWindowD(WindowD *window) {
    windowD = window;
}
