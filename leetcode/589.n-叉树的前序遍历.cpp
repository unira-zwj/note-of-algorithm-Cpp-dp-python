/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        find(root);
        return ans;
    }
private:
    vector<int> ans;
    void find(Node* root){
        if (root == 0) return;
        ans.push_back(root->val);
        // 注意这里的Node* 指针的遍历 root->children
        for (auto child : root->children){
            find(child);
        }
    }
};
// @lc code=end

