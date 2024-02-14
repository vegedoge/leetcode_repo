#
# @lc app=leetcode.cn id=2 lang=python3
#
# [2] 两数相加
#

# @lc code=start
# Definition for singly-linked list.
# from typing import Optional
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        def sumTwoDigit(digit1, digit2, carry):
            sum = digit1 + digit2 + carry
            carry = sum // 10
            residue = sum % 10
            return carry, residue
        
        result_head = ListNode()
        current = result_head
        carry = 0
        
        while l1 or l2 or carry:
            digit1 = l1.val if l1 else 0
            digit2 = l2.val if l2 else 0
            
            carry, residue = sumTwoDigit(digit1, digit2, carry)
            current.next = ListNode(residue)           
            current = current.next
            
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        
        return result_head.next
                
            
# @lc code=end

