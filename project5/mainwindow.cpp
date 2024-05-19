#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myitemdelegate.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(new MyTableModel(this))
{
    ui->setupUi(this);

    QMap<int, QString> initialData;
    initialData[1] = "One";
    initialData[2] = "Two";
    initialData[3] = "Three";

    model->setMap(initialData);

    MyItemDelegate *delegate = new MyItemDelegate(this);
    ui->listView->setItemDelegate(delegate);

    ui->listView->setModel(model);


    disconnect(ui->addButton, &QPushButton::clicked, this, nullptr);
    disconnect(ui->removeButton, &QPushButton::clicked, this, nullptr);


    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::on_removeButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    qDebug() << "Add button clicked";
    bool keyOk;
    int key = ui->keyLineEdit->text().toInt(&keyOk);
    QString value = ui->valueLineEdit->text().trimmed();

    qDebug() << "Key:" << key << "Key Valid:" << keyOk;
    qDebug() << "Value:" << value;

    if (keyOk && !value.isEmpty()) {
        QMap<int, QString> map = model->map();
        if (map.contains(key)) {
            QMessageBox::warning(this, "Key exists", "The specified key already exists.");
        } else {
            map.insert(key, value);
            model->setMap(map);
            ui->keyLineEdit->clear();
            ui->valueLineEdit->clear();
        }
    } else {
        QMessageBox::warning(this, "Invalid input", "Please enter a valid key and value.");
    }
}

void MainWindow::on_removeButton_clicked()
{
    qDebug() << "Remove button clicked";
    bool keyOk;
    int key = ui->removeKeyLineEdit->text().toInt(&keyOk);

    qDebug() << "Key to remove:" << key << "Key Valid:" << keyOk;

    if (keyOk) {
        QMap<int, QString> map = model->map();
        if (map.remove(key) > 0) {
            model->setMap(map);
            ui->removeKeyLineEdit->clear();
        } else {
            QMessageBox::warning(this, "Key not found", "The specified key was not found.");
        }
    } else {
        QMessageBox::warning(this, "Invalid input", "Please enter a valid key.");
    }
}
