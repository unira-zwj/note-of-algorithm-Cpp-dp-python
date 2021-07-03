/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
/*
划分为(a)b
a: k-1
b: n-k
边界: n = 0
*/
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {""};
        vector<string> result;
        // 分成两个子问题
        for (int k = 1; k <= n; k++){
            vector<string> result_a = generateParenthesis(k - 1);
            vector<string> result_b = generateParenthesis(n - k);
            // 组合子问题的答案
            for (string& a : result_a){
                for (string& b : result_b){
                    result.push_back("(" + a + ")" + b);
                }
            }
        }
        return result;
        
    }
};
// @lc code=end

