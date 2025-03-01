/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

#include "leetcode.h"

// @lc code=start
class MyQueue {
public:
    /*
    2个栈分别用于入栈和出栈，出栈为空时才去把入栈倒入出栈。
    */
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if (out.empty()) in_to_out();

        int ret = out.top();
        out.pop();
        return ret;
    }
    
    int peek() {
        if (out.empty()) in_to_out();

        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }

private:
    stack<int> in;
    stack<int> out;

    void in_to_out() {
        while (!in.empty()) {
            out.push(in.top());
            in.pop();
        }
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

