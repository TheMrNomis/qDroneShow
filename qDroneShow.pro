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
    libs/MAVLink/common/mavlink_msg_cmd.cpp \
    libs/MAVLink/common/mavlink_msg_cmd_ack.cpp \
    libs/MAVLink/common/mavlink_msg_heartbeat.cpp \
    libs/MAVLink/bytebuffer.cpp \
    libs/MAVLink/mavlinkmessage.cpp \
    libs/MAVLink/common/mavlink_msg_set_mode.cpp \
    libs/UAV/seriallink.cpp \
    libs/MAVLink/common/mavlink_msg_global_position_int.cpp \
    libs/MAVLink/common/mavlink_msg_attitude.cpp \
    libs/MAVLink/common/mavlink_msg_vfr_hud.cpp \
    src/dronelist.cpp \
    src/uavwidget.cpp \
    libs/MAVLink/common/mavlink_msg_sys_status.cpp \
    libs/MAVLink/common/mavlink_msg_request_rata_stream.cpp \
    libs/MAVLink/common/mavlink_msg_statustext.cpp \
    libs/MAVLink/common/mavlink_msg_gps_raw_int.cpp

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
    libs/MAVLink/common/mavlink_msg_cmd.h \
    libs/MAVLink/common/mavlink_msg_cmd_ack.h \
    libs/MAVLink/bytebuffer.h \
    libs/MAVLink/mavlink_enums.h \
    libs/MAVLink/mavlinkmessage.h \
    libs/MAVLink/common/mavlink.h \
    libs/MAVLink/common/mavlink_msg_set_mode.h \
    libs/UAV/seriallink.h \
    libs/MAVLink/common/messagetypes.h \
    libs/MAVLink/common/mavlink_msg_global_position_int.h \
    libs/MAVLink/common/mavlink_msg_attitude.h \
    libs/MAVLink/common/mavlink_msg_vfr_hud.h \
    libs/MAVLink/common/mavlink_msg_heartbeat.h \
    src/dronelist.h \
    src/mainwindow.h \
    src/uavwidget.h \
    libs/MAVLink/common/mavlink_msg_sys_status.h \
    libs/MAVLink/common/messagecrcs.h \
    libs/MAVLink/common/messagelengths.h \
    libs/MAVLink/common/mavlink_msg_request_rata_stream.h \
    libs/MAVLink/common/mavlink_msg_statustext.h \
    libs/MAVLink/common/mavlink_msg_gps_raw_int.h

RESOURCES += \
    icons.qrc
