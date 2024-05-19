QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    concretecomponent.cpp \
    concretedecoratora.cpp \
    concretedecoratorremovedigits.cpp \
    dectohexdecorator.cpp \
    formuladecorator.cpp \
    hextodecdecorator.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Component.h \
    Decorator.h \
    concretecomponent.h \
    concretedecoratora.h \
    concretedecoratorremovedigits.h \
    dectohexdecorator.h \
    formuladecorator.h \
    hextodecdecorator.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
