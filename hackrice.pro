QT = core gui

greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets

INCLUDEPATH += C:/boost/boost_1_74_0/
LIBS += "-LC:/boost/boost_1_74_0/stage/lib/"

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    appointment.cpp \
    schedule_table.cpp \
    schedule_tabs.cpp \
    update_form.cpp \
    worker.cpp \
    schedule.cpp \
    doctor.cpp \
    nurse.cpp \
    update.cpp

FORMS += \
    mainwindow.ui \
    schedule_table.ui \
    schedule_tabs.ui \
    update_form.ui

HEADERS += \
    mainwindow.h \
    appointment.h \
    schedule_table.h \
    schedule_tabs.h \
    update_form.h \
    worker.h \
    schedule.h \
    doctor.h \
    nurse.h \
    update.h

RESOURCES += \
    HRX_LOGO.png
