/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start

#include<iostream>

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(-1); //创建哨兵节点
        ListNode* pre = preHead;
        while (l1 != nullptr && l2 != nullptr){
            if (l1->val < l2->val){
                pre->next = l1;
                l1 = l1->next;
            }
            else{
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        pre->next = l1 == nullptr ? l2 : l1; // 不懂
        return preHead->next; //为啥返回preHead而不是pre
    }
};
// @lc code=end

