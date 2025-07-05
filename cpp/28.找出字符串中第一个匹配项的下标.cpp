/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.size(); i++) {
            int j = 0;
            while (haystack[i+j] == needle[j]) {
                j++;
                if (j == needle.size()) {
                    return i;
                }
            }
        }
        return -1;
        }
};
// @lc code=end

