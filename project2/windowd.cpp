#include "WindowD.h"
#include <QHBoxLayout>
#include <QRegularExpression>

WindowD::WindowD(Mediator *mediator, QWidget *parent) : QWidget(parent), mediator(mediator) {
    editor = new QTextEdit(this);
    // Настройка компоновки и прочих элементов
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(editor);
    setLayout(layout);
}

QStringList WindowD::getForbiddenWords() const {
    QString text = editor->toPlainText();
    return text.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);

}
