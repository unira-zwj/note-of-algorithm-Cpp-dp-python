/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
/*
终止条件：
1. 当root节点左右孩子都为空，返回1
2. 当root节点左或右孩子有一个为空，返回不为空的孩子的深度
3. 当root节点左右孩子都不为空，返回左右孩子中的较小深度
*/
public:
    int minDepth(TreeNode* root) {
        if (root == 0) return 0;
        if (root->right == nullptr && root->left == nullptr) return 1;
        if (root->right == nullptr && root->left != nullptr){
            return minDepth(root->left) + 1;
        }
        if (root->right != nullptr && root->left == nullptr){
            return minDepth(root->right) + 1;
        }
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
// @lc code=end

