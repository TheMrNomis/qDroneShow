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
    src/connectivityhandler.cpp \
    libs/mavlink/protocol.cpp

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
    src/connectivityhandler.h \
    libs/mavlink/common/common.h \
    libs/mavlink/common/mavlink.h \
    libs/mavlink/common/mavlink_msg_actuator_control_target.h \
    libs/mavlink/common/mavlink_msg_att_pos_mocap.h \
    libs/mavlink/common/mavlink_msg_attitude.h \
    libs/mavlink/common/mavlink_msg_attitude_quaternion.h \
    libs/mavlink/common/mavlink_msg_attitude_quaternion_cov.h \
    libs/mavlink/common/mavlink_msg_attitude_target.h \
    libs/mavlink/common/mavlink_msg_auth_key.h \
    libs/mavlink/common/mavlink_msg_autopilot_version.h \
    libs/mavlink/common/mavlink_msg_battery_status.h \
    libs/mavlink/common/mavlink_msg_camera_trigger.h \
    libs/mavlink/common/mavlink_msg_change_operator_control.h \
    libs/mavlink/common/mavlink_msg_change_operator_control_ack.h \
    libs/mavlink/common/mavlink_msg_command_ack.h \
    libs/mavlink/common/mavlink_msg_command_int.h \
    libs/mavlink/common/mavlink_msg_command_long.h \
    libs/mavlink/common/mavlink_msg_data_stream.h \
    libs/mavlink/common/mavlink_msg_data_transmission_handshake.h \
    libs/mavlink/common/mavlink_msg_debug.h \
    libs/mavlink/common/mavlink_msg_debug_vect.h \
    libs/mavlink/common/mavlink_msg_distance_sensor.h \
    libs/mavlink/common/mavlink_msg_encapsulated_data.h \
    libs/mavlink/common/mavlink_msg_file_transfer_protocol.h \
    libs/mavlink/common/mavlink_msg_global_position_int.h \
    libs/mavlink/common/mavlink_msg_global_position_int_cov.h \
    libs/mavlink/common/mavlink_msg_global_vision_position_estimate.h \
    libs/mavlink/common/mavlink_msg_gps2_raw.h \
    libs/mavlink/common/mavlink_msg_gps2_rtk.h \
    libs/mavlink/common/mavlink_msg_gps_global_origin.h \
    libs/mavlink/common/mavlink_msg_gps_inject_data.h \
    libs/mavlink/common/mavlink_msg_gps_raw_int.h \
    libs/mavlink/common/mavlink_msg_gps_rtk.h \
    libs/mavlink/common/mavlink_msg_gps_status.h \
    libs/mavlink/common/mavlink_msg_heartbeat.h \
    libs/mavlink/common/mavlink_msg_highres_imu.h \
    libs/mavlink/common/mavlink_msg_hil_controls.h \
    libs/mavlink/common/mavlink_msg_hil_gps.h \
    libs/mavlink/common/mavlink_msg_hil_optical_flow.h \
    libs/mavlink/common/mavlink_msg_hil_rc_inputs_raw.h \
    libs/mavlink/common/mavlink_msg_hil_sensor.h \
    libs/mavlink/common/mavlink_msg_hil_state.h \
    libs/mavlink/common/mavlink_msg_hil_state_quaternion.h \
    libs/mavlink/common/mavlink_msg_landing_target.h \
    libs/mavlink/common/mavlink_msg_local_position_ned.h \
    libs/mavlink/common/mavlink_msg_local_position_ned_cov.h \
    libs/mavlink/common/mavlink_msg_local_position_ned_system_global_offset.h \
    libs/mavlink/common/mavlink_msg_log_data.h \
    libs/mavlink/common/mavlink_msg_log_entry.h \
    libs/mavlink/common/mavlink_msg_log_erase.h \
    libs/mavlink/common/mavlink_msg_log_request_data.h \
    libs/mavlink/common/mavlink_msg_log_request_end.h \
    libs/mavlink/common/mavlink_msg_log_request_list.h \
    libs/mavlink/common/mavlink_msg_manual_control.h \
    libs/mavlink/common/mavlink_msg_manual_setpoint.h \
    libs/mavlink/common/mavlink_msg_memory_vect.h \
    libs/mavlink/common/mavlink_msg_mission_ack.h \
    libs/mavlink/common/mavlink_msg_mission_clear_all.h \
    libs/mavlink/common/mavlink_msg_mission_count.h \
    libs/mavlink/common/mavlink_msg_mission_current.h \
    libs/mavlink/common/mavlink_msg_mission_item.h \
    libs/mavlink/common/mavlink_msg_mission_item_int.h \
    libs/mavlink/common/mavlink_msg_mission_item_reached.h \
    libs/mavlink/common/mavlink_msg_mission_request.h \
    libs/mavlink/common/mavlink_msg_mission_request_list.h \
    libs/mavlink/common/mavlink_msg_mission_request_partial_list.h \
    libs/mavlink/common/mavlink_msg_mission_set_current.h \
    libs/mavlink/common/mavlink_msg_mission_write_partial_list.h \
    libs/mavlink/common/mavlink_msg_named_value_float.h \
    libs/mavlink/common/mavlink_msg_named_value_int.h \
    libs/mavlink/common/mavlink_msg_nav_controller_output.h \
    libs/mavlink/common/mavlink_msg_optical_flow.h \
    libs/mavlink/common/mavlink_msg_optical_flow_rad.h \
    libs/mavlink/common/mavlink_msg_param_map_rc.h \
    libs/mavlink/common/mavlink_msg_param_request_list.h \
    libs/mavlink/common/mavlink_msg_param_request_read.h \
    libs/mavlink/common/mavlink_msg_param_set.h \
    libs/mavlink/common/mavlink_msg_param_value.h \
    libs/mavlink/common/mavlink_msg_ping.h \
    libs/mavlink/common/mavlink_msg_position_target_global_int.h \
    libs/mavlink/common/mavlink_msg_position_target_local_ned.h \
    libs/mavlink/common/mavlink_msg_power_status.h \
    libs/mavlink/common/mavlink_msg_radio_status.h \
    libs/mavlink/common/mavlink_msg_raw_imu.h \
    libs/mavlink/common/mavlink_msg_raw_pressure.h \
    libs/mavlink/common/mavlink_msg_rc_channels.h \
    libs/mavlink/common/mavlink_msg_rc_channels_override.h \
    libs/mavlink/common/mavlink_msg_rc_channels_raw.h \
    libs/mavlink/common/mavlink_msg_rc_channels_scaled.h \
    libs/mavlink/common/mavlink_msg_request_data_stream.h \
    libs/mavlink/common/mavlink_msg_safety_allowed_area.h \
    libs/mavlink/common/mavlink_msg_safety_set_allowed_area.h \
    libs/mavlink/common/mavlink_msg_scaled_imu.h \
    libs/mavlink/common/mavlink_msg_scaled_imu2.h \
    libs/mavlink/common/mavlink_msg_scaled_imu3.h \
    libs/mavlink/common/mavlink_msg_scaled_pressure.h \
    libs/mavlink/common/mavlink_msg_scaled_pressure2.h \
    libs/mavlink/common/mavlink_msg_serial_control.h \
    libs/mavlink/common/mavlink_msg_servo_output_raw.h \
    libs/mavlink/common/mavlink_msg_set_actuator_control_target.h \
    libs/mavlink/common/mavlink_msg_set_attitude_target.h \
    libs/mavlink/common/mavlink_msg_set_gps_global_origin.h \
    libs/mavlink/common/mavlink_msg_set_mode.h \
    libs/mavlink/common/mavlink_msg_set_position_target_global_int.h \
    libs/mavlink/common/mavlink_msg_set_position_target_local_ned.h \
    libs/mavlink/common/mavlink_msg_sim_state.h \
    libs/mavlink/common/mavlink_msg_statustext.h \
    libs/mavlink/common/mavlink_msg_sys_status.h \
    libs/mavlink/common/mavlink_msg_system_time.h \
    libs/mavlink/common/mavlink_msg_terrain_check.h \
    libs/mavlink/common/mavlink_msg_terrain_data.h \
    libs/mavlink/common/mavlink_msg_terrain_report.h \
    libs/mavlink/common/mavlink_msg_terrain_request.h \
    libs/mavlink/common/mavlink_msg_timesync.h \
    libs/mavlink/common/mavlink_msg_v2_extension.h \
    libs/mavlink/common/mavlink_msg_vfr_hud.h \
    libs/mavlink/common/mavlink_msg_vibration.h \
    libs/mavlink/common/mavlink_msg_vicon_position_estimate.h \
    libs/mavlink/common/mavlink_msg_vision_position_estimate.h \
    libs/mavlink/common/mavlink_msg_vision_speed_estimate.h \
    libs/mavlink/common/version.h \
    libs/mavlink/bytebuffer.h \
    libs/mavlink/message.h \
    libs/mavlink/protocol.h

RESOURCES += \
    icons.qrc
