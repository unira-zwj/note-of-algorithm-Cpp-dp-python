/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
/*
学习二元组，sort的使用
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 新建二元组同时存元素和索引
        vector<pair<int, int>> newnums;
        for (int i = 0; i < nums.size(); i++){
            newnums.push_back(make_pair(nums[i], i));
        }
        // 重新排序
        sort(newnums.begin(), newnums.end());

        int l = 0, r = newnums.size() - 1;
        for (l; l < r; l++){
            while (l < r && newnums[l].first + newnums[r].first > target) r--;
            if (newnums[l].first + newnums[r].first == target) break;
        }
        return {newnums[l].second, newnums[r].second};
    }
};

/*
vector<int> Solution::twoSum(vector<int>& nums, int target)
{

}
int main(){
    Solution twoSum;
    twoSum.nums = {1,2,3,4};
    twoSum.target = 3;
}
*/
// @lc code=end

