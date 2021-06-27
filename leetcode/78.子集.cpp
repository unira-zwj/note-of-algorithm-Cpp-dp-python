/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
/*
递推公式：
    nums[i] or continue

终止条件：
    nums[i].size() = 0

*/
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> select;
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int>& nums) {
        pre(nums, 0);
        return ans;
        
    }
private:
    void pre(vector<int>& nums, int index){
        if (index == nums.size()){
            ans.push_back(select);
            return;
        }
        //cout << "index1  " << index << endl;
        pre(nums, index + 1);
        // cout << "index2  " << index << endl;
        select.push_back(nums[index]);
        pre(nums, index + 1);
        // cout << "index3  " << index << endl;
        select.pop_back();
    }
};
// @lc code=end

