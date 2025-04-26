/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
        bool isPalindrome(ListNode* head) {
            ListNode* secondHalf = secondHalfList(head);
            ListNode* list2 = reverseList(secondHalf->next);
            ListNode* cur = head;
            while(cur && list2 && cur->val == list2->val) {
                list2 = list2->next;
                cur = cur->next;
            }
    
            return list2 == nullptr;
            
        }
    
        ListNode* secondHalfList(ListNode* head) {
            ListNode* slow = head;
            ListNode* fast = head;
            while (fast->next && fast->next->next ) {
                slow = slow ->next;
                fast = fast ->next ->next;
            }
            return slow;
        }
    
        ListNode* reverseList(ListNode* head) {
            ListNode* prev = nullptr;
            ListNode* cur = head;
            while(cur != nullptr) {
                ListNode* temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;
            }
            return prev;
        }
    
    };
// @lc code=end

