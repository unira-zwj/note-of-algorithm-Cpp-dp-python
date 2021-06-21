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
    int aa = 1;
    cout << "aa" << aa % 2 << endl;
    return 0;
}
