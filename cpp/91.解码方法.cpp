/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */
#include <string>
#include <vector>


// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = s.size();
        s = " " + s;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        int a;
        int b;
        for (int i = 1; i < n + 1; ++i)
        {
            a = s[i] - '0';
            b = 10 * (s[i - 1] - '0') + s[i] - '0';

            // 以a结尾
            if (1 <= a && a <= 9 ) {
                dp[i] = dp[i - 1];
            }
            if (b >= 10 && b <= 26) {
                dp[i] += dp[i - 2];     // dp[i-1] + dp[i -2]
            }
        }

        return dp[n];
    }
};
// @lc code=end

