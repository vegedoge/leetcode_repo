/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include <vector>
#include <cmath>
using namespace std;
// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        // init
        for (int i = 0; i < n+1; i++) {
            dp[i] = i;
        }

        for (int i = 1; i < n+1; i++) {
            int floor_square = floor(sqrt(i));
            for (int j = 1; j <= floor_square; j++) {
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};
// @lc code=end

