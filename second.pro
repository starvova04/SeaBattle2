QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    battlefield.cpp \
    cellbtn.cpp \
    droparea.cpp \
    gameloopthread.cpp \
    gamepage.cpp \
    main.cpp \
    mainwindow.cpp \
    placeshipsform.cpp \
    shipform.cpp \
    shippcellbtn.cpp \
    shipsstockform.cpp \
    startpage.cpp

HEADERS += \
    battlefield.h \
    cellbtn.h \
    droparea.h \
    gameloopthread.h \
    gamepage.h \
    mainwindow.h \
    placeshipsform.h \
    shipform.h \
    shippcellbtn.h \
    shipsstockform.h \
    startpage.h

FORMS += \
    battlefield.ui \
    droparea.ui \
    gamepage.ui \
    mainwindow.ui \
    placeshipsform.ui \
    shipform.ui \
    shipsstockform.ui \
    startpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
