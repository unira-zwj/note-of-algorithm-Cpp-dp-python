/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
边界问题没考虑好，注意迭代是自迭代`fast = fast->next->next`.
循环条件也判断不好。。。。。
 */

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            if (fast == head) return true;
            head = head->next;
            if (fast == head) return true;
        }
        return false;
    }
};
// @lc code=end

