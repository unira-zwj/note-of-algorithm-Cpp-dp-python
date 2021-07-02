/*
 * @lc app=leetcode.cn id=811 lang=cpp
 *
 * [811] 子域名访问计数
 */

// @lc code=start
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
/*
key->count
key = 

*/
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        unordered_map<string, int> webcount;
        for (auto& cpdomain : cpdomains){
            int index1 = cpdomain.find(' ');
            int index2 = cpdomain.find('.');
            int index3 = cpdomain.rfind('.');
            int nums = stoi(cpdomain.substr(0, index1));
            string web1 = cpdomain.substr(index1 + 1);
            string web2 = cpdomain.substr(index2 + 1);
            webcount[web1] += nums;
            webcount[web2] += nums;
            if (index2 != index3) {
                string web3 = cpdomain.substr(index3 + 1);
                webcount[web3] += nums;
            }
        }
        for (auto& key_val : webcount){
            string key = key_val.first;
            string val = to_string(key_val.second);
            string temp = val + " " + key;
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end

