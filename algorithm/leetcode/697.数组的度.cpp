/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
/* 
扫描找出频次最大的数
*/
public:
    int findShortestSubArray(vector<int>& nums) {
        int len = maxnum(nums);


        return ;
    }
private:
    int ans = 0;
    int maxnum(vector<int>& nums){
        unordered_map<int, int> count;
        for (auto& num : nums){
            count[num] += 1;
            ans = max(ans, count[num]);
        }
        return ans;
    }
};
// @lc code=end

