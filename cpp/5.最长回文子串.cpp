/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 1;
        string result;
        result.push_back(s[0]);
        if (s.length() == 1)
        {
            return s;
        }

        for (int i = 0; i < s.length(); i++) {
            int len1 = expandFromCenter(s, i, i + 1);   // even centered
            int len2 = expandFromCenter(s, i, i);       // odd centered
            int local_len = max(len1, len2);
            if (local_len > maxLen)
            {
                maxLen = local_len;
                result = s.substr(i - ((local_len  - 1)/ 2), local_len);
            }
        }

        return result;
    }

    int expandFromCenter(string s, int left, int right) {
        int l = left;
        int r = right;
        while (l >= 0 && right < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }
};
// @lc code=end

