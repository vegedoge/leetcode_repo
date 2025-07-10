/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
#include <algorithm>
class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0;
        int end = nums.size() - 1;
        int mid;
        int mid_val;

        while (begin < end) {
            mid = begin + (end - begin) / 2;
            mid_val = nums[mid];
            // compare last element and mid element
            if (mid_val < nums[nums.size() - 1]) {
                end = mid;
            } else {
                begin = mid + 1;
            }
        }

        return nums[begin];
    }
};
// @lc code=end

