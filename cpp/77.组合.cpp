/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<int>> results;
    vector<int> path;
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            results.push_back(path);
            return;
        }

        for (int i = startIndex; i <= n; i++) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return results;
    }
};
// @lc code=end

