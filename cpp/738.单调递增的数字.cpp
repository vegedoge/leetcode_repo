/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */
#include<string>
// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        std::string num = std::to_string(n);
        int largest_digit = num.size();

        for (int i = num.size() - 1; i > 0; --i) {
            if (num[i - 1] > num[i]) {
                largest_digit = i;
                num[i - 1]--;
            }
        }

        for (int i = largest_digit; i < num.size(); ++i) {
            num[i] = '9';
        }

        return std::stoi(num);
    }
};
// @lc code=end

