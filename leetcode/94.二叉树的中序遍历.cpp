/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        find(root);
        return ans;
    }
private:
    // 形参中vector<int>& ans 注意这里加&引用
    vector<int> ans;
    void find(TreeNode* root){
        if (root == 0) return;
        find(root->left);
        ans.push_back(root->val);
        find(root->right);
    }
};
// @lc code=end

