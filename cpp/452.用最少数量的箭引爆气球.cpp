/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
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
        }
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int arrows = 1;

        for (int i = 1; i < points.size(); ++i)
        {
            // 没重叠上
            if (points[i][0] > points[i-1][1]) {
                arrows++;
            } else {
                // 保证取最小的重合区域
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }

        return arrows;
    }
};
// @lc code=end

