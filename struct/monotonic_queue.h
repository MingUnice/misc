#ifndef __MONOTONIC_QUEUE_H__
#define __MONOTONIC_QUEUE_H__

#include <deque>
#include <functional>

template<class T>
struct MonotonicQueue {
  MonotonicQueue(std::function<bool(const T&, const T&)> compare =
                 std::less<T>()) : compare_(compare) {}
  
  void push(T t)
  {
    while (!queue_.empty() &&
           compare_(queue_.back(), t))
      queue_.pop_back();
    queue_.push_back(t);
  }

  void pop()
  {
    queue_.pop_front();
  }

  T top()
  {
    return queue_.front();
  }
  
  std::deque<T> queue_;
  std::function<bool(const T&, const T&)> compare_;
};


#endif
