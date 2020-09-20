QT = core gui

greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets

INCLUDEPATH += C:/boost/boost_1_74_0/
LIBS += "-LC:/boost/boost_1_74_0/stage/lib/"

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    appointment.cpp \
    schedule_table.cpp \
    worker.cpp \
    schedule.cpp \
    doctor.cpp \
    nurse.cpp \
    update.cpp

FORMS += \
    mainwindow.ui \
    schedule_table.ui

HEADERS += \
    mainwindow.h \
    appointment.h \
    schedule_table.h \
    worker.h \
    schedule.h \
    doctor.h \
    nurse.h \
    update.h

RESOURCES += \
    HRX_LOGO.png
