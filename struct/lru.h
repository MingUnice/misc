#ifndef __LRU_H__
#define __LRU_H__

#include <unordered_map>
#include <list>

template<class KEY, class VAL>
struct LRU {

  LRU() {}
  LRU(size_t capacity) : capacity_(capacity) {}
  virtual ~LRU() {}

  bool get(KEY key, VAL &val)
  {
    if (map_.count(key) == 0)
      return false;
    auto it = map_[key];
    cache_.splice(cache_.begin(), cache_, it);
    val = it->second;
    return true;
  }

  void put(KEY key, VAL val)
  {
    if (map_.count(key) == 0) {
      if (cache_.size() == capacity_) {
        map_.erase(cache_.back().first);
        cache_.pop_back();
      }
      cache_.emplace_front(key, val);
      map_[key] = cache_.begin();
    } else {
      auto it = map_[key];
      cache_.splice(cache_.begin(), cache_, it);
      it->second = val;
    }
  }

  size_t capacity_ = 0;
  std::list<std::pair<KEY, VAL> > cache_;
  std::unordered_map<KEY, decltype(cache_.begin())> map_;
};


#endif
