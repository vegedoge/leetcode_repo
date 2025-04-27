/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include<vector>
// @lc code=start
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        int mid;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // mid 在左边
            if(nums[mid] >= nums[left]) {
                // target 在left和mid之间 向左搜索
                if (nums[mid] > target && nums[left] <= target) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            // mid在右边
            } else {
                // target 在mid和right之间 向右搜索
                if (nums[mid] <= target && nums[right-1] >= target) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }

        return -1;
    }
};
// @lc code=end

