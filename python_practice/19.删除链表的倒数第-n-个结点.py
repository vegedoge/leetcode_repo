#
# @lc app=leetcode.cn id=19 lang=python3
#
# [19] 删除链表的倒数第 N 个结点
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode()
        listQueue = []
        current = dummy
        count = 0
        start = head
        while head is not None:
            current = head
            head = head.next
            count += 1
            if count <= n + 1:
                listQueue.append(current)
            else:
                listQueue = listQueue[1:]
                listQueue.append(current)
        if count == n:
            start = start.next
        else:  
            listQueue[0].next = None if listQueue[0].next is None else listQueue[0].next.next
        return start
        
            
            
# @lc code=end

