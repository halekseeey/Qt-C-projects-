#include "WindowC.h"
#include <QVBoxLayout>

WindowC::WindowC(Mediator *mediator, QWidget *parent) : QWidget(parent), mediator(mediator) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    clearButton = new QPushButton("Clear", this);
    layout->addWidget(clearButton);
    setLayout(layout);

    connect(clearButton, &QPushButton::clicked, this, &WindowC::onClearClicked);

    clearButton->setEnabled(false); // Изначально кнопка Clear выключена
}

void WindowC::enableClearButton(bool enable) {
    clearButton->setEnabled(enable);
}

void WindowC::onClearClicked() {
    mediator->clearText();
}
