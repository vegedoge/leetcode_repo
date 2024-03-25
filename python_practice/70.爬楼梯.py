#
# @lc app=leetcode.cn id=70 lang=python3
#
# [70] 爬楼梯
#

# @lc code=start
class Solution:
    def climbStairs(self, n: int) -> int:
        # fn = f[n-1] + f[n-2]
        if n == 1:
            return 1
        elif n == 2:
            return 2
        else:
            f = [1, 2]
            for i in range(2, n):
                fn = f[0] + f[1]
                f[0] = f[1]
                f[1] = fn
            return f[1]
                
            
        
# @lc code=end

