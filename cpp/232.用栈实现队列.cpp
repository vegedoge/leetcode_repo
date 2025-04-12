/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include<stack>
using namespace std;
// @lc code=start
class MyQueue {
public:
    stack<int> in_stack;
    stack<int> out_stack;
    MyQueue() {

    }

    void push(int x) {
        in_stack.push(x);
        }
    
    int pop() {
        if (out_stack.empty()){
            while(!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
        int temp = out_stack.top();
        out_stack.pop();
        return temp;
    }

    int peek() {
        int top = this->pop();
        out_stack.push(top);
        return top;
    }

    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

