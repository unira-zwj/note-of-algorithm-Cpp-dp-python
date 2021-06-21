/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while ( n > 0 ){
            if ( m > 0 && nums1[m-1] > nums2[n-1]){
                nums1[m+n-1] = nums1[m-1];
                m--;
            }
            else{
            nums1[m+n-1] = nums2[n-1];
            n--;
            }
        }
    }
};
// @lc code=end

