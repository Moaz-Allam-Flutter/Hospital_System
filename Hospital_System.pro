QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminwindow.cpp \
    appointmentform.cpp \
    availableslots.cpp \
    doctorwindow.cpp \
    main.cpp \
    loginwindow.cpp \
    medicalrecord.cpp \
    patientappointments.cpp \
    patientwindow.cpp \
    registerwindow.cpp

HEADERS += \
    adminwindow.h \
    appointmentform.h \
    availableslots.h \
    doctorwindow.h \
    loginwindow.h \
    medicalrecord.h \
    patientappointments.h \
    patientwindow.h \
    registerwindow.h

FORMS += \
    adminwindow.ui \
    appointmentform.ui \
    availableslots.ui \
    doctorwindow.ui \
    loginwindow.ui \
    medicalrecord.ui \
    patientappointments.ui \
    patientwindow.ui \
    registerwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
