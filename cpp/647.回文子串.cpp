/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    // 1. dp 
    // int countSubstrings(string s) {
    //     int n = s.size();
    //     // dp[i][j] 代表从i到j是回文
    //     vector<vector<bool>> dp(n, vector<bool>(n, false));
    //     int result = 0;
    //     // 先外层再里层
    //     for (int j = 0; j < n; ++j)
    //     {
    //         for (int i = 0; i <= j; ++i) {
    //             // 相等
    //             if (s[i] == s[j]) {
    //                 // 长度不大于2或者长度大于但里面也是回文
    //                 if (j - i < 2 || dp[i+1][j-1] == true) {
    //                     dp[i][j] = true;
    //                     result++;
    //                 }
    //             }
    //         }
    //     }
    //     return result;
    // }

    // 2. 中心扩散
    int countSubstrings(string s) {
        int n = s.size();
        int result = 0;

        for (int center = 0; center < n; ++center) {
            int result1 = expandFromCenter(s, center, center + 1);  // 两个数字中心
            int result2 = expandFromCenter(s, center; center);      // 单个数字中心
            result = result + result1 + result2;
        }

        return result;
    }

    int expandFromCenter(string s, int left, int right) {
        int result = 0;
        int l = left;
        int r = right;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
            result++;
        }

        return result;
    }
};
// @lc code=end

