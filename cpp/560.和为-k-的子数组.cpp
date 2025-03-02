/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // prefix sum j - prefix sum (i-1) = k
        // prefix sum (i-1) = prefix sum j - k
        unordered_map<int, int> prefix_sum;
        prefix_sum[0] = 1;
        int sum = 0;
        int count = 0;

        for (auto num: nums) {
            sum += num;

            if (prefix_sum.find(sum - k) !=prefix_sum.end()) {
                count += prefix_sum[sum - k];
            }

            prefix_sum[sum]++;
        }
        return count;
    }
};
// @lc code=end

