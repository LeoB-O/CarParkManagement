#-------------------------------------------------
#
# Project created by QtCreator 2017-12-30T14:17:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CarParkManagement
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        carparkmanagement.cpp \
    carenter.cpp \
    employee.cpp \
    searchcar.cpp \
    vehicle.cpp \
    parkplace.cpp \
    staff.cpp \
    management.cpp \
    otherfun.cpp \
    carleave.cpp

HEADERS += \
        carparkmanagement.h \
    carenter.h \
    employee.h \
    searchcar.h \
    vehicle.h \
    parkplace.h \
    staff.h \
    management.h \
    otherfun.h \
    carleave.h

FORMS += \
        carparkmanagement.ui \
    carenter.ui \
    employee.ui \
    searchcar.ui \
    carleave.ui

INCLUDEPATH += D:\mysql-5.7.20-win32\include

LIBS += -LD:\User\Documents\QtProjects\CarParkManagement\ -llibmysql
