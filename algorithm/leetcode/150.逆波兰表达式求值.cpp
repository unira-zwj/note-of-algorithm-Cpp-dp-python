/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> nums;
        for (int i = 0; i < tokens.size(); i++)
        //for (string& token : tokens)
        {
            //string& token = tokens[i];
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
            //if (token[0] >= '0' && token[0] <= '9')
            {
                nums.push(stoi(tokens[i]));

            }
            else{
                long long a = nums.top();
                nums.pop();
                long long  b = nums.top();
                nums.pop();
                nums.push(calculat(a, b, tokens[i]));
            }
        }
        return nums.top();
    }
    long long calculat(long long a, long long b, string c){
        if (c == "+") return b + a;
        if (c == "-") return b - a;
        if (c == "*") return b * a;
        if (c == "/") return b / a;
        return 0;
    }
};
// @lc code=end

