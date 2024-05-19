#include "WindowB.h"
#include <QVBoxLayout>

WindowB::WindowB(Mediator *mediator, QWidget *parent) : QWidget(parent), mediator(mediator) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    copyButton = new QPushButton("Copy", this);
    pasteButton = new QPushButton("Paste", this);
    layout->addWidget(copyButton);
    layout->addWidget(pasteButton);
    setLayout(layout);

    connect(copyButton, &QPushButton::clicked, this, &WindowB::onCopyClicked);
    connect(pasteButton, &QPushButton::clicked, this, &WindowB::onPasteClicked);

    pasteButton->setEnabled(false); // Изначально кнопка Paste выключена
}

void WindowB::enablePasteButton(bool enable) {
    pasteButton->setEnabled(enable);
}

void WindowB::onCopyClicked() {
    mediator->copyText();
}

void WindowB::onPasteClicked() {
    mediator->pasteText();
}
