/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
using namespace std;
#include <vector>
#include <algorithm>
// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1)
        {
            return intervals;
        }
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size();) {
            int local_max = intervals[i][1];
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= local_max) {
                local_max = local_max > intervals[j][1] ? local_max : intervals[j][1];
                j++;
            }
            result.push_back({intervals[i][0], local_max});
            i = j;
        }
        return result;
    }
};
// @lc code=end

