/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int max_len = 0;
        unordered_set<int> window;
        while(right < s.size()) {
            while(window.find(s[right]) != window.end()) {
                window.erase(s[left++]);
            }
            window.insert(s[right]);
            max_len = max(max_len, (right - left + 1));

            right++;
        }
        return max_len;
    }
};
// @lc code=end

