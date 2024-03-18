#
# @lc app=leetcode.cn id=11 lang=python3
#
# [11] 盛最多水的容器
#
from typing import List

# @lc code=start
class Solution:
    def maxArea(self, height: List[int]) -> int:
        left, right = 0, len(height) - 1
        record = 0
        while left < right:
            area = (right - left) * min(height[left], height[right])  
            if area > record:
                record = area
            if height[left] > height[right]:
                right -= 1
            else:
                left += 1
        
        return record
# @lc code=end

