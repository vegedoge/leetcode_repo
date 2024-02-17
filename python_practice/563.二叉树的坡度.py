#
# @lc app=leetcode.cn id=563 lang=python3
#
# [563] 二叉树的坡度
#

# @lc code=start
# Definition for a binary tree node.
# from typing import Optional

# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
        
class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        def search(root: Optional[TreeNode]):
            if not root:
                return 0, 0
            left_sum, left_slope = search(root.left)
            right_sum, right_slope = search(root.right)
            return left_sum + right_sum + root.val, abs(left_sum - right_sum) + left_slope + right_slope
        
        leaf_sum, slope_sum = search(root)
        return slope_sum
        
        
# @lc code=end

