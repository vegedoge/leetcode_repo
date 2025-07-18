/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        // dp[i][j] word1的前i-1长度和word2的前j-1长度
        // 如果要一样需要的最小删除次数
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = 0;
        // 初始化和‘ ’的删除次数
        for (int i = 1; i < m + 1; ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j < n + 1; ++j) {
            dp[0][j] = j;
        }

        for (int i = 1; i < m + 1; ++i)
        {
            for (int j = 1; j < n + 1; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    // 如果一样 这次不用删除
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    // 如果不一样 选一个少的删除
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

