#include "bytebuffer.h"

ByteBuffer::ByteBuffer(bool bytesSwap, bool alignedFields):
  m_MAVLINK_NEED_BYTE_SWAP(bytesSwap),
  m_MAVLINK_ALIGNED_FIELDS(alignedFields),
  m_buffer()
{

}

void ByteBuffer::operator <<(uint8_t n)
{
  _push_back((const char*) n, sizeof(n));
}

void ByteBuffer::operator <<(int8_t n)
{
  _push_back((const char*) n, sizeof(n));
}

void ByteBuffer::operator <<(uint16_t n)
{
  _push_back((const char*) n, sizeof(n));
}

void ByteBuffer::operator <<(int16_t n)
{
  _push_back((const char*) n, sizeof(n));
}

void ByteBuffer::operator <<(uint32_t n)
{
  _push_back((const char*) n, sizeof(n));
}

void ByteBuffer::operator <<(int32_t n)
{
  _push_back((const char*) n, sizeof(n));
}

void ByteBuffer::operator <<(uint64_t n)
{
  _push_back((const char*) n, sizeof(n));
}

void ByteBuffer::operator <<(int64_t n)
{
  _push_back((const char*) n, sizeof(n));
}

void ByteBuffer::operator <<(char n)
{
  _push_back((const char*) n, sizeof(n));
}

void ByteBuffer::operator <<(float n)
{
  _push_back((const char*) n, sizeof(n));
}

void ByteBuffer::operator <<(double n)
{
  _push_back((const char*) n, sizeof(n));
}

void ByteBuffer::_push_back(const char* t, int length)
{
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



//iterator functions
ByteBuffer::const_iterator ByteBuffer::cbegin()
{
  return ByteBuffer::const_iterator(m_buffer.cbegin());
}

ByteBuffer::const_iterator ByteBuffer::cend()
{
  return ByteBuffer::const_iterator(m_buffer.cend());
}

ByteBuffer::const_iterator& ByteBuffer::const_iterator::operator ++()
{
  ++m_it;
  return &this;
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
  return &this;
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

ByteBuffer::const_iterator::const_iterator(std::vector<char>::const_iterator<char> it):m_it(it){}
ByteBuffer::const_iterator::const_iterator(ByteBuffer::const_iterator const& it):m_it(it){}
