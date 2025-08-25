/*
 * @lc app=leetcode.cn id=1218 lang=cpp
 *
 * [1218] 最长定差子序列
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int result = 0;
        int n = arr.size();
        unordered_map<int, int> dp;
        for (int i = 0; i < n; ++i) {
            if (dp.count(arr[i] - difference)) {
                dp[arr[i]] = dp[arr[i] - difference] + 1;
            } else {
                dp[arr[i]] = 1;
            }
            result = max(result, dp[arr[i]]);
        }
        // for (const auto& x: dp) {
        //     result = max(result, x.second);
        // }
        return result;
    }
};
// @lc code=end

