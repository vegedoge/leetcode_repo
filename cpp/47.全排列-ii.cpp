/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include<vector>
using namespace std;
#include<algorithm>
// @lc code=start
class Solution {
private:
    vector<vector<int>> results;
    vector<int> path;
    vector<bool> used;
    void backTracking(vector<int> &nums)
    {
        if (path.size() == nums.size()) {
            results.emplace_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            // 每一层回溯是纵向深入 纵向深入结束之后回到横向
            // 此时used变为false 处理下一个 如果下一个和上一个一样，
            // 那就不需要再重复纵向处理
            // used主要看现在是在纵向里面还是不是

            path.push_back(nums[i]);
            used[i] = true;

            backTracking(nums);

            used[i] = false;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        results.clear();
        path.clear();

        sort(nums.begin(), nums.end());
        used.assign(nums.size(), false);

        backTracking(nums);
        return results;
    }
};
// @lc code=end

