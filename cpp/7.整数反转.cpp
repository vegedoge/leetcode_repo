/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        // bool positive = x > 0 ? true : false;
        int result = x % 10;
        x = x / 10;
        while (x)
        {
            if (result > __INT32_MAX__ / 10) {
                return 0;
            }

            if (result < (-1 * (__INT32_MAX__ - 1)) / 10) {
                return 0;
            }
            result = 10 * result + x % 10;
            x = x / 10;
        }
        return result;
    }
};
// @lc code=end

