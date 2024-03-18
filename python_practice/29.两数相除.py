#
# @lc app=leetcode.cn id=29 lang=python3
#
# [29] 两数相除
#

# @lc code=start
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if divisor == 0:
            raise ZeroDivisionError("divisor is zero")
        
        INT_MAX = 2 ** 31 -1
        INT_MIN = -2 ** 31
        
        if dividend == INT_MIN and divisor == -1:
            return INT_MAX
        
        negative = (dividend < 0) ^ (divisor < 0)
        dividend = abs(dividend)
        divisor = abs(divisor)

        result = 0
        while dividend >= divisor:
            temp, count = divisor, 1
            while dividend >= (temp << 1):
                temp <<= 1
                count <<= 1
            dividend = dividend - temp
            result += count
        
        return -result if negative else result 
            
            
# @lc code=end

