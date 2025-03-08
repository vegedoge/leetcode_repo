/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */
#include <algorithm>
// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        // reverse(s.begin(), s.end());
        for (int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--) {
            std::swap(s[i], s[j]);
        }
    }
};
// @lc code=end

