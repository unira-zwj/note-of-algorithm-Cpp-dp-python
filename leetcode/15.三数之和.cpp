/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
/*
//       -1,  0,  1, 2, -1, -4
// 排序   -4, -1, -1, 0,  1,  2
//            i      l   r
//                i  l   r
// 答案  [-1, -1, 2] [-1, 0, 1]
*/
// 离谱离谱！！！去重内外层都要去重！！！
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); 
        for (int i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 第二次循环开始去重！！！
            int r = nums.size() - 1;
            for (int l = i + 1; l < nums.size() ; l++){
                if (l > i + 1 && nums[l] == nums[l - 1]) continue; // 第二次循环开始去重！！！
                while (l < r && nums[l] + nums[r] > -nums[i]) r--; // l < r!!!
                if (l < r && nums[l] + nums[r] == -nums[i]){ // l < r!!!
                    ans.push_back({nums[i], nums[l], nums[r]});
                }
            }
        }
        return ans;
    }
};
// @lc code=end

