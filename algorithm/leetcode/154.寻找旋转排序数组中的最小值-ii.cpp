/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
/*
 * 分为两个数组，左边的是单调递增，右边单调递减
 * 分三种情况
 *  1. mid < right 说明mid在右边的单调数组
 *  2. mid > right 说明mid在左边数组
 *  3. mid == right 巧妙的right ++
 */
class Solution {

public:
    int findMin(vector<int>& nums);
};

int Solution::findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] < nums[right]) {
            right = mid;
        }
        else if (nums[mid] > nums[right]) {
            left = mid + 1;
        }
        else {
            right --;
        }
    }
    return nums[left];
}
// @lc code=end

