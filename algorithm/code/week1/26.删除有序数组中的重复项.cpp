/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

/*
 * 这一题一定要注意return的值，只能返回整数型return a。
 */


// @lc code=start

#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int a = 0;
        for ( int i = 0; i < nums.size(); i++){
            if (i == 0 || nums[i -1] != nums[i]){
                nums[a] = nums[i];
                a++;
            }
        }
        return a;
    }
};
// @lc code=end



