/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start

#include<vector>
#include<iostream>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> s(nums.size() + 1, 0);
        for (int i = 1; i < s.size(); i++){
            s[i] = s[i - 1] + nums[i-1];
        }
        // 前缀和s的窗口，r要和r左边左右的数中的最小值相减。
        vector<int> pre(s.size(), 0); // 前缀最小值
        
        for (int i = 1; i < s.size(); i++){
            pre[i] = min(pre[i - 1], s[i]);
        }
        int ans = -100000;
        for (int i = 1; i < s.size(); i++){
            ans = max(ans, s[i] - pre[i - 1]);
            }
        return ans;  
    }
};
// @lc code=end

