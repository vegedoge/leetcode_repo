#
# @lc app=leetcode.cn id=6 lang=python3
#
# [6] Z 字形变换
#

# @lc code=start
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows <= 1 or len(s) < numRows:
            return s
        result = [""] * numRows
        direction = 1
        row = 0
        
        for char in s:
            result[row] += char
            row = row + direction
            if row == numRows -1 or row == 0:
                direction *= -1
                
        return "".join(result)
                
              
        
# @lc code=end

