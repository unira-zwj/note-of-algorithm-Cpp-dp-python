/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
/*
思路：重新排序-->分组-->提取到ans
熟悉map的用法
字符串排序
map的插入
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 建立hash map，copy一份str，将其排序后分组
        unordered_map<string, vector<string>> group;
        for (auto& str : strs){
            string copy = str;
            sort(copy.begin(), copy.end());
            group[copy].push_back(str);
            cout << "key  " << copy << "value  " << str << endl;
        }
        //从分组里push_back到ans里
        vector<vector<string>> ans;
        for (auto& an : group){
            ans.push_back(an.second);
        }
        return ans;
    }
};
// @lc code=end

