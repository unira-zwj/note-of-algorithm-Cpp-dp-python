/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

/*
* 遍历回溯
* 建立vector<vector<string>>
* 在第一行1-n位置放Q
    在第二行1-n位置放Q
* 当tempAns.size = n截止
*/
// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n);
    bool conflict(vector<vector<int>> xyQ, int maxIndex);
    vector<vector<string>> Queens(int n, int index);

private:
    vector<string> tempAns;
    vector<vector<string>> ans;
    vector<vector<int>> xyQ;
};

bool Solution::conflict(vector<vector<int>> xyQ, int maxIndex){
    int x = xyQ[maxIndex][0];
    int y = xyQ[maxIndex][1];
    if (maxIndex < 1) return true;
    for (int a = 0; a < maxIndex; a++){
        // 比较xyQ[maxIndex] 与 xyQ[i]
        int x1 = xyQ[a][0];
        int y1 = xyQ[a][1];
        if (x == x1 || y == y1) return false;
        if (x+y == x1+y1 && x-y == x1-y1) return false;
    }
    return true;
}

vector<vector<string>> Solution::Queens(int n, int index){
    if (index == n) {
        ans.push_back(tempAns);
    }
    for (int i = 0; i < n; i++){
        string s = string(n, '.');
        s[i] = 'Q';
        vector<int> xy = {index, i};
        xyQ.push_back(xy);
        if (conflict(xyQ, i)) continue;
        tempAns.push_back(s);
        Queens(n, index + 1);
        tempAns.pop_back();
    }
    return ans;
}

vector<vector<string>> Solution::solveNQueens(int n){
    return Queens(n, 0);
}
// @lc code=end

