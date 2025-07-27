/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> results;
    vector<int> temp_result;
    int local_sum;

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        results.clear();
        temp_result.clear();
        local_sum = 0;
        sort(candidates.begin(), candidates.end());
        backTracking(candidates, target, 0);

        return results;
    }

    void backTracking(vector<int>& candidates, int target, int startIndex) {

        if (target == local_sum) {
            results.push_back(temp_result);
        } else if (target < local_sum) {
            return;
        } else {
            for (int i = startIndex; i < candidates.size(); ++i) {
                // 在同一层 进行去重 同一层不能使用相同元素 纵向的不同层可以
                if (i > startIndex) {
                    if (candidates[i - 1] == candidates[i]) {
                        continue;
                    }
                }
                temp_result.push_back(candidates[i]);
                local_sum += candidates[i];
                backTracking(candidates, target, i + 1);
                local_sum -= candidates[i];
                temp_result.pop_back();
            }
        }
    }
};
// @lc code=end

