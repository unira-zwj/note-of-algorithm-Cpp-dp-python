/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int a = 0;
        for ( int i = 0; i < nums.size(); i++){
            if (i == 0 || nums[a-1] != nums[i]){
                nums[a] = nums[i];
                a++;
            }
        }
        return nums.size();
    }
};
// @lc code=end

