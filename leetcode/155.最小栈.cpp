/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
// @lc code=start

/*
int 需要有返回，void不需要
注意push的判断if (mins.empty() || mins.top() >= val)
*/
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int val) {
        if (mins.empty() || mins.top() >= val){
            mins.push(val);
        }
        s.push(val);

    }
    
    void pop() {
        if (s.top() == mins.top()){
            mins.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
private: stack<int> s;
private: stack<int> mins;
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

