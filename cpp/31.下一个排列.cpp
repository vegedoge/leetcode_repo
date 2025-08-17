/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int target_idx = -1;

        // 从右往左找第一个 nums[i] < nums[i+1]
        for (int i = len - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                target_idx = i;
                break;
            }
        }

        // 如果没找到，说明是最大排列，直接反转
        if (target_idx == -1) {
            reverse(nums, 0, len - 1);
            return;
        }

        // 从右往左找第一个大于 nums[target_idx] 的数
        int swap_idx = -1;
        for (int i = len - 1; i > target_idx; --i) {
            if (nums[i] > nums[target_idx]) {
                swap_idx = i;
                break;
            }
        }

        // 交换
        swap(nums, target_idx, swap_idx);

        // 反转 target_idx 之后的部分
        reverse(nums, target_idx + 1, len - 1);
    }

    void swap(vector<int>& nums, int left, int right) {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
    }

    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums, left, right);
            ++left;
            --right;
        }
    }
};
// @lc code=end

