/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& things, int n) {
        vector<int> coEffect(n + 2, 0); // 累加影响数组
        for (auto& thing : things){
            coEffect[thing[0]] += thing[2];
            coEffect[thing[1] + 1] -= thing[2];
        }
        vector<int> ans(n, 0); // 前缀和数组
        ans[0] = coEffect[1];
        for (int i = 1; i < n; i++){
            ans[i] = ans[i-1] + coEffect[i + 1];
        }return ans;
    }
};
// @lc code=end

