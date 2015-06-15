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
#include <deque>

class ByteBuffer
{
public:
  /**
   * @brief creates an empty ByteBuffer
   * @param bytesSwap Should the bytes be swapped? (e.g for changing the endianness)
   */
  ByteBuffer(bool bytesSwap = false, bool alignedFields = true);

  /**
   * @brief add n to the buffer
   */
  template <typename T>
  void operator <<(T n);
  void operator <<(ByteBuffer const&);

  /**
   * @brief puts sizeof(T) bytes onto a variable
   * @param n The variable to put the bytes
   * @warning the first sizeof(T) bytes will be removed from <this> !
   */
  template <typename T>
  void operator >>(T &n);
  /**
   * @brief puts ONE byte from this to receiptBuffer
   * @param receiptBuffer The buffer to put the byte onto
   * @warning the first byte will be removed from <this> !
   */
  void operator >>(ByteBuffer &receiptBuffer);

  char const operator [](unsigned int) const;
  char const operator [](int) const;

  class const_iterator
  {
    friend class ByteBuffer;
  public:
    const_iterator(std::deque<char>::const_iterator it);
    const_iterator(ByteBuffer::const_iterator const& it);
    ByteBuffer::const_iterator& operator ++();
    ByteBuffer::const_iterator  operator ++(int);
    ByteBuffer::const_iterator& operator --();
    ByteBuffer::const_iterator  operator --(int);
    char const operator *() const;
    bool operator ==(ByteBuffer::const_iterator const& i) const;
    bool operator !=(ByteBuffer::const_iterator const& i) const;
  private:
    std::deque<char>::const_iterator m_it;
  };

  ByteBuffer::const_iterator cbegin() const;
  ByteBuffer::const_iterator cend() const;


private:
  const bool m_MAVLINK_NEED_BYTE_SWAP;
  const bool m_MAVLINK_ALIGNED_FIELDS;

  std::deque<char> m_buffer;
};

std::ostream& operator <<(std::ostream& out, ByteBuffer const& b);

template <typename T>
void ByteBuffer::operator <<(T n)
{
  const char * t = (const char*)&n;
  int length = sizeof(n);
  if(m_MAVLINK_NEED_BYTE_SWAP)
  {
    for(int i = length-1; i >= 0; i--)
      m_buffer.push_back(t[i]);
  }
  else if(!m_MAVLINK_ALIGNED_FIELDS)
  {
    for(int i = 0; i < length; i++)
      m_buffer.push_back(t[i]);
  }
  else
  {
    for(int i = 0; i < length; i++)
      m_buffer.push_back(t[i]);
  }
}

template <typename T>
void ByteBuffer::operator >>(T &n)
{
  n = 0;
  for(int i = sizeof(n); i > 0; --i)
  {
    n *= 255;
    n += m_buffer[0];
    m_buffer.pop_front();
  }
}

#endif // BYTEBUFFER_H
