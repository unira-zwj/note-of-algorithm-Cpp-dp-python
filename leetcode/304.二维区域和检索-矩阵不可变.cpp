/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start

#include<vector>
#include<iostream>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> s;
    NumMatrix(vector<vector<int>>& matrix) {
        s.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int x = 0; x < matrix.size(); x++){
            for (int y = 0; y < matrix[0].size(); y++){
                s[x + 1][y + 1] = s[x][y + 1] + s[x + 1][y] - s[x][y] + matrix[x][y]; 
            }
        }
    }   

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; row2++; col1++; col2++; // 上面求前缀和的时候s是从1开始索引
        return s[row2][col2] - s[row2][col1 - 1] - s[row1 - 1][col2] + s[row1 - 1][col1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

