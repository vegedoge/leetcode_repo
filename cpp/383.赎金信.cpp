/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */
#include<unordered_map>
// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int> targets;
        for (auto c : ransomNote)
        {
            targets[c]++;
        }
        for (auto c: magazine) {
            if (targets.find(c) != targets.end()) {
                if (targets[c] > 0)
                    targets[c]--;
            }
        }

        for (auto c: targets) {
            if (c.second != 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

