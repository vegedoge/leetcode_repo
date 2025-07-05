/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.back() == 9) {
            digits.pop_back();
            if (digits.empty()) {
                digits.emplace_back(0);
            }
            vector<int> temp = plusOne(digits);
            temp.emplace_back(0);
            return temp;
        } else {
            digits.back() += 1;
            return digits;
        }
    }
};
// @lc code=end

