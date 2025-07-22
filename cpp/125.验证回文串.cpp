/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */
#include<string>
#include <cctype>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 1) {
            return true;
        }
        int left = 0;
        int right = s.size() - 1;

        while(left < right) {
            // 可以用isdigit
            // isalnum
            while (left < right && (s[left] > 'z' || s[left] < 'a')
                    && (s[left] >'Z' || s[left] < 'A')
                    && (s[left] > '9' || s[left] < '0') ) {
                left++;
            }

            while (left < right && (s[right] > 'z' || s[right] < 'a')
                    && (s[right] >'Z' || s[right] < 'A')
                    && (s[right] > '9' || s[right] < '0') ) {
                right--;
            }

            char temp_1 = std::tolower(s[left]);
            char temp_2 = std::tolower(s[right]);

            if (temp_1 != temp_2) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
// @lc code=end

