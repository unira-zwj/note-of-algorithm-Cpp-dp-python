/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
 * 学习找father和dfs遍历 
 */
class Solution {
public:
    unordered_map<int, TreeNode*> father;
    unordered_map<int, bool> visit;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        father[root->val] = nullptr;
        pre(root);
        while (p != nullptr){
            visit[p->val] = true;
            p = father[p->val];
        }
        while (q != nullptr){
            if (visit[q->val] == true){
                return q;
            }
            q = father[q->val];
        }
        return nullptr;
    }

    // 前序遍历,为啥pre放在if里面
    void pre(TreeNode* root){
        if (root->left != nullptr){
            father[root->left->val] = root;
            pre(root->left);
        }
        if (root->right != nullptr){
            father[root->right->val] = root;
            pre(root->right);
        }
        
        
    }
};
// @lc code=end