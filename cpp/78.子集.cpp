/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> results;
    vector<int> temp_result;

    void backTracking(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            return;
        }

        for (int i = idx; i < nums.size(); ++i) {
            temp_result.push_back(nums[i]);
            results.push_back(temp_result);
            backTracking(nums, i + 1);
            temp_result.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        results.clear();
        temp_result.clear();
        std::vector<int> empty_inst;
        empty_inst.clear();
        results.emplace_back(empty_inst);
        backTracking(nums, 0);

        return results;
    }
};
// @lc code=end

