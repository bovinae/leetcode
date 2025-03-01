/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

#include "leetcode.h"

// @lc code=start
class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if (m.empty() || val <= m.top()) m.push(val);
    }
    
    void pop() {
        int val = s.top();
        if (val == m.top()) m.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return m.top();
    }

private:
    stack<int> s;
    stack<int> m;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

