/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
// @lc code=start

// 加强vector的操作使用
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--){
            if (digits[i] != 9){
                digits[i]++;
                break;
            }
                digits[i] = 0;
            if (i == 0){
                vector<int> newdigits (digits.size() + 1);
                newdigits[0] = 1;
                return newdigits;
            }
        }
        return digits;
    }
};
// @lc code=end

