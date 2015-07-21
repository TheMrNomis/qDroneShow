#ifndef MAVLINK_CPP_BYTEBUFFER_H
#define MAVLINK_CPP_BYTEBUFFER_H

#include <iostream>
#include <deque>

#include "protocol.h"

namespace mavlink
{
  class ByteBuffer
  {
    public:
      ByteBuffer();
      ByteBuffer(ByteBuffer const& buffer);
      ByteBuffer(const char * data, size_t length);

      void operator = (ByteBuffer const& buffer);

      template <typename T>
      void push_back(T n);
      void push_back(ByteBuffer const& n);

      template <typename T>
      void operator << (T n);
      void operator << (ByteBuffer const& n);

      template <typename T>
      T get(unsigned int n) const;

      uint8_t operator [] (unsigned int i) const;

      void pop_front(unsigned int i = 1);

      size_t size() const;

      operator char*() const;

      class const_iterator
      {
        friend class ByteBuffer;

        public:
          const_iterator(std::deque<uint8_t>::const_iterator it);
          const_iterator(ByteBuffer::const_iterator const& it);

          ByteBuffer::const_iterator& operator ++ ();
          ByteBuffer::const_iterator  operator ++ (int);
          ByteBuffer::const_iterator& operator -- ();
          ByteBuffer::const_iterator  operator -- (int);

          uint8_t operator * () const;
          bool operator == (ByteBuffer::const_iterator const& it) const;
          bool operator != (ByteBuffer::const_iterator const& it) const;

        private:
          std::deque<uint8_t>::const_iterator m_it;
      };

      ByteBuffer::const_iterator cbegin() const;
      ByteBuffer::const_iterator cend() const;

    private:
      std::deque<uint8_t> m_buffer;

      void _load(ByteBuffer const& buffer);
  };
};

//implemenation

mavlink::ByteBuffer::ByteBuffer():
  m_buffer()
{

}

mavlink::ByteBuffer::ByteBuffer(ByteBuffer const& buffer):
  ByteBuffer()
{
  _load(buffer);
}

mavlink::ByteBuffer::ByteBuffer(const char * data, size_t length):
  ByteBuffer()
{
  for(unsigned int i = 0; i < length; ++i)
    m_buffer.push_back(data[i]);
}

void mavlink::ByteBuffer::operator = (ByteBuffer const& buffer)
{
  m_buffer.clear();
  _load(buffer);
}

template <typename T>
void mavlink::ByteBuffer::push_back(T n)
{
  const char * t = (const char *)&n;
  size_t length = sizeof(n);

  if(mavlink::NEED_BYTE_SWAP)
    for(unsigned int i = length - 1; i >= 0; --i)
      m_buffer.push_back(t[i]);
  else
    for(unsigned int i = 0; i < length; ++i)
      m_buffer.push_back(t[i]);
}

void mavlink::ByteBuffer::push_back(ByteBuffer const& n)
{
  _load(n);
}

template <typename T>
void mavlink::ByteBuffer::operator << (T n)
{
  push_back<T>(n);
}

void mavlink::ByteBuffer::operator << (ByteBuffer const& n)
{
  push_back(n);
}

template <typename T>
T mavlink::ByteBuffer::get(unsigned int n) const
{
  const size_t length(sizeof(T));

  char * t = new char[length];
  for(size_t i = 0; i < length; ++i)
  {
    #if MAVLINK_NEED_BYTE_SWAP
      t[i] = m_buffer[n + length-1-i];
    #else
      t[i] = m_buffer[n + i];
    #endif
  }

  T ret(*(reinterpret_cast<T*>(t)));
  delete[] t;

  return ret;
}

uint8_t mavlink::ByteBuffer::operator [] (unsigned int i) const
{
  return m_buffer[i];
}

void mavlink::ByteBuffer::pop_front(unsigned int i)
{
  for(unsigned int j = 0; j < i && m_buffer.size() > 0; ++j)
    m_buffer.pop_front();
}

size_t mavlink::ByteBuffer::size() const
{
  return m_buffer.size();
}

mavlink::ByteBuffer::operator char*() const
{
  char * buf = new char[m_buffer.size()];

  int i(0);
  for(auto it = m_buffer.cbegin(); it != m_buffer.cend(); ++it)
    buf[i++] = *it;

  return buf;
}

void mavlink::ByteBuffer::_load(ByteBuffer const& buffer)
{
  for(auto it = buffer.m_buffer.cbegin(); it != buffer.m_buffer.cend(); ++it)
    m_buffer.push_back(*it);
}

mavlink::ByteBuffer::const_iterator mavlink::ByteBuffer::cbegin() const
{
  return ByteBuffer::const_iterator(m_buffer.cbegin());
}

mavlink::ByteBuffer::const_iterator mavlink::ByteBuffer::cend() const
{
  return ByteBuffer::const_iterator(m_buffer.cend());
}

//const_iterator
mavlink::ByteBuffer::const_iterator::const_iterator(std::deque<uint8_t>::const_iterator it):
  m_it(it){}

mavlink::ByteBuffer::const_iterator::const_iterator(ByteBuffer::const_iterator const& it):
  m_it(it.m_it){}

mavlink::ByteBuffer::const_iterator& mavlink::ByteBuffer::const_iterator::operator ++ ()
{
  ++m_it;
  return *this;
}

mavlink::ByteBuffer::const_iterator  mavlink::ByteBuffer::const_iterator::operator ++ (int)
{
  mavlink::ByteBuffer::const_iterator tmp(*this);
  operator ++();
  return tmp;
}

mavlink::ByteBuffer::const_iterator& mavlink::ByteBuffer::const_iterator::operator -- ()
{
  --m_it;
  return *this;
}

mavlink::ByteBuffer::const_iterator  mavlink::ByteBuffer::const_iterator::operator -- (int)
{
  ByteBuffer::const_iterator tmp(*this);
  operator --();
  return tmp;
}

uint8_t mavlink::ByteBuffer::const_iterator::operator * () const
{
  return *m_it;
}

bool mavlink::ByteBuffer::const_iterator::operator == (ByteBuffer::const_iterator const& it) const
{
  return m_it == it.m_it;
}

bool mavlink::ByteBuffer::const_iterator::operator != (ByteBuffer::const_iterator const& it) const
{
  return !operator == (it);
}

#endif /* MAVLINK_CPP_BYTEBUFFER_H */
