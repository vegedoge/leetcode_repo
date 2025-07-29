/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */
#include<vector>
// @lc code=start
class Solution {
public:
    bool cashBack(std::vector<int>& changes, int input) {
        if (changes[0] != 0) {
            if (input == 10) {
                changes[0]--;
                changes[1]++;
                return true;
            } else {
                if (changes[1] != 0) {
                    changes[1]--;
                    changes[0]--;
                    return true;
                }
                else
                {
                    if (changes[0] > 2) {
                        changes[0] -= 3;
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        return false;
    }
    bool lemonadeChange(std::vector<int>& bills) {
        // 分别代表5 10存量
        std::vector<int> changes(2, 0);

        for(auto input: bills) {
            if (input == 5) {
                changes[0]++;
            } else {
                if (!cashBack(changes, input)) {
                    return false;
                }
            }
        }

        return true;
    }
};
// @lc code=end

