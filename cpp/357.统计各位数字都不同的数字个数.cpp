/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 统计各位数字都不同的数字个数
 */
#include<math.h>
// @lc code=start
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return 10;
        }
        int result = 0;
        for (int i = 2; i <= n; ++i)
        {
            result += helper(i);
        }

        return result + 10;
    }

    int helper(int n) {
        int local_result = 9;
        for (int i = 2; i <= n; ++i)
        {
            local_result = local_result * (10 - i + 1);
        }

        return local_result;
    }
};
// @lc code=end

