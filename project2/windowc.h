#ifndef WINDOWC_H
#define WINDOWC_H

#include <QWidget>
#include <QPushButton>
#include "Mediator.h"

class WindowC : public QWidget {
    Q_OBJECT
public:
    explicit WindowC(Mediator *mediator, QWidget *parent = nullptr);
    void enableClearButton(bool enable);

private slots:
    void onClearClicked();

private:
    QPushButton *clearButton;
    Mediator *mediator;
};

#endif // WINDOWC_H
