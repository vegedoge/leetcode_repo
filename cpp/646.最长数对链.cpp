/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */
#include <algorithm>

// @lc code=start
class Solution {
static bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    } else {
        return a[0] < b[0];
    }
}
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), cmp);
        vector<int> dp(n, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};
// @lc code=end

