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

