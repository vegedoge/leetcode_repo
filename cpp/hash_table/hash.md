# Hash表

## 1. 概念

### 1.1
用Hash函数把元素映射到Hash表里面，如果元素数量大于HashTable size，
则会出现碰撞。此时有两种办法：  
+ 拉链法 在同一个index上线性排列元素
+ 线性探测法 要修tableSize 大于 dataSize，在冲突索引下方放新元素

### 1.2 常见数据结构

#### 1.2.1 set
std::set, std::multiset, std::unordered_set
红黑树      红黑树         哈希表
有序        有序           无序
不可重复    可重复         不可重复

#### 1.2.2 map
std::map      std::multimap      std::unordered_map
红黑树        红黑树               哈希表
key有序       key有序             key无序
key不可重复   key可重复           key不可重复

常使用于判断元素是否出现过

## 2. 练习题目

### 2.1  有效字母异位词

NO.242  类似题目 No.438  可以维护滑动窗口 同时使用unordered_map

### 2.2 两个数组交集

No.349  No.350

### 2.3 快乐数

No.202

### 2.4 两数之和

No.1

### 2.5 四数相加

No.454

### 2.6 赎金信

No.383  其实对于这种26个字母的 可以用一个数组来代替哈希表

### 2.7 三数之和

用快慢指针加一个循环 注意去重操作 和上一个自己做比较