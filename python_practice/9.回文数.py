#
# @lc app=leetcode.cn id=9 lang=python3
#
# [9] 回文数
#

# @lc code=start
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            str_x = "-" + str(x)
        else:
            str_x = str(x)
        reversed_x = str_x[::-1]
        if reversed_x == str_x:
            return True
        else:
            return False     
        
# @lc code=end
