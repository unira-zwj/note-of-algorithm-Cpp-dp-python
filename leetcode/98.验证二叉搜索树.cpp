/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
#include<iostream>
#include<vector>
using namespace std;

class Solution {
/*
节点的左子树只包含小于当前节点的数。=> 左子数的最大节点比根小
节点的右子树只包含大于当前节点的数。=> 右子数的最小节点比根大
所有左子树和右子树自身必须也是二叉搜索树。
*/
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr ) return true;
        if (root->right <= root || root->left >= root){
            return false;
        }
        isValidBST(root->right);
        isValidBST(root->left);
        //if (root->right || root)
        return true;
    }
};
// @lc code=end

