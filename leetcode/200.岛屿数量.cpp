/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
/*
* 错因：函数变量的声明和传递要注意
*       全局变量的声明
* 熟悉：岛屿类的搜索
*/

class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid);
    int numIslands(vector<vector<char>>& grid);

private:
    vector<vector<bool>> visited;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    int m;
    int n;
};


void Solution::dfs(int x, int y, vector<vector<char>>& grid){
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y
         + dy[i];
        // 任何时候访问数组前，判断合法性
        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        if (grid[nx][ny] == '1' && !visited[nx][ny]) {
            dfs(nx, ny, grid);
        }
    }
}

int Solution::numIslands(vector<vector<char>>& grid){
    m = grid.size();
    n = grid[0].size();
    int ans = 0;
    visited = vector<vector<bool>>(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] == '1' && !visited[i][j]){
                dfs(i, j, grid);
                ans ++;
            }
        }
    }
    return ans;
}
// @lc code=end

