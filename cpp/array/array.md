# 数组  

## 1. 数组  

数组元素靠覆盖。  
C++中数组的内存地址是连续的[0][0]->[0][1]->[1][0]->[1][1]  
比如int 每个地址之间就差4个byte  

## 2. 二分查找  

### a. 左闭右开

```cpp
while (left < right)
if (nums[middle] > target) => right = middle;
if (nums[middle] < target) => left = middle + 1;
```

### b. 左闭右闭  

```cpp
while (left <= right)
if (nums[middle] > target) => right = middle - 1;
if (nums[middle] < target) => left = middle + 1;
```

### c. 例题

No.704(E) No.35(E) No.34(M)

## 3. 移除元素

不使用额外的空间 使用O(1)的算法。
由于array本身是在内存里顺序排列的 我们移除实际上是用邻近的元素覆盖  
这里可以选择使用双指针法  

例题： No.27, No.977


