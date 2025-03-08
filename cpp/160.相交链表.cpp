/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */
#include <algorithm>
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0;
        int lenB = 0;
        while (curA != nullptr)
        {
            lenA++;
            curA = curA->next;
        }

        while (curB != nullptr)
        {
            lenB++;
            curB = curB->next;
        }

        curA = headA;
        curB = headB;

        if (lenA < lenB) {
            std::swap(lenA, lenB);
            std::swap(curA, curB);
        }

        int gap = lenA - lenB;

        while(gap--) {
            curA = curA->next;
        }

        while(curA != nullptr) {
            if (curA == curB)
                return curA;
            curA = curA->next;
            curB = curB->next;
        }

        return nullptr;
    }
};
// @lc code=end

