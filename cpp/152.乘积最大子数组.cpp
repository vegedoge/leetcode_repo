/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int local_max = 0;
        int local_min = 0;
        int global_max = 0;

        if (nums.size() == 1) {
            return nums[0];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(local_max, local_min);
            }
            local_max = max(nums[i], local_max * nums[i]);
            local_min = min(nums[i], local_min * nums[i]);
            global_max = max(local_max, global_max);
        }

        return global_max;
    }
};
// @lc code=end

