/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *cur2 = head;
        ListNode *temp2;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* second_head = reverseList(slow->next);

        slow->next = nullptr;

        ListNode *first_head = head;
        mergeList(first_head, second_head);

    }

    ListNode*  reverseList(ListNode* head) {
        ListNode *temp;
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            temp = cur->next;
            cur->next = prev;
            prev = cur;

            cur = temp;
        }

        return prev;
    }

    void mergeList(ListNode* head1, ListNode* head2) {
        ListNode *l1 = head1;
        ListNode *l2 = head2;
        while (l1 != nullptr && l2 != nullptr)
        {
            ListNode *l1_next = l1->next;
            ListNode *l2_next = l2->next;

            l1->next = l2;
            if (l1_next == nullptr)
            {
                break;
            }

            l2->next = l1_next;

            l1 = l1_next;
            l2 = l2_next;
        }
    }
};
// @lc code=end

