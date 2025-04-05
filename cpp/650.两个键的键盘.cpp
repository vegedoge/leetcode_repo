/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 两个键的键盘
 */
#include <vector>
#include <cmath>

// @lc code=start
class Solution {
public:
    int minSteps(int n) {
        // i j dp[i][j]代表记事本i和剪切板j的最小操作数
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, __INT32_MAX__));
        int min;

        dp[1][0] = 0;
        dp[1][1] = 1;
        for (int i = 2; i <= n; i++) {
            min = __INT32_MAX__;
            for (int j = 1; j <= floor(i/2) ; j++) {
                // if paste
                dp[i][j] = dp[i - j][j] + 1;
                min = std::min(min, dp[i][j]);
            }
            // paste
            dp[i][i] = min + 1;
        }

        int ans = __INT32_MAX__;
        for (int k = 0; k <= n; k++) {
            ans = std::min(ans, dp[n][k]);
        }

        return ans;
    }
};
// @lc code=end

