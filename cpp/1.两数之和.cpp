/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <unordered_map>
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> mapping;
        for (int i = 0; i < nums.size(); i++) {
            auto iter = mapping.find(target - nums[i]);
            if (iter != mapping.end()) {
                return { i, iter->second };
            }

            mapping[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

