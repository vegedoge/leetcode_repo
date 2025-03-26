/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */
#include<list>
#include<unordered_map>
// @lc code=start
class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity){}

    int get(int key) {
        auto it = cache_map.find(key);
        if(it == cache_map.end()) {
            return -1;
        }
        // found match
        // it->second: *unordered_map<int, d_list::iterator>->second
        cache_list.splice(cache_list.begin(), cache_list, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = cache_map.find(key);
        // found and update
        if(it != cache_map.end()) {
            it->second->second = value;
            cache_list.splice(cache_list.begin(), cache_list, it->second);
            return;
        }
        // not found and insert
        cache_list.emplace_front(key, value);
        // update map
        cache_map[key] = cache_list.begin();

        // check capacity and remove from end
        if (cache_list.size() > capacity) {
            int last_key = cache_list.back().first;
            cache_map.erase(last_key);
            cache_list.pop_back();
        }
    }

private:
    int capacity;
    using d_list = std::list<std::pair<int, int>>;
    d_list cache_list;
    std::unordered_map<int, d_list::iterator> cache_map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

