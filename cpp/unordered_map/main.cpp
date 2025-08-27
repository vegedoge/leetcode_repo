#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <functional> // std::hash std::equal_to

template<
  typename K,
  typename V,
  typename Hasher = std::hash<K>,
  typename KeyEqual = std::equal_to<K>
>

class MyUnorderedMap {
public:
  using Node = std::pair<const K, V>;

  // 初始化桶数组
  explicit MyUnorderedMap(size_t bucket_count = 10) : buckets_(bucket_count), size_(0) {
    if (bucket_count == 0) {
      buckets_.resize(1);
    }
  }

  // 实现operator[]
  V& operator[](const K& key) {
    // 计算桶的索引
    size_t index = get_bucket_index_(key);
    auto &bucket_list = buckets_[index];

    // 链表里面找key
    for (auto& node: bucket_list) {
      if (KeyEqual()(node.first, key)) {
        return node.second;
      }
    }

    // 没找到 插入
    bucket_list.emplace_front(key, V{});
    size_++;
    return bucket_list.front().second;
  }

  // 不会修改任何成员变量
  size_t size() const {
    return size_;
  }

  bool empty() const {
    return size_ == 0;
  }

private:
  // 计算桶索引
  size_t get_bucket_index_(const K& key) const {
    return Hasher()(key) % bucket_size();
  }

  // 链表存储
  std::vector<std::list<Node>> buckets_;
  size_t size_;
}

int main() {
  MyUnorderedMap<std::string, int> my_map;

  // 测试插入和访问
  my_map["apple"] = 10;
  my_map["banana"] = 20;
  std::cout << "apple: " << my_map["apple"] << std::endl;
  std::cout << "banana: " << my_map["banana"] << std::endl;

  // 测试访问一个不存在的 key，会触发默认插入
  std::cout << "orange: " << my_map["orange"] << std::endl; 
  
  std::cout << "Map size: " << my_map.size() << std::endl; // 应该是 3
  
  // 修改已存在的值
  my_map["apple"] = 15;
  std::cout << "apple (updated): " << my_map["apple"] << std::endl;

  return 0;
}