#ifndef MAVLINK_MSG_REQUEST_RATA_STREAM_H
#define MAVLINK_MSG_REQUEST_RATA_STREAM_H

#include "./mavlink.h"

class MAVLink_msg_request_rata_stream : public MAVLinkMessage
{
public:
  MAVLink_msg_request_rata_stream(uint8_t systemID, uint8_t componentID, uint8_t sequenceNumber,
                                  uint8_t target_system, uint8_t target_component,
                                  uint8_t req_stream_id, uint16_t req_message_rate,
                                  uint8_t start_stop);

  uint16_t get_req_message_rate() const;
  uint8_t get_target_system() const;
  uint8_t get_target_component() const;
  uint8_t get_req_stream_id() const;
  uint8_t get_start_stop() const;
};

#endif // MAVLINK_MSG_REQUEST_RATA_STREAM_H
