/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        string result = "";
        int shortest_len = __INT32_MAX__;
        // window
        int sub_len;
        int start = 0;
        int end = 0;
        // matched sub string
        int head = 0;
        int matches = 0;

        // init unordered map
        unordered_map<char, int> target, window;
        for (char c: t) target[c]++;

        for (; end < s.size(); end++) {
            // get right element
            char c = s[end];

            // new window element matches one target element
            if (target.count(c)) {
                window[c]++;
                if (window[c] == target[c])
                    matches++;
            }

            while (matches == target.size()) {
                sub_len = end - start + 1;
                if (shortest_len > sub_len) {
                    shortest_len = sub_len;
                    head = start;
                }

                // get left element
                char h = s[start];
                start++;

                if (target.count(h)) {
                    window[h]--;
                    if (window[h] == (target[h] - 1))
                        matches--;
                }
            }
        }
        result = shortest_len < __INT32_MAX__ ? s.substr(head, shortest_len) : result;
        return result;
    }
};
// @lc code=end

