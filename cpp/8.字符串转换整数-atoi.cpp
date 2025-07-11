/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <string>
// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        bool negative = false;
        bool blank = false;
        bool flag = false;
        bool zeros = false;
        bool overflow = false;
        int result = 0;
        int i = 0;
        while (s[i] == ' ')
        {
            i++;
        }

        if (s[i] == '+' && !flag) {
            flag = true;
            i++;
        } else if (s[i] == '-' && !flag) {
            flag = true;
            negative = true;
            i++;
        }

        while (s[i] == '0' && !zeros) {
            i++;
        }
        flag = true;
        zeros = true;

        while (s[i] >= '0' && s[i] <= '9') {
            int temp = s[i] - '0';
            if ((__INT32_MAX__ - temp) / 10 < result) {
                result = __INT32_MAX__;
                overflow = true;
                break;
            }
            result = result * 10 + temp;
            i++;
        }

        if (negative) {
            if (overflow) {
                return -1 * result - 1;
            } else {
                return -1 * result;
            }
        } else {
            return result;
        }
    }
};
// @lc code=end

