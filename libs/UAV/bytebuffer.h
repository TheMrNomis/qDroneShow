#ifndef BYTEBUFFER_H
#define BYTEBUFFER_H

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

  char const operator [](unsigned int) const;

  class const_iterator
  {
  public:
    ByteBuffer::const_iterator& operator ++();
    ByteBuffer::const_iterator  operator ++(int);
    ByteBuffer::const_iterator& operator --();
    ByteBuffer::const_iterator  operator --(int);
    char const operator *() const;
    bool operator ==(ByteBuffer::const_iterator const& i) const;
    bool operator !=(ByteBuffer::const_iterator const& i) const;
  private:
    const_iterator(std::vector<char>::const_iterator<char> it);
    const_iterator(ByteBuffer::const_iterator const& it);

    std::vector<char>::const_iterator<char> m_it;
  };

  ByteBuffer::const_iterator cbegin();
  ByteBuffer::const_iterator cend();


private:
  void _push_back(const char* t, int length);


  const bool m_MAVLINK_NEED_BYTE_SWAP;
  const bool m_MAVLINK_ALIGNED_FIELDS;

  std::vector<char> m_buffer;
};

#endif // BYTEBUFFER_H
