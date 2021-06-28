/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
/*
读题：
长度相同，中间不能有其他字符：滑动窗口长度固定，将s分解为若干个word
不需要考虑顺序：hash
思路：
 - 从枚举位置开始，分解字符串s为一个个word,比较滑动窗口的map和输入的words的map是否相等

substr 的用法
对words建hash map
    - // words的单词到次数的映射
        unordered_map<string, int> word_to_times;
        for (string& word : words)
        {
            word_to_times[word] += 1；
        }
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> map1 = words_to_nums(words);
        int word_nums = words.size(); // 单词数量
        int word_size = words[0].size(); // 每个单词字符数
        int n = word_nums * word_size;  // 总字符数，窗口长度
        vector<int> ans;
        // 设置多个起点
        for (int start = 0; start < word_size; start++){
            // 滑动窗口,比较map
            for (int l = start; l + n <= s.size(); l += word_size){
                vector<string> swords = s_to_words(l, l + n, word_size, s); // 窗口区间字符分解为word
                unordered_map<string, int> map2 = words_to_nums(swords); // 再装进map2
                if (isSame(map1, map2)){
                    ans.push_back(l);
                } 
                cout << "l  " << l << endl;
            }
        }
        return ans;

    }
private:
    // 分解start~next的区间字符串为一个个word
    vector<string> s_to_words(int l, int r, int word_size, string s){
        vector<string> swords = {};
        for (int i = l; i < r; i += word_size){
            swords.push_back(s.substr(i, word_size));
        }
        return swords;
    }

    // 新建words_to_nums和窗口内字符串st_to_mp的map
    unordered_map<string, int> words_to_nums(vector<string> words){
        unordered_map<string, int> map;
        for (auto& word : words){
            map[word]++;
        }
        return map;
    }

    // 比较两个map是否相等
    // map1和map2大小相等，且1里面有的key2全有，且值一样
    bool isSame(unordered_map<string, int> map1, unordered_map<string, int> map2){
        if (map1.size() != map2.size()) return false;
        for (auto& key_value : map1){
            auto& key = key_value.first;
            auto& value = key_value.second;
            if (map2.find(key) == map2.end() || value != map2[key]) return false;
        }
        return true;
    }

    
};
// @lc code=end

