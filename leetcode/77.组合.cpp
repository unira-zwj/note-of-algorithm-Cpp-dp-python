/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
/*
string nums[n] = {1, 2, 3 ..... n}
递归
取或不取nums[i]
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        com(n, k, 0);
        return ans;
    }

private:
    vector<int> st;
    void com(int n, int k, int index){
        // st存够数了就返回个ans
        if (st.size() == k){
            ans.push_back(st);
            return;
        }
        // 选的数已经超过K个，剩下的数全选也不够k个
        if (n - index < k - st.size()) return;

        // 取当前位置的值，先存到临时位置，执行下一次迭代然后再释放临时位置
        st.push_back(index + 1);
        com(n, k, index + 1);
        st.pop_back();

        // 不取直接下一步迭代
        com(n, k, index + 1);
    }
};
// @lc code=end

