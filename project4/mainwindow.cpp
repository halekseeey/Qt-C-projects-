#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTimer>
#include <cstdlib>
#include <ctime>
#include <QDebug>
#include <QMap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , serialPort(new QSerialPort(this))
    , serialThread(new QThread(this))
    , randomThread(new QThread(this))
    , randomGenerator(new RandomNumberGenerator)
{
    ui->setupUi(this);

    // Настройка порта, установка параметров и обработка ошибок
    serialPort->setPortName("/dev/ttys001");
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    // Создание обработчика для чтения данных из порта
    SerialPortReader *serialReader = new SerialPortReader(serialPort);
    serialReader->moveToThread(serialThread);

    connect(serialThread, &QThread::started, this, [this]() {
        if (!serialPort->open(QIODevice::ReadWrite)) {
            qWarning("Failed to open port");
            QMessageBox::critical(this, "Error", "Failed to open serial port");
            return;
        }
    });
    connect(serialThread, &QThread::finished, serialPort, &QSerialPort::close);
    connect(serialPort, &QSerialPort::readyRead, serialReader, &SerialPortReader::readData);
    connect(serialReader, &SerialPortReader::dataReceived, this, &MainWindow::handleSerialData);

    connect(serialPort, &QSerialPort::errorOccurred, this, [this](QSerialPort::SerialPortError error) {
        if (error == QSerialPort::ResourceError) {
            qCritical() << "Critical Error:" << serialPort->errorString();
            serialPort->close();
            QMessageBox::critical(this, "Critical Error", serialPort->errorString());
        } else {
            qWarning() << "Serial port error:" << serialPort->errorString();
        }
    });

    serialThread->start();

    // Настройка генератора случайных чисел
    randomGenerator->moveToThread(randomThread);
    connect(randomThread, &QThread::started, [this] {
        QTimer *timer = new QTimer;
        connect(timer, &QTimer::timeout, randomGenerator, &RandomNumberGenerator::generateRandomNumber);
        timer->start(2000);
    });
    connect(randomGenerator, &RandomNumberGenerator::randomNumberGenerated, this, &MainWindow::handleRandomNumber);

    randomThread->start();

    // Инициализация генератора случайных чисел
    std::srand(std::time(nullptr));
}

MainWindow::~MainWindow()
{
    serialThread->quit();
    serialThread->wait();
    randomThread->quit();
    randomThread->wait();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    bool ok;
    int number = ui->lineEdit->text().toInt(&ok);
    if (ok) {
        container.append(number);
        ui->textEdit->append("Added by user: " + QString::number(number));
        qDebug() << "Added by user:" << number; // Вывод в консоль

        // Увеличение счетчика числа
        countMap[number]++;
        qDebug() << "Count of number " << number << " is now " << countMap[number];
    }
}

void MainWindow::handleSerialData(const QByteArray &data)
{
    QString dataString = QString::fromUtf8(data); // Преобразование в строку
    bool ok;
    int number = dataString.toInt(&ok); // Преобразование строки в число
    if (ok) {
        container.append(number);
        ui->textEdit->append("Received from serial port: " + QString::number(number));
        qDebug() << "Received from serial port:" << number; // Вывод в консоль

        // Увеличение счетчика числа
        countMap[number]++;
        qDebug() << "Count of number " << number << " is now " << countMap[number];
    } else {
        qDebug() << "Failed to convert data to int:" << dataString; // Вывод в консоль
    }
}

void MainWindow::handleRandomNumber(int number)
{
    ui->textEdit->append("Generated: " + QString::number(number)); // Вывод в текстовое поле
    qDebug() << "Generated:" << number; // Вывод в консоль

    // Увеличение счетчика числа
    countMap[number]++;
    qDebug() << "Count of number " << number << " is now " << countMap[number];

    // Подсчет количества вхождений числа
    int count = countMap.value(number, 0);
    qDebug() << "Count of number " << number << " is " << count;
    if (count > 1) {
        QByteArray message = QByteArray::number(number) + ": " + QByteArray::number(count) + " times";

        qint64 bytesWritten = serialPort->write(message);
        if (bytesWritten == -1) {
            qWarning() << "Failed to write to serial port:" << serialPort->errorString();
        } else if (bytesWritten != message.size()) {
            qWarning() << "Failed to write all data to serial port. Bytes written:" << bytesWritten;
        } else {
            serialPort->flush(); // Очистка буфера

            // Вывод сообщения в консоль и окно сообщения
            qDebug() << "Sending to serial port:" << message; // Вывод в консоль
            QMessageBox::information(this, "Random Number Found", message);
        }
    }
}

SerialPortReader::SerialPortReader(QSerialPort *port, QObject *parent)
    : QObject(parent)
    , serialPort(port)
{}

void SerialPortReader::readData()
{
    emit dataReceived(serialPort->readAll());
}

void RandomNumberGenerator::generateRandomNumber()
{
    int number = std::rand() % 10; // Генерация числа от 0 до 4
    emit randomNumberGenerated(number);
}
