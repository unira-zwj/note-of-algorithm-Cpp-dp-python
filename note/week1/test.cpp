#include<iostream>
#include<string>
#include<vector>

using namespace std;
/*
int numberOfSubarrays(vector<int>& nums, int k) {
    vector<int> s(nums.size()+1);
    for (int i = 0; i < nums.size(); i++){
        s[i+1] = nums[i] / 2;
    }
    vector<int> count(nums.size()+1);
    for (int i = 0; i < nums.size(); i++){
        count[s[i]] += 1;
    }
    int ans = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] - k >= 0){
            ans += count[s[i] - k];
        }
    }
    return ans;
}*/
int main(){
    vector<vector<int>> matrix; // 输入二维数组 matrix[x][y]
    vector<vector<int>> s(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0)); // 前缀和二维数组
    for (int x = 0; x <= matrix.size(); x++){
        for(int y = 0; y <= matrix[0].size(); y++){
            s[x + 1][y + 1] = s[x][y + 1] + s[x + 1][y] - s[x][y] + matrix[x][y];
        }
    }
}
