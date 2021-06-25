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
/*
建立值到下标的映射
边循环查询，边插入，每次只查询i前面的映射
维护nums[0, i - 1]
防止查询到i本身
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> value_to_index;
        for (int i = 0; i < nums.size(); i++){
            
            // 去value_to_index[]里找有没有等于target - nums[i]的
            // 在C++中，如果查询后不存在会返回尾部
            // 如果!=尾部就是find到了
            if (value_to_index.find(target - nums[i]) != value_to_index.end()){
                return {value_to_index[target - nums[i]], i};
            }
            // 注意是value_to_index，不要写成了value_to_index[i]=nuns[i]，这样是index_to_value
            value_to_index[nums[i]] = i; 
        }
        return {};
    }
};


/* 
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
            while (newnums[l].first + newnums[r].first > target) r--;
            if (newnums[l].first + newnums[r].first == target) break;
        }
        return {newnums[l].second, newnums[r].second};
    }
};
*/

// @lc code=end

