/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/*
指针对应的就是地址，解题时不需要考虑节点元素，考虑好指针指向的地址就行了。
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
    ListNode* reverseList(ListNode* head) {
        ListNode* back = nullptr;
        while(head != nullptr){
            ListNode* hid = head->next;
            head->next = back;
            back = head;
            head = hid;
        }
        return back;
    }
};
// @lc code=end

