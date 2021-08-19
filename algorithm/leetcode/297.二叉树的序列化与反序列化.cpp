/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
注意string是一个字符串，应该以添加字符的方式添加
学习split的实现

*/
class Codec {
public:

    // Encodes a tree to a single string.string ans = {};
    
    string serialize(TreeNode* root) {
        string pre = {};
        toString(root, pre);
        pre.pop_back();
        return pre;
    }
    // 前序遍历序列化
    void toString(TreeNode* root, string& pre) {
        if (root == nullptr) {
            pre += "null,";
            return;
        }else{
            pre += to_string(root->val) + ",";
            toString(root->left, pre);
            toString(root->right, pre);
        }
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        queue<string> ans = split(data);
        return toTree(ans);
    }
    // 前序遍历反序列化
    // 先把string串拆分
    queue<string> split(string& str) {
        queue<string> sout;
        if (str.empty()) return sout;
        int pre = 0;
        for (int i = 0; i <= str.size(); ++i) {
            if (i == str.size() || str[i] == ',') {
                sout.emplace(str.substr(pre, i-pre));
                pre = i+1;
            }
        }
        return sout;
    }
    // 前序遍历反序列化
    TreeNode* toTree(queue<string>& sout){
        if (sout.front() == "null"){
            sout.pop();
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(sout.front()));
        sout.pop();
        root->left = toTree(sout);
        root->right = toTree(sout);
        return root;
    }


};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

