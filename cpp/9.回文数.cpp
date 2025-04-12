/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#include<string>

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) {
            return false;
        }
        std::string x_str = std::to_string(x);
        int left = 0;
        int right = x_str.size();
        for (; left <= right; left++, right--) {
            if (x_str[left] != x_str[right -1]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

