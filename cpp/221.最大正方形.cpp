/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */
#include<vector>
#include<algorithm>
// @lc code=start
class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int max_size = 0;

        // 以ij为右下角的正方形的最大边长
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        dp[1][1] = matrix[0][0];

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = 1 + std::min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]});
                    if (dp[i][j] > max_size) {
                        max_size = dp[i][j];
                    }
                }
            }
        }

        return max_size * max_size;
    }
};
// @lc code=end

