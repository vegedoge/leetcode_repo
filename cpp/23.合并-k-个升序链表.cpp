/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode *result = new ListNode(-100001);
        for (int i = 0; i < n; ++i)
        {
            merge2Lists(result, lists[i]);
        }
        return result->next;
    }

    ListNode* merge2Lists(ListNode* list1, ListNode* list2) {

        if (list1 == nullptr)
        {
            return list2;
        }

        if (list2 == nullptr) {
            return list1;
        }

        if (list1->val < list2->val) {
            list1->next = merge2Lists(list1->next, list2);
            return list1;
        } else {
            list2->next = merge2Lists(list1, list2->next);
            return list2;
        }
    }
};
// @lc code=end

