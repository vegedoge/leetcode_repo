/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include <unordered_map>

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        std::unordered_map<char, int> window;
        int len = p.size();
        std::vector<int> result;
        std::unordered_map<char, int> inputs;
        int left = 0, right = 0;
        int valid = 0;

        for (auto c : p)
        {
            inputs[c]++;
        }

        if (s.size() < p.size())
            return result;
        
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (inputs.count(c))
            {
                window[c]++;
                if (inputs[c] == window[c]) {
                    valid++;
                }
            }

            while (right - left == len) {
                if (valid == inputs.size()) {
                    result.push_back(left);
                }
                char cl = s[left];
                left++;

                if (inputs.count(cl)) {
                    if (window[cl] == inputs[cl]) {
                        valid--;
                    }

                    window[cl]--;
                }
            }
        }
        return result;
    }
};
// @lc code=end

