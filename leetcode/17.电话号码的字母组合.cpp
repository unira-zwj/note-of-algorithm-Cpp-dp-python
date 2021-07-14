/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start

/*
* 对23456789建立hash map
* 将第一个字符的hash value挨个存入ans
    遍历每个ans，将第二个字符串的hash value添加至ans后
* ans 长度等于digits长度截止

错因： 没有还原combination
*/
#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    unordered_map<char, string> creatMap();
    void findCombination(int index, string digits);
    vector<string> letterCombinations(string digits);

private:
    unordered_map<char, string> cMap;
    int digitsLen;
    string combination;
    vector<string> combinations;
};

unordered_map<char, string> Solution::creatMap(){
    cMap['2'] = "abc";
    cMap['3'] = "def";
    cMap['4'] = "ghi";
    cMap['5'] = "jkl";
    cMap['6'] = "mno";
    cMap['7'] = "pqrs";
    cMap['8'] = "tuv";
    cMap['9'] = "wxyz";
    return cMap;
}

void Solution::findCombination(int index, string digits){
    digitsLen = digits.size();
    if (index == digitsLen) {
        combinations.push_back(combination);
    }else{
        for (auto& s : cMap[digits[index]]){
            combination.push_back(s);
            findCombination(index + 1, digits);
            combination.pop_back(); // 注意还原
        }
    }
}

vector<string> Solution::letterCombinations(string digits){
    if (digits.size() == 0) return {};
    creatMap();
    findCombination(0, digits);
    return combinations;
}
// @lc code=end

