#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "WindowA.h"
#include "WindowB.h"
#include "WindowC.h"
#include "WindowD.h"
#include "ConcreteMediator.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    WindowA *windowA;
    WindowB *windowB;
    WindowC *windowC;
    WindowD *windowD;
    ConcreteMediator *mediator;
};

#endif // MAINWINDOW_H
