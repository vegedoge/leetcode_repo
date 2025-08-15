/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

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

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        if (intervals.size() == 0) {
            result.push_back(newInterval);
            return result;
        }

        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), cmp);
        // 防止最后一个没塞进去
        intervals.push_back({100001, 1000002});

        for (int i = 1; i < intervals.size(); ++i) {
            // 没重合
            if (intervals[i][0] > intervals[i - 1][1]) {
                result.push_back(intervals[i - 1]);
            } else {
                intervals[i][0] = std::min(intervals[i - 1][0], intervals[i][0]);
                intervals[i][1] = std::max(intervals[i - 1][1], intervals[i][1]);
            }
        }

        return result;
    }
};
// @lc code=end

