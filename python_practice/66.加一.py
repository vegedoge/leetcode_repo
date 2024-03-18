#
# @lc app=leetcode.cn id=66 lang=python3
#
# [66] 加一
#
from typing import List
# @lc code=start
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits = digits[::-1]
        for i in range (len(digits)):
            if digits[i] == 9 and i == len(digits) -1:
                digits[i] = 0
                digits.append(1)
            elif digits[i] == 9:
                digits[i] = 0
            else:
                digits[i] += 1
                break
        return digits[::-1]
                
            
            
        
        
# @lc code=end

