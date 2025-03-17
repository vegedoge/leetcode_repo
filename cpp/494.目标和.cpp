/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     int sum = 0;
    //     for (int num : nums)
    //     {
    //         sum += num;
    //     }
    //     if (abs(target) > sum)
    //         return 0;
    //     // x - (sum - x) = target
    //     if ((target+sum) % 2 == 1)
    //         return 0;

    //     int bagSize = (target + sum) / 2;
    //     // 相当于填满bagSize的+符号num和
    //     vector<vector<int>> dp(n, vector<int>(bagSize+1, 0));

    //     // init
    //     if (nums[0] <= bagSize)
    //         dp[0][nums[0]] = 1;

    //     dp[0][0] = 1;

    //     //处理0的组合
    //     int numZero = 0;
    //     for (int i = 0; i < n; i++) {
    //         if (nums[i] == 0) {
    //             numZero++;
    //         }
    //         dp[i][0] = (int) pow(2, numZero);
    //     }

    //     for (int i = 1; i < n; i++) {
    //         for (int j = 0; j <= bagSize; j++) {
    //             if (nums[i] > j)
    //                 dp[i][j] = dp[i - 1][j];
    //             else
    //                 dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
    //         }
    //     }
    //     return dp[n - 1][bagSize];
    // }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int ele: nums) {
            sum += ele;
        }
        if (abs(target) > sum)
            return 0;
        int bagSize = (sum + target) / 2;
        if ((target + sum) % 2 == 1)
            return 0;

        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            // j enough to hold nums[0...i]
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};
// @lc code=end

