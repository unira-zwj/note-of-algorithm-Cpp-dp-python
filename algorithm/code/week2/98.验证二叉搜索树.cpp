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
如果该二叉树的左子树不为空，则左子树上所有节点的值均小于它的根节点的值； 
若它的右子树不空，则右子树上所有节点的值均大于它的根节点的值；
它的左右子树也为二叉搜索树。
递推公式：判断root是否是比root.left大，并且比root.right小
终止条件：root == null
*/
public:
    bool isValidBST(TreeNode* root) {
        long long low = LONG_MIN;
        long long up = LONG_MAX;
        return val(root, low, up);
    }
private:
    bool val(TreeNode* root, long long low, long long up){
        if (root == nullptr) return true;
        if (root->val >= up || root->val <= low){
            return false;
        }
        return val(root->left, low, root->val) && val(root->right , root->val, up);
    }
};       
// @lc code=end
