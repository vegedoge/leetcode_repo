/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
private:
    int sum;
    vector<int> temp;
    vector<vector<int>> results;

    void backTracking(const vector<int>& candidates, int target, int startIndex) {
        if (sum == target) {
            results.push_back(temp);
            return;
        } else if (sum > target) {
            return;
        } else {
            for (int i = startIndex; i < candidates.size(); i++) {
                sum += candidates[i];
                temp.push_back(candidates[i]);
                backTracking(candidates, target, i);
                sum -= candidates[i];
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        results.clear();
        temp.clear();
        backTracking(candidates, target, 0);
        return results;
    }
};
// @lc code=end

