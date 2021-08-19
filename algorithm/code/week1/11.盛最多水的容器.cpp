/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
/*
双指针逼近
ans暂存短边*(r-l)
短边抛弃递归
再求面积与ans比取max
*/
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        int h = 0;
        for (int l = 0; l < r; l++){
            h = min(height[l], height[r]);
            ans = max((r - l) * h, ans);
            while (height[r] < height[l]){
                r--;
                h = min(height[l], height[r]);
                ans = max((r - l) * h, ans);
            }
        }
        return ans;
    }
};
// @lc code=end

