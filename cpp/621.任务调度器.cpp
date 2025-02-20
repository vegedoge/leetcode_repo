/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::vector <int> vec(26, 0);
        for (char c : tasks) {
            vec[c - 'A']++;
        }
        sort(vec.begin(), vec.end(), greater<int>());
        int cnt = 1;
        // record those tasks cant be inserted into the interval
        while (cnt < vec.size() && vec[cnt] == vec[0]) {
            cnt++;
        }
        return max((vec[0] - 1) * (n + 1) + cnt, (int)tasks.size());
    }
};
// @lc code=end

