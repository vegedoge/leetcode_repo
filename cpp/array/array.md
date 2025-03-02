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

## 3. 移除元素(双指针)

不使用额外的空间 使用O(1)的算法。
由于array本身是在内存里顺序排列的 我们移除实际上是用邻近的元素覆盖  
这里可以选择使用双指针法  
另外，关于std::remove(), std::remove()并不会真的移除元素，而是把被移除的元素覆盖
然后返回指向移除之后元素end()的迭代器。

```cpp
std::vector<int> vec = {1, 2, 3, 4, 5, 2, 3};
auto it = std::remove(vec.begin(), vec.end(), 2);
\\ => {1, 3, 4, 5, 3, _, _}, it->vec[5]
std::erase(it, vec.end());
```

例题： No.27, No.977

## 4. 最小子数组  

寻找一个区间中的子区间，暴力计算就是用两个循环，一个循环子区间的起点，一个循环子区间的终点，然后O(n^2) 遍历。  
但是还可以用滑动窗口，不断调节起点和终点位置。  
用一个循环遍历窗口的终点，一旦当前窗口满足条件，就移动起始指针。最后记录下最小的窗口长度。

例题: No.209, No.76, No. 904

## 5. 螺旋矩阵

画出一个螺旋排列的正方形 注意坚持循环不变的原则（左闭右开或者左开右闭）
直接对矩阵对应位置 按照螺旋来操作

例题： No.59, No.54

## 6. 子序列和

使用前序和
例题： No.53, No.560
