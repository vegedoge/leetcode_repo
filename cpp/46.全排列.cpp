/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<int>> results;
    void backTracking(vector<int>& nums, int startIndex) {
        if (nums.size() == startIndex) {
            results.emplace_back(nums);
            return;
        }

        for(int i = startIndex; i < nums.size(); i++) {
            std::swap(nums[i], nums[startIndex]);
            backTracking(nums, startIndex + 1);
            std::swap(nums[i], nums[startIndex]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backTracking(nums, 0);
        return results;
    }
};
// @lc code=end

