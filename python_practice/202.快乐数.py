#
# @lc app=leetcode.cn id=202 lang=python3
#
# [202] 快乐数
#


# @lc code=start
class Solution:
    def isHappy(self, n: int) -> bool:
        def cal_sum(n: int) -> int:
            '''calculate helper'''
            sum = 0
            while n > 0:
                last = n % 10
                n = n // 10
                sum += last * last
            return sum

        history = set()
        while True:
            if n == 1:
                return True
            else:
                history.add(n)
                n = cal_sum(n)
                if n in history:
                    return False


# @lc code=end
