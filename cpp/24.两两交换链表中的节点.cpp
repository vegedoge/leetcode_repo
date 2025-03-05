/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *cur = dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode* temp_next = cur->next->next->next;
            ListNode *temp = cur->next;
            cur->next = cur->next->next;    // link head to 2
            cur->next->next = temp;         // switch 2 & 1
            cur->next->next->next = temp_next;  // link new 2 and old 3

            cur = cur->next->next;
        }
        ListNode *output = dummyHead->next;
        delete dummyHead;
        return output;
    }
};
// @lc code=end

