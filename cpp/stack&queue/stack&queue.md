## 栈和队列


### 1. 基本问题

#### 1.1 stack和queue是容器吗
stack相当于一种数据结构，不提供set或者map那样的对应迭代器。  
所以是container adapter，而不是container。

#### 1.2 stack和queue的实现
栈用vector list deque等都可以实现， 提供push pop top
默认使用deque


### 题目

225 队列实现栈  

232 栈实现队列  

347 前K个高频元素

优先级队列： 对外接口暴露为一个队列，内部依照权值进行排序。default利用max-heap完成对元素的排序。

heap是一个完全二叉树，树中每个节点的值都不小于或者不大于左右节点的值。root大于左右就是大顶堆max-heap，反之小顶堆。

239 滑动窗口最大值

实现一个单调队列，维护里面的最大值作为弹出的值.  
单调队列： 队列里面保持单调，但是可以双端弹出和push

150 逆波兰表达式求值







