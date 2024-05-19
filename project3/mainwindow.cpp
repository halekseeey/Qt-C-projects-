#include "MainWindow.h"
#include "ConcreteDecoratorA.h"
#include "ConcreteDecoratorRemoveDigits.h"
#include "FormulaDecorator.h"
#include "HexToDecDecorator.h"
#include "DecToHexDecorator.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent), component(nullptr), baseComponent(nullptr) {
    setupUI();
    setupConnections();
}

MainWindow::~MainWindow() {
    delete component;
    delete baseComponent;
}

void MainWindow::setupUI() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *controlsLayout = new QHBoxLayout();
    textEdit = new QTextEdit();
    comboBox = new QComboBox();
    applyButton = new QPushButton("Apply Decorator");
    resetButton = new QPushButton("Reset");
    readButton = new QPushButton("Read File");

    comboBox->addItem("Select Decorator", QVariant(-1));
    comboBox->addItem("Reverse Text", QVariant(0));
    comboBox->addItem("Remove Digits Except 0", QVariant(1));
    comboBox->addItem("Calculate Formulas", QVariant(2));
    comboBox->addItem("Hex to Decimal", QVariant(3));
    comboBox->addItem("Decimal to Hex", QVariant(4));

    controlsLayout->addWidget(comboBox);
    controlsLayout->addWidget(applyButton);
    controlsLayout->addWidget(resetButton);
    controlsLayout->addWidget(readButton);

    mainLayout->addLayout(controlsLayout);
    mainLayout->addWidget(new QLabel("Output:"));
    mainLayout->addWidget(textEdit);
}

void MainWindow::setupConnections() {
    connect(applyButton, &QPushButton::clicked, this, &MainWindow::onApplyDecorator);
    connect(resetButton, &QPushButton::clicked, this, &MainWindow::onResetDecorators);
    connect(readButton, &QPushButton::clicked, this, &MainWindow::onReadFile);
}

void MainWindow::onApplyDecorator() {
    if (!baseComponent) {
        QMessageBox::warning(this, "Warning", "Please load a file first.");
        return;
    }

    int index = comboBox->currentData().toInt();
    Component *newComponent = component ? component : baseComponent;

    switch (index) {
    case 0:
        newComponent = new ConcreteDecoratorA(newComponent);
        break;
    case 1:
        newComponent = new ConcreteDecoratorRemoveDigits(newComponent);
        break;
    case 2:
        newComponent = new FormulaDecorator(newComponent);
        break;
    case 3:
        newComponent = new HexToDecDecorator(newComponent);
        break;
    case 4:
        newComponent = new DecToHexDecorator(newComponent);
        break;
    default:
        QMessageBox::warning(this, "Warning", "Please select a valid decorator.");
        return;
    }

    if (newComponent != component) {
        component = newComponent;
        textEdit->setText(component->operation());
    }
}

void MainWindow::onResetDecorators() {
    if (baseComponent) {
        updateComponent(new ConcreteComponent(*baseComponent)); // Создаем новый компонент на основе исходного
        textEdit->setText(component->operation());
    }
}

void MainWindow::onReadFile() {
    QString filePath = QFileDialog::getOpenFileName(this, "Open Text File", "", "Text Files (*.txt);;All Files (*)");
    if (filePath.isEmpty()) return;
    ConcreteComponent *newComponent = new ConcreteComponent(filePath);
    if (baseComponent != nullptr) {
        delete baseComponent;
    }
    baseComponent = newComponent;
    updateComponent(new ConcreteComponent(filePath));
    textEdit->setText(component->operation());
}

void MainWindow::updateComponent(Component *newComponent) {
    if (component != nullptr && component != baseComponent) {
        delete component; // Удаляем текущий компонент, если он не исходный
    }
    component = newComponent;
}
