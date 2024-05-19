#ifndef WINDOWD_H
#define WINDOWD_H

#include <QWidget>
#include <QTextEdit>
#include "Mediator.h"

class WindowD : public QWidget {
    Q_OBJECT
public:
    explicit WindowD(Mediator *mediator, QWidget *parent = nullptr);
    QStringList getForbiddenWords() const;

private:
    QTextEdit *editor;
    Mediator *mediator;
};

#endif // WINDOWD_H
