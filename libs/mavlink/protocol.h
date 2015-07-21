#ifndef  MAVLINK_CPP_PROTOCOL_H
#define  MAVLINK_CPP_PROTOCOL_H

#include "string.h"

/*
   If you want MAVLink on a system that is native big-endian,
   you need to define NATIVE_BIG_ENDIAN
*/
namespace mavlink
{
  #ifdef NATIVE_BIG_ENDIAN
    const bool NEED_BYTE_SWAP = mavlink::PROTOCOL_USE_LITTLE_ENDIAN;
  #else
    const bool NEED_BYTE_SWAP = !mavlink::PROTOCOL_USE_LITTLE_ENDIAN;
  #endif

  /* the sequence number of the system.
     do NOT use _sequenceNumber directly to craft a message.
     use sequenceNumber() instead, which guarantee you that the variable is incremented at each call
   */
  uint8_t volatile _sequenceNumber = 0;
  inline uint8_t sequenceNumber(){return _sequenceNumber++;}
}

#endif // _MAVLINK_PROTOCOL_H_
