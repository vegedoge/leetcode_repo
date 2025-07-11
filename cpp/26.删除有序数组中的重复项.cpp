/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */
#include<vector>
#include<unordered_set>
#include<algorithm>
// @lc code=start
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[slow] == nums[fast]) {
                continue;
            } else {
                ++slow;
                nums[slow] = nums[fast];
            }
        }

        return slow + 1;
    }

};
// @lc code=end

