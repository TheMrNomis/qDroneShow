#-------------------------------------------------
#
# Project created by QtCreator 2015-06-05T16:14:52
#
#-------------------------------------------------

QT       += core \
            gui \
            qml \
            serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qDroneShow
TEMPLATE = app

INCLUDEPATH += include/ \
    libs/

SOURCES += src/main.cpp \
    src/mainwindow.cpp \
    libs/UAV/uav.cpp \
    libs/UAV/link.cpp \
    formationwidget.cpp \
    libs/UAV/UAS.cpp \
    libs/MAVLink/common/mavlink_msg_cmd.cpp \
    libs/MAVLink/common/mavlink_msg_cmd_ack.cpp \
    libs/MAVLink/common/mavlink_msg_heartbeat.cpp \
    libs/MAVLink/bytebuffer.cpp \
    libs/MAVLink/mavlinkmessage.cpp \
    libs/MAVLink/common/mavlink_msg_set_mode.cpp \
    libs/UAV/seriallink.cpp

HEADERS  += include/mainwindow.h \
    libs/UAV/uav.h \
    libs/UAV/mavlinkmessage.h \
    libs/UAV/link.h \
    libs/UAV/mavlinkheartbeat.h \
    libs/UAV/mavlinkcommand.h \
    libs/UAV/bytebuffer.h \
    libs/UAV/ardupilotmega.h \
    formationwidget.h \
    libs/UAV/UAS.h \
    libs/UAV/UASInterface.h \
    libs/UAV/enums.h \
    libs/UAV/mavlink_msg_cmd_ack.h \
    libs/MAVLink/common/mavlink_msg_cmd.h \
    libs/MAVLink/common/mavlink_msg_cmd_ack.h \
    libs/MAVLink/bytebuffer.h \
    libs/MAVLink/mavlink_enums.h \
    libs/MAVLink/mavlinkmessage.h \
    libs/MAVLink/common/mavlink.h \
    libs/MAVLink/common/mavlink_msg_set_mode.h \
    libs/UAV/seriallink.h

FORMS    += mainwindow.ui \
    formationwidget.ui
