#ifndef __RING_BUFFER_H__
#define __RING_BUFFER_H__

#include <algorithm>
#include <cmath>

#include <stdlib.h>
#include <string.h>

inline static unsigned int roundup_pow_of_2(unsigned int n)
{
  if (n == 1) return 1;
  return 1UL << (unsigned int)(std::log2(n - 1) + 1);
}

struct RingBuffer {
  RingBuffer() {}
  RingBuffer(size_t n)
  {
    init(n);
  }
  ~RingBuffer()
  {
    if (buffer_)
      free(buffer_);
  }

  void init(size_t n)
  {
    if (n & (n - 1)) {
      n = roundup_pow_of_2(n);
    }
    buffer_ = (unsigned char *)malloc(n);
    size_ = n;
  }

  inline size_t buffer_len()
  {
    return in_ - out_;
  }

  inline size_t in_index()
  {
    return in_ & (size_ - 1);
  }

  inline size_t out_index()
  {
    return out_ & (size_ - 1);
  }

  size_t put(unsigned char *buffer, size_t len)
  {
    size_t l;
    len = std::min(len, size_ - buffer_len());
    l = std::min(len, size_ - in_index());
    memcpy(buffer_ + in_index(), buffer, l);
    memcpy(buffer_, buffer + l, len -l);
    in_ += len;
    return len;
  }

  size_t get(unsigned char *buffer, size_t len)
  {
    size_t l;
    len = std::min(len, buffer_len());
    l = std::min(len, size_ - out_index());
    memcpy(buffer, buffer_ + out_index(), l);
    memcpy(buffer + l, buffer_, len - l);
    out_ += len;
    if (out_ == in_)
      out_ = in_ = 0;
    return len;
  }

  size_t size_ = 0;
  size_t in_ = 0;
  size_t out_ = 0;
  unsigned char *buffer_ = nullptr;
};

#endif
