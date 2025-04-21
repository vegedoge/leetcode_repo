/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = head->next;
        // iterate to mid point
        while(fast!=nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *right = slow->next;
        slow->next = nullptr;
        ListNode *leftHead = sortList(head);
        ListNode *rightHead = sortList(right);

        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;

        while(leftHead!=nullptr || rightHead != nullptr){
            if(leftHead == nullptr) {
                cur->next = rightHead;
                break;
            }
            if(rightHead == nullptr) {
                cur->next = leftHead;
                break;
            }
            if(leftHead->val < rightHead->val) {
                cur->next = leftHead;
                leftHead = leftHead->next;
            } else {
                cur->next = rightHead;
                rightHead = rightHead->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
// @lc code=end

