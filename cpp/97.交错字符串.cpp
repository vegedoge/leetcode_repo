/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */
#include<string>
#include<vector>
// @lc code=start
class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        int m = s1.length() + 1;
        int n = s2.length() + 1;

        if (s3.length() != s1.length() + s2.length()) {
            return false;
        }

        std::vector<std::vector<bool>> dp(m, std::vector<bool>(n, false));
        dp[0][0] = true;
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i - 1][0] & s1[i - 1] == s3[i - 1];
        }

        for (int j = 1; j < n; ++j) {
            dp[0][j] = dp[0][j - 1] & s2[j - 1] == s3[j - 1];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = (dp[i - 1][j] & s1[i - 1] == s3[i + j - 1]) ||
                           (dp[i][j - 1] & s2[j - 1] == s3[i + j - 1]);
            }
        }

        return dp[m-1][n-1];
    }
};
// @lc code=end

