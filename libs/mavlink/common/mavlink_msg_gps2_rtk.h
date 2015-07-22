#ifndef MAVLINK_CPP_MSG_GPS2_RTK_H
#define MAVLINK_CPP_MSG_GPS2_RTK_H

#include "../message.h"

namespace mavlink
{
  namespace msg
  {
    const uint8_t gps2_rtk_id = 128;
    const uint8_t gps2_rtk_length = 35;
    const uint8_t gps2_rtk_crc = 226;

    class gps2_rtk : public mavlink::message
    {
      public:
        gps2_rtk(uint8_t system_id, uint8_t component_id,  uint32_t  time_last_baseline_ms, uint8_t  rtk_receiver_id, uint16_t  wn, uint32_t  tow, uint8_t  rtk_health, uint8_t  rtk_rate, uint8_t  nsats, uint8_t  baseline_coords_type, int32_t  baseline_a_mm, int32_t  baseline_b_mm, int32_t  baseline_c_mm, uint32_t  accuracy, int32_t  iar_num_hypotheses):
          mavlink::message( mavlink::msg::gps2_rtk_length,
                            system_id,
                            component_id,
                            mavlink::msg::gps2_rtk_id)
        {
           m_payload.push_back<uint32_t>(time_last_baseline_ms); ///< Time since boot of last baseline message received in ms.
           m_payload.push_back<uint32_t>(tow); ///< GPS Time of Week of last baseline
           m_payload.push_back<int32_t>(baseline_a_mm); ///< Current baseline in ECEF x or NED north component in mm.
           m_payload.push_back<int32_t>(baseline_b_mm); ///< Current baseline in ECEF y or NED east component in mm.
           m_payload.push_back<int32_t>(baseline_c_mm); ///< Current baseline in ECEF z or NED down component in mm.
           m_payload.push_back<uint32_t>(accuracy); ///< Current estimate of baseline accuracy.
           m_payload.push_back<int32_t>(iar_num_hypotheses); ///< Current number of integer ambiguity hypotheses.
           m_payload.push_back<uint16_t>(wn); ///< GPS Week Number of last baseline
           m_payload.push_back<uint8_t>(rtk_receiver_id); ///< Identification of connected RTK receiver.
           m_payload.push_back<uint8_t>(rtk_health); ///< GPS-specific health report for RTK data.
           m_payload.push_back<uint8_t>(rtk_rate); ///< Rate of baseline messages being received by GPS, in HZ
           m_payload.push_back<uint8_t>(nsats); ///< Current number of sats used for RTK calculation.
           m_payload.push_back<uint8_t>(baseline_coords_type); ///< Coordinate system of baseline. 0 == ECEF, 1 == NED
          
          
        }

      	uint32_t get_time_last_baseline_ms() const
          {return m_payload.get<uint32_t>(0);}
      	uint32_t get_tow() const
          {return m_payload.get<uint32_t>(4);}
      	int32_t get_baseline_a_mm() const
          {return m_payload.get<int32_t>(8);}
      	int32_t get_baseline_b_mm() const
          {return m_payload.get<int32_t>(12);}
      	int32_t get_baseline_c_mm() const
          {return m_payload.get<int32_t>(16);}
      	uint32_t get_accuracy() const
          {return m_payload.get<uint32_t>(20);}
      	int32_t get_iar_num_hypotheses() const
          {return m_payload.get<int32_t>(24);}
      	uint16_t get_wn() const
          {return m_payload.get<uint16_t>(28);}
      	uint8_t get_rtk_receiver_id() const
          {return m_payload.get<uint8_t>(30);}
      	uint8_t get_rtk_health() const
          {return m_payload.get<uint8_t>(31);}
      	uint8_t get_rtk_rate() const
          {return m_payload.get<uint8_t>(32);}
      	uint8_t get_nsats() const
          {return m_payload.get<uint8_t>(33);}
      	uint8_t get_baseline_coords_type() const
          {return m_payload.get<uint8_t>(34);}
      
      
    };
  };
};

#endif //MAVLINK_CPP_MSG_GPS2_RTK_H
    