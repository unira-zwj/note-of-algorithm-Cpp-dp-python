/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* low = head;
        while (fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            low = low->next;
            if (fast == low){
                while (head != low){
                    head = head->next;
                    low = low->next;
                }
                return head;
            }
        }
        return nullptr;
    }
};
// @lc code=end

