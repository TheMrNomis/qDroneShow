/*=======================================================================
 * qDroneShow Aerial vehicle show planification
 *
 * Copyright (C) 2015 - Amaury Louarn <amaury.louarn@homnomnom.fr>
 *
 * qDroneShow is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Feneral public license as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * qDroneShow is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without event the implied warranty of
 * MERCHANDABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with qDroneShow. If not, see <http://www.gnu.org/licenses/>
 * ======================================================================*/

#ifndef BYTEBUFFER_H
#define BYTEBUFFER_H

#include <bitset>
#include <iostream>
#include <cstdint>
#include <vector>

class ByteBuffer
{
public:
  ByteBuffer(bool bytesSwap = true, bool alignedFields = true);

  void operator <<(uint8_t);
  void operator <<(int8_t);
  void operator <<(uint16_t);
  void operator <<(int16_t);
  void operator <<(uint32_t);
  void operator <<(int32_t);
  void operator <<(uint64_t);
  void operator <<(int64_t);
  void operator <<(char);
  void operator <<(float);
  void operator <<(double);
  void operator <<(ByteBuffer const&);

  char const operator [](unsigned int) const;
  char const operator [](int) const;

  class const_iterator
  {
    friend class ByteBuffer;
  public:
    const_iterator(std::vector<char>::const_iterator it);
    const_iterator(ByteBuffer::const_iterator const& it);
    ByteBuffer::const_iterator& operator ++();
    ByteBuffer::const_iterator  operator ++(int);
    ByteBuffer::const_iterator& operator --();
    ByteBuffer::const_iterator  operator --(int);
    char const operator *() const;
    bool operator ==(ByteBuffer::const_iterator const& i) const;
    bool operator !=(ByteBuffer::const_iterator const& i) const;
  private:
    std::vector<char>::const_iterator m_it;
  };

  ByteBuffer::const_iterator cbegin() const;
  ByteBuffer::const_iterator cend() const;


private:
  void _push_back(const char* t, int length);

  const bool m_MAVLINK_NEED_BYTE_SWAP;
  const bool m_MAVLINK_ALIGNED_FIELDS;

  std::vector<char> m_buffer;
};

std::ostream& operator <<(std::ostream& out, ByteBuffer const& b);
#endif // BYTEBUFFER_H
