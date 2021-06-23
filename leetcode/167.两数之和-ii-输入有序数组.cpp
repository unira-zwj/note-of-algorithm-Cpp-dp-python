/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
/*
双指针
num[l] + num[r] = target
num[l] 增大； num[r]减小；
直到num[l] == num[r]或者num[l] + num[r] = target
注意两头逼近
*/
        int l = 0;
        int r = numbers.size() - 1;
        for (l = 0; l < r; l++){
            while (numbers[l] + numbers[r] > target) r--;
            if (numbers[l] + numbers[r] == target) break;
        }
        return {l + 1, r + 1};
    }
};
// @lc code=end

