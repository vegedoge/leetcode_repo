/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> result;
        for (auto str : strs)
        {
            int counts[26] = {0};
            for (auto c: str) {
                counts[c - 'a'] += 1;
            }

            string key = "";

            for (int i = 0; i < 26; i++) {
                if (counts[i] != 0) {
                    key.push_back(i + 'a');
                    key.push_back(counts[i]);
                }
            }

            map[key].push_back(str);
        }

        for(auto& m: map) {
            result.push_back(m.second);
        }

        return result;
    }
};
// @lc code=end

