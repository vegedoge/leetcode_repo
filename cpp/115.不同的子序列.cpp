/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */
#include<string>
#include<vector>
// @lc code=start
class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        std::vector<std::vector<u_int64_t>> dp(t.size() + 1, std::vector<u_int64_t>(s.size() + 1, 0));
        for (int j = 0; j <= s.size(); ++j) {
            dp[0][j] = 1;
        }

        for (int i = 1; i <= t.size(); ++i) {
            for (int j = 1; j <= s.size(); ++j) {
                if (s[j-1] == t[i-1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        return dp[t.size()][s.size()];
    }
};
// @lc code=end

