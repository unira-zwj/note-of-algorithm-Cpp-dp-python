/*
 * @lc app=leetcode.cn id=1248 lang=cpp
 *
 * [1248] 统计「优美子数组」
 */

// @lc code=start
#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        // 前缀和
        vector<int> s(nums.size()+1);
        for (int i = 0; i < nums.size(); i++){
            s[i+1] = s[i] + nums[i] % 2;
        }

        // 计数
        vector<int> count(s.size());
        for (int i = 0; i < nums.size(); i++){
            count[s[i]] += 1;
        }

        // 返回s[j] 等于s[i] - k的count数
        int ans = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] - k >= 0){
                ans += count[s[i] - k];
            }
        }
        return ans;
    }
};
// @lc code=end

