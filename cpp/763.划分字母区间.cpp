/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
#include<vector>
#include<string>
// @lc code=start
class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        int alphabet[26];

        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a';
            // 保存最远距离
            alphabet[idx] = i;
        }

        int curRange = 0;
        int counter = 0;
        std::vector<int> results;
        for (int i = 0; i < s.size(); ++i)
        {
            counter++;
            curRange = std::max(curRange, alphabet[s[i] - 'a']);
            if (curRange == i) {
                results.push_back(counter);
                counter = 0;
            }
        }

        return results;
    }
};
// @lc code=end

