/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<int>> results;
    int sum;
    vector<int> path;

    void backTracking(int k, int n, int startIndex, int sum) {
        if(path.size() == k) {
            if(sum == n) {
                results.push_back(path);
            }
            return;
        }

        for (int i = startIndex; i <= 9; i++) {
            sum += i;
            path.push_back(i);
            backTracking(k, n, i+1, sum);
            sum -= i;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backTracking(k, n, 1, 0);
        return results;
    }
};
// @lc code=end

