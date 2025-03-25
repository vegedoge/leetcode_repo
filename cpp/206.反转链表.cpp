/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    // 迭代
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* temp;
    //     ListNode *pre = nullptr;
    //     ListNode *cur = head;

    //     while(cur!=nullptr){
    //         temp = cur->next;
    //         cur->next = pre;
    //         pre = cur;

    //         cur = temp;
    //     }

    //     return pre;
    // }
    // 递归
    ListNode* reverseList(ListNode* head) {
        if (head==nullptr || head->next==nullptr) {
            return head;
        }
        ListNode *h = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return h;   // return new head
    }
};
// @lc code=end


