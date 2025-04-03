/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // we take 0s and 1s as stuff to be filled into a 2-dim-bag
        vector<int> zeros(strs.size(), 0);
        vector<int> ones(strs.size(), 0);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < strs.size(); i++)
        {
            // get zeros and ones
            for (char c: strs[i]) {
                if (c == '0') {
                    zeros[i] += 1;
                } else if (c == '1') {
                    ones[i] += 1;
                }
            }
        }

        for (int i = 0; i < strs.size(); i++) {
            for (int j = m; j >= zeros[i]; j--) {
                for (int k = n; k >= ones[i]; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - zeros[i]][k - ones[i]] + 1);
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

