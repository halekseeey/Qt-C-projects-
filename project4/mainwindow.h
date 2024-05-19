#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QThread>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class RandomNumberGenerator : public QObject
{
    Q_OBJECT

public:
    void generateRandomNumber();

signals:
    void randomNumberGenerated(int number);
};

class SerialPortReader : public QObject
{
    Q_OBJECT

public:
    explicit SerialPortReader(QSerialPort *port, QObject *parent = nullptr);

signals:
    void dataReceived(const QByteArray &data);

public slots:
    void readData();

private:
    QSerialPort *serialPort;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void handleSerialData(const QByteArray &data);
    void handleRandomNumber(int number);

private:
    Ui::MainWindow *ui;
    QSerialPort *serialPort;
    QThread *serialThread;
    QThread *randomThread;
    RandomNumberGenerator *randomGenerator;
    QList<int> container;
    QMap<int, int> countMap; // Контейнер для подсчета количества вхождений
};

#endif // MAINWINDOW_H
