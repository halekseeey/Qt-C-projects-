#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gradebook.h"
#include <QStackedWidget>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_AddCourse_clicked();

    void on_CloseButton_clicked();

    void on_AddCourseMain_clicked();

    void on_AddStudentMain_clicked();

private:
    Ui::MainWindow *ui;
    Gradebook gradebook;
     QStackedWidget *stackedWidget;
    QStandardItemModel *model;
};
#endif // MAINWINDOW_H
