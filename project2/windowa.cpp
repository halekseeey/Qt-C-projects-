#include "WindowA.h"
#include <QHBoxLayout>

WindowA::WindowA(Mediator *mediator, QWidget *parent) : QWidget(parent), mediator(mediator) {
    editor = new QTextEdit(this);
    // Настройка компоновки и прочих элементов
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(editor);
    setLayout(layout);

    connect(editor, &QTextEdit::cursorPositionChanged, this, &WindowA::checkSelectedText);
    connect(editor, &QTextEdit::textChanged, this, &WindowA::onTextChanged);
}

void WindowA::onTextChanged() {
    bool textPresent = !editor->toPlainText().isEmpty();
    if (textPresent) {
        mediator->updateClearButtonVisibility(textPresent);
    }
}

void WindowA::checkSelectedText() {
    QTextCursor cursor = editor->textCursor();
    if (!cursor.hasSelection()) {
        return;
    }
    QString selectedText = cursor.selectedText();

    // Сохраняем позицию начала и конца выделения
    int selectionStart = cursor.selectionStart();
    int selectionEnd = cursor.selectionEnd();

    // Перемещаем курсор в начало документа и выбираем текст от начала до начала выделения
    cursor.setPosition(0);
    cursor.setPosition(selectionStart, QTextCursor::KeepAnchor);
    QString textBefore = cursor.selectedText();

    // Перемещаем курсор в конец выделения и выбираем текст от конца выделения до конца документа
    cursor.setPosition(selectionEnd);
    cursor.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
    QString textAfter = cursor.selectedText();

    // Восстанавливаем исходное положение курсора
    cursor.setPosition(selectionStart);
    editor->setTextCursor(cursor);

    //Пример обработки: печать текста до и после выделения
    // qDebug() << "Before:" << textBefore;
    // qDebug() << "Selected:" << selectedText;
    // qDebug() << "After:" << textAfter;

    mediator->checkForbiddenWords(textBefore, selectedText, textAfter);
}

void WindowA::setText(const QString &text) {
    QString currentText = editor->toPlainText();
    editor->setText(currentText + text);
}

QString WindowA::getText() const {
    return editor->toPlainText();
}

void WindowA::clearText() {
   editor->setText("");
}

