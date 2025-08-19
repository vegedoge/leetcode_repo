/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */
#include <vector>

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        uint64_t n = coins.size();
        vector<vector<uint64_t>> dp(n + 1, vector<uint64_t>(amount + 1, 0));

        for (int i = 0; i < n + 1; ++i) {
            dp[i][0] = 1;
        }

        // for (int j = 0; j < amount + 1; ++j) {
        //     if (j % coins[0] == 0) {
        //         dp[0][j] = 1;
        //     }
        // }

        for (int i = 1; i < n + 1; ++i)
        {
            for (int j = 1; j < amount + 1; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if (coins[i-1] <= j)
                {
                    // 可以从当前里面一直选
                    dp[i][j] += dp[i][j - coins[i-1]];
                }
            }
        }

        return dp[n][amount];
    }
};
// @lc code=end

