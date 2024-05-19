// #include "mainwindow.h"
// #include "ui_mainwindow.h"

// MainWindow::MainWindow(QWidget *parent)
//     : QMainWindow(parent)
//     , ui(new Ui::MainWindow)
// {
//     ui->setupUi(this);
// }

// MainWindow::~MainWindow()
// {
//     delete ui;
// }
#include "MainWindow.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), mediator(new ConcreteMediator()) {
    auto *widget = new QWidget();
    auto *layout = new QHBoxLayout(widget);

    windowA = new WindowA(mediator);
    windowB = new WindowB(mediator);
    windowC = new WindowC(mediator);
    windowD = new WindowD(mediator);

    mediator->setWindowA(windowA);
    mediator->setWindowB(windowB);
    mediator->setWindowC(windowC);
    mediator->setWindowD(windowD);

    layout->addWidget(windowA);
    layout->addWidget(windowB);
    layout->addWidget(windowC);
    layout->addWidget(windowD);

    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow() {
    delete windowA;
    delete windowB;
    delete windowC;
    delete windowD;
    delete mediator;
}
