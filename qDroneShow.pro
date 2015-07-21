#-------------------------------------------------
#
# Project created by QtCreator 2015-06-05T16:14:52
#
#-------------------------------------------------

QT       += core \
            gui \
            qml \
            serialport

CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qDroneShow
TEMPLATE = app

INCLUDEPATH += include/ \
    libs/

SOURCES += src/main.cpp \
    src/mainwindow.cpp \
    libs/UAV/uav.cpp \
    libs/UAV/link.cpp \
    libs/UAV/seriallink.cpp \
    src/dronelist.cpp \
    src/uavwidget.cpp \
    src/mapwidget.cpp \
    src/aboutwindow.cpp \
    src/connectivityhandler.cpp

HEADERS  += \
    libs/UAV/uav.h \
    libs/UAV/mavlinkmessage.h \
    libs/UAV/link.h \
    libs/UAV/mavlinkheartbeat.h \
    libs/UAV/mavlinkcommand.h \
    libs/UAV/bytebuffer.h \
    libs/UAV/ardupilotmega.h \
    libs/UAV/enums.h \
    libs/UAV/mavlink_msg_cmd_ack.h \
    libs/UAV/seriallink.h \
    src/dronelist.h \
    src/mainwindow.h \
    src/uavwidget.h \
    src/mapwidget.h \
    src/aboutwindow.h \
    src/connectivityhandler.h

RESOURCES += \
    icons.qrc
