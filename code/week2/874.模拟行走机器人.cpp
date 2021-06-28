/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 */

// @lc code=start
/* 
* leetcode不支持对set使用pair，拼凑新哈希
* 方向数组技巧
*/
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> blocks;
        for (auto& obstacle : obstacles){
            blocks.insert(calhash(obstacle[0], obstacle[1]));
        }

        // 方向组技巧北东南西
        int x=0,  y = 0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int dir = 0;
        int ans = 0;
        for (auto& command : commands){
            if (command > 0){
                // 一步一步走，检测障碍物
                for (int i = 0; i < command; i++){
                    // 先测试下一步会不会有障碍物
                    int tryx = x + dx[dir];
                    int tryy = y + dy[dir];
                    if (blocks.find(calhash(tryx, tryy)) != blocks.end()){
                        break;
                    }
                    // 没有障碍物就走一步
                    x += dx[dir];
                    y += dy[dir];
                    ans = max(ans, x * x + y * y);
                }

            }else if (command == -1){
                // 右转，坐标转换
                dir = (dir + 1) % 4;
            }else if (command == -2){
                // 左转，坐标转换
                dir = (dir - 1 + 4) % 4;
            }
        }
        return ans;
    }

private:
    string calhash(int x, int y){
        return to_string(x) + "," + to_string(y);
    }

};
// @lc code=end




