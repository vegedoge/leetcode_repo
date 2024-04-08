#
# @lc app=leetcode.cn id=263 lang=python3
#
# [263] 丑数
#


# @lc code=start
class Solution:
    def isUgly(self, n: int) -> bool:
        if n < 1:
            return False
        elif n < 7:
            return True
        else:
            while n >= 7:
                if n % 2 == 0:
                    n = n / 2
                    continue
                elif n % 3 == 0:
                    n = n / 3
                    continue
                elif n % 5 == 0:
                    n = n / 5
                    continue
                else:
                    return False
            return True


# @lc code=end
