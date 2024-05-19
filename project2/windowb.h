#ifndef WINDOWB_H
#define WINDOWB_H

#include <QWidget>
#include <QPushButton>
#include "Mediator.h"

class WindowB : public QWidget {
    Q_OBJECT
public:
    explicit WindowB(Mediator *mediator, QWidget *parent = nullptr);
    void enablePasteButton(bool enable);

private slots:
    void onCopyClicked();
    void onPasteClicked();

private:
    QPushButton *copyButton;
    QPushButton *pasteButton;
    Mediator *mediator;
};

#endif // WINDOWB_H
