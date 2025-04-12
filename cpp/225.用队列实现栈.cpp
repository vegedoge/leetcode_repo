/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include <queue>
using namespace std;
// @lc code=start
class MyStack {
public:
    queue<int> que1;
    queue<int> que2;
    MyStack()
    {
    }

    void push(int x) {
        que1.push(x);
    }

    int pop() {
        int size = que1.size();
        size--;
        while(size--) {
            que2.push(que1.front());
            que1.pop();
        }

        int res = que1.front();
        que1.pop();
        que1 = que2;
        while (!que2.empty())
        {
            que2.pop();
        }
        return res;
    }

    int top() {
        int size = que1.size();
        size--;
        while (size--){
            // 将que1 导入que2，但要留下最后一个元素
            que2.push(que1.front());
            que1.pop();
        }

        int result = que1.front(); // 留下的最后一个元素就是要回返的值
        que2.push(que1.front());   // 获取值后将最后一个元素也加入que2中，保持原本的结构不变
        que1.pop();

        que1 = que2; // 再将que2赋值给que1
        while (!que2.empty()){
            // 清空que2
            que2.pop();
        }
        return result;
    }
    
    bool empty() {
        return que1.empty();
        }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

