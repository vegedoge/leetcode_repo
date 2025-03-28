/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include<vector>
#include<algorithm>
// @lc code=start
class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;  // dp[i] means use min dp[i] coins to reach amount i
        for (int i = 0; i < amount + 1; i++){
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] > i) {
                    continue;
                } else {
                    dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
                }
                
            }
        }

        if (dp[amount] == amount + 1) {
            return -1;
        } else {
            return dp[amount];
        }
        }
};
// @lc code=end

