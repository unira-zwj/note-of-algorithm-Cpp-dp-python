/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
/*
1. 确定根和左右子树
preorder [3, 9, 20, 15, 17]
    inorder  [9, 3, 15, 20, 7]
            [3]
            / \
preorder  [9] [20, 15, 17]
inorder   [9] [15, 20, 7]
2. 

vector 没有find函数
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        int rootIndex = 0;
        while (inorder[rootIndex] != root->val)
            rootIndex ++;
        vector<int> leftIn(inorder.begin(), inorder.begin() + rootIndex);
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + rootIndex + 1);
        root->left = buildTree(leftPre, leftIn);
        vector<int> rightIn(inorder.begin() + rootIndex + 1, inorder.end());
        vector<int> rightPre(preorder.begin() + rootIndex + 1, preorder.end());
        root->right = buildTree(rightPre, rightIn);
        return root;    
    }
};
// @lc code=end

