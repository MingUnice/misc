#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <atomic>
#include <mutex>

class Singleton {
public:
  static Singleton *GetInstance()
  {
    Singleton *tmp = instance_.load();
    if (tmp == nullptr) {
      std::lock_guard<std::mutex> lk(mutex_);
      tmp = instance_.load();
      if (tmp == nullptr) {
        tmp = new Singleton();
        instance_.store(tmp);
      }
    }
    return instance_;
  }

private:
  Singleton() {};
  static std::atomic<Singleton *> instance_;
  static std::mutex mutex_;
};

#endif
