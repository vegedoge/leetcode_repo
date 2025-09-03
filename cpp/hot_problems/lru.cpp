#include <iostream>
#include <unordered_map>
#include <list>

class LRUCache {
public:
  LRUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    if (!cache_map_.count(key)) {
      return -1;
    }

    // list的迭代器
    auto it = cache_map_[key];
    int val = it->second;

    cache_list_.erase(it);
    cache_list_.push_front({key, val});

    cache_map_[key] = cache_list_.begin();
  }

  int put(int key, int value) {
    if (cache_map_.find(key) != cache_map_) {
      auto it = cache_map_[key];
      cache_list_.erase(it);
    } else if (cache_map_.size() >= capacity) {
      int lru_key = cache_list_.back().first;

      cache_map_.erase(lru_key);
      cache_list_.pop_back();
    }

    cache_list_.push_front({key, value});
    cache_map[key] = cache_list_.begin();
  }

private:
  int capacity;
  using cache_list = std::list<std::pair<int, int>>;
  cache_list cache_list_;
  std::unordered_map<int, cache_list::iterator> cache_map_;
};