/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

#include <algorithm>
// @lc code=start
class Solution {
static bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) {
        return a[1] > b[1];     // 这里是大于 相当于信封更宽
    } else  {
        return a[0] < b[0];
    }
}

static bool canHold(const vector<int>& a, const vector<int>& b) {
    return (a[0] > b[0] && a[1] > b[1]);
}

public:
    // int maxEnvelopes(vector<vector<int>>& envelopes) {
    //     int n = envelopes.size();
    //     sort(envelopes.begin(), envelopes.end(), cmp);

    //     vector<int> dp(n, 1);
    //     int result = 1;

    //     for (int i = 1; i < n; ++i) {
    //         for (int j = 0; j < i; ++j) {
    //             if (canHold(envelopes[i], envelopes[j])) {
    //                 dp[i] = max(dp[i], dp[j] + 1);
    //                 result = max(result, dp[i]);
    //             }
    //         }
    //     }

    //     return result;
    // }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            } else {
                return a[0] < b[0];
            }
        });

        vector<int> result;

        for (const auto& envelope: envelopes) {
            int height = envelope[1];

            // 找到套娃里能插入的位置
            auto it = std::lower_bound(result.begin(), result.end(), height);

            // 如果是最大的
            if (it == result.end()) {
                result.push_back(height);
            } else {
                // 不然换成尽可能小的,方便继续套
                // width因为已经排序了所以不用管
                *it = height;
            }
        }

        return result.size();
    }
};
// @lc code=end

