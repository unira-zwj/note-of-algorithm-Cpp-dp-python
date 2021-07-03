/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
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
};*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        queue<pair<Node*, int>> pre;
        pre.push(make_pair(root, 0));
        while(!pre.empty()){
            // 取队头 front()返回起始元素
            Node* node = pre.front().first;
            int depth = pre.front().second;
            pre.pop();
            // 边界处理
            if (pre.size() <= depth) ans.push_back({});
            // 储存答案
            ans[depth].push_back(node->val);
            // 注意这里是node->children
            for (auto& child : node->children){
                pre.push(make_pair(child, depth + 1));
            }
        }
        return ans;
    }
};
// @lc code=end

