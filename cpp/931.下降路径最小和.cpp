/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int result = 10001;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // init
        for (int j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int min_prev = dp[i - 1][j];
                if (j > 0)
                {
                    min_prev = min(min_prev, dp[i - 1][j - 1]);
                }

                if (j < n - 1) {
                    min_prev = min(min_prev, dp[i - 1][j + 1]);
                }

                dp[i][j] = matrix[i][j] + min_prev;
            }
        }

        for (int j = 0; j < n; ++j) {
            result = min(result, dp[n - 1][j]);
        }

        return result;
    }
};
// @lc code=end

