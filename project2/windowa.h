#ifndef WINDOWA_H
#define WINDOWA_H

#include <QWidget>
#include <QTextEdit>
#include "Mediator.h"

class WindowA : public QWidget {
    Q_OBJECT
public:
    explicit WindowA(Mediator *mediator, QWidget *parent = nullptr);
    void setText(const QString &text);
    void clearText();
    void checkSelectedText();
    void onTextChanged();
    QString getText() const;

private:
    QTextEdit *editor;
    Mediator *mediator;
};

#endif // WINDOWA_H
