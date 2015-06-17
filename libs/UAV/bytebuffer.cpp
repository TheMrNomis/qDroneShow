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

#include "bytebuffer.h"

ByteBuffer::ByteBuffer(bool bytesSwap, bool alignedFields):
  m_MAVLINK_NEED_BYTE_SWAP(bytesSwap),
  m_MAVLINK_ALIGNED_FIELDS(alignedFields),
  m_buffer()
{

}

ByteBuffer::ByteBuffer(ByteBuffer const& buffer, bool bytesSwap, bool alignedFields):
  ByteBuffer(bytesSwap, alignedFields)
{
  load(buffer);
}

ByteBuffer::ByteBuffer(const char * data, size_t length, bool bytesSwap, bool alignedFields):
  ByteBuffer(bytesSwap, alignedFields)
{
  for(unsigned int i = 0; i < length; ++i)
    m_buffer.push_back(data[i]);
}

void ByteBuffer::operator =(ByteBuffer const& buffer)
{
  m_buffer.clear();
  load(buffer);
}

void ByteBuffer::operator <<(ByteBuffer const& n)
{
  load(n);
}

void ByteBuffer::operator >>(ByteBuffer &receiptBuffer)
{
  receiptBuffer << m_buffer.front();
  m_buffer.pop_front();
}

char const ByteBuffer::operator [](unsigned int i) const
{
  return m_buffer[i];
}

char const ByteBuffer::operator [](int i) const
{
  return m_buffer[i];
}

size_t ByteBuffer::size() const {return m_buffer.size();}
ByteBuffer::operator char*() const
{
  char * buffer = new char[m_buffer.size()];

  int i(0);
  for(auto it = m_buffer.cbegin(); it != m_buffer.cend(); ++it)
    buffer[i++] = *it;

  return buffer;
}

void ByteBuffer::load(ByteBuffer const& buffer)
{
  for(auto it = buffer.m_buffer.cbegin(); it != buffer.m_buffer.cend(); ++it)
    m_buffer.push_back(*it);
}

//iterator functions
ByteBuffer::const_iterator ByteBuffer::cbegin() const
{
  return ByteBuffer::const_iterator(m_buffer.cbegin());
}

ByteBuffer::const_iterator ByteBuffer::cend() const
{
  return ByteBuffer::const_iterator(m_buffer.cend());
}

ByteBuffer::const_iterator& ByteBuffer::const_iterator::operator ++()
{
  ++m_it;
  return *this;
}

ByteBuffer::const_iterator  ByteBuffer::const_iterator::operator ++(int)
{
  ByteBuffer::const_iterator tmp(*this);
  operator ++();
  return tmp;
}

ByteBuffer::const_iterator& ByteBuffer::const_iterator::operator --()
{
  --m_it;
  return *this;
}

ByteBuffer::const_iterator  ByteBuffer::const_iterator::operator --(int)
{
  ByteBuffer::const_iterator tmp(*this);
  operator --();
  return tmp;
}

char const ByteBuffer::const_iterator::operator *() const
{
  return *m_it;
}

bool ByteBuffer::const_iterator::operator ==(const_iterator const& i) const
{
  return m_it == i.m_it;
}

bool ByteBuffer::const_iterator::operator !=(ByteBuffer::const_iterator const& i) const
{
  return !operator ==(i);
}

ByteBuffer::const_iterator::const_iterator(std::deque<char>::const_iterator it):m_it(it){}
ByteBuffer::const_iterator::const_iterator(ByteBuffer::const_iterator const& it):m_it(it.m_it){}

std::ostream& operator <<(std::ostream& out, ByteBuffer const& b)
{
  for(ByteBuffer::const_iterator it = b.cbegin(); it != b.cend(); ++it)
    out << "[" << std::bitset<8>(*it) << "]";
  return out;
}

