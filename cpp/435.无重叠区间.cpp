/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        } else {
            return a[0] < b[0];
        }
    }

    // 其实就是求总区间数量减去不交叉的区间数量
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int result = 1;

        for (int i = 1; i < intervals.size(); ++i) {
            // 没重合
            if (intervals[i][0] >= intervals[i-1][1]) {
                result++;
            } else {
                // 取最小右边界
                intervals[i][1] = min(intervals[i][1], intervals[i - 1][1]);
            }
        }

        return intervals.size() - result;
    }
};
// @lc code=end

