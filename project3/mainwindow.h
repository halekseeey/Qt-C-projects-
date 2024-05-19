#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>
#include "Component.h"
#include "ConcreteComponent.h"

class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onApplyDecorator();
    void onResetDecorators();
    void onReadFile();

private:
    QTextEdit *textEdit;
    QComboBox *comboBox;
    QPushButton *applyButton;
    QPushButton *resetButton;
    QPushButton *readButton;

    Component *component; // Текущий декорированный компонент
    ConcreteComponent *baseComponent; // Исходный компонент без декораций

    void setupUI();
    void setupConnections();
    void updateComponent(Component *newComponent);
};

#endif // MAINWINDOW_H
