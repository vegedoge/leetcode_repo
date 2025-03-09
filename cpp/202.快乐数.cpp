/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> history;
        while (true)
        {
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            if (history.find(sum) != history.end()) {
                return false;
            } else {
                n = sum;
                history.insert(n);
            }
        }
    }

    int getSum(int n) {
        int sum = 0;
        while (n > 0)
        {
            int last = n % 10;
            n = n / 10;
            sum += last * last;
        }
        return sum;
    }
};
// @lc code=end

