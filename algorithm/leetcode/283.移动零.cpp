/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start

// #include<vector.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int back = 0;
        for (int front = 0; front < nums.size(); front++){
            if (nums[front] != 0){
                swap(nums[front], nums[back]);
                back++;
            }
        }
    }
};
// @lc code=end

