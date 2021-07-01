/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
/*
递归：
不是考虑下一个数选不选了，而是考虑下个位置放什么数
维护：没有用过的数放在当前位置
终止条件：st.size > nums.size()
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> statu(n, 0); // statu是全局变量，之前定义为局部变量去了gg
        
        pre(nums, 0, statu);
        return ans;
    }
private:
    vector<int> st;
    void pre(vector<int> nums, int index, vector<int> statu){
        if (index == nums.size()){
            ans.push_back(st);
            return;
        } 
        for (int i = 0; i < nums.size(); i++){
            if (statu[i] == 0){
                st.push_back(nums[i]);
                statu[i] = 1;
                // cout << statu[0] << endl;
                pre(nums, index + 1, statu);
                statu[i] = 0;
                st.pop_back();
            }
        }
    }
};
// @lc code=end

