/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start

#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int nums = s.size();
        stack<char> m;
        if (s[0] == ')' || s[0] == '}' || s[0] == ']') return false;
        for (int i = 0; i < nums; i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                m.push(s[i]);
            }
            else{
                if (m.empty()) return false;
                else if (s[i] == ')'){
                    if (m.top() != '('){
                        return false;
                    } 
                }
                else if (s[i] == ']'){
                    if (m.top() != '['){
                        return false;
                    } 
                }
                else if (s[i] == '}'){
                    if (m.top() != '{'){
                        return false;
                    } 
                }
                m.pop();
            }
        }
        return m.empty();
    }
};
// @lc code=end

/*
注意if 的嵌套关系，还有pop的位置
注意判断push->pop的空栈情况
*/