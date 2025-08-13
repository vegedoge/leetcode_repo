/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        //找到区域前一个
        ListNode *pre_left = dummy;
        for (int i = 0; i < left - 1; ++i) {
            pre_left = pre_left->next;
        }

        ListNode *cur = pre_left->next;
        ListNode *temp;
        ListNode *pre = nullptr;
        for (int i = 0; i < right - left + 1; ++i) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }

        pre_left->next->next = cur;
        pre_left->next = pre;

        return dummy->next;
    }
};
// @lc code=end

