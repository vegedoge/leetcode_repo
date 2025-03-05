/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *fast = dummyHead;
        ListNode *slow = dummyHead;
        int distance = 0;
        while (fast->next != nullptr)
        {
            fast = fast->next;
            distance++;
            if (distance == n + 1)
            {
                slow = slow->next;
                distance--;
            }
        }
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        ListNode *output = dummyHead->next;
        delete dummyHead;
        return output;
    }
};
// @lc code=end

