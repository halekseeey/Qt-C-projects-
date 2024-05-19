/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QListView *listView;
    QHBoxLayout *addLayout;
    QLineEdit *keyLineEdit;
    QLineEdit *valueLineEdit;
    QPushButton *addButton;
    QHBoxLayout *removeLayout;
    QLineEdit *removeKeyLineEdit;
    QPushButton *removeButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        listView = new QListView(centralwidget);
        listView->setObjectName("listView");

        verticalLayout->addWidget(listView);

        addLayout = new QHBoxLayout();
        addLayout->setObjectName("addLayout");
        keyLineEdit = new QLineEdit(centralwidget);
        keyLineEdit->setObjectName("keyLineEdit");

        addLayout->addWidget(keyLineEdit);

        valueLineEdit = new QLineEdit(centralwidget);
        valueLineEdit->setObjectName("valueLineEdit");

        addLayout->addWidget(valueLineEdit);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");

        addLayout->addWidget(addButton);


        verticalLayout->addLayout(addLayout);

        removeLayout = new QHBoxLayout();
        removeLayout->setObjectName("removeLayout");
        removeKeyLineEdit = new QLineEdit(centralwidget);
        removeKeyLineEdit->setObjectName("removeKeyLineEdit");

        removeLayout->addWidget(removeKeyLineEdit);

        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName("removeButton");

        removeLayout->addWidget(removeButton);


        verticalLayout->addLayout(removeLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        keyLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Key", nullptr));
        valueLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        removeKeyLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Key", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
