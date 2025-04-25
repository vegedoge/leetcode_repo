/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // dp[i][j] 长度为i-1的nums1 和长度为j-1的nums2的最长重复子数组
        int m = nums1.size();
        int n = nums2.size();
        int result = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } 
                if(dp[i][j] > result)
                    result = dp[i][j];
            }
        }

        return result;
    }
};
// @lc code=end

