/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> mappings;
        int y;
        for (int i = 0; i < nums.size(); i++)
        {
            y = target - nums[i];
            if (mappings.find(y) != mappings.end())
            {
                return {i, mappings[y]};
            }
            else
            {
                mappings[nums[i]] = i;
            }
        }
        return {}; // Return empty vector if no solution found
    }
};
// @lc code=end

