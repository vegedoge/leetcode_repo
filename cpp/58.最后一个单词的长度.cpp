/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */
#include<string>

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int temp = 1;
        bool valid_flag = false;
        for (auto c : s)
        {
            if (c == ' ') {
                valid_flag = false;
                continue;
            } else {
                // clear last word
                if (!valid_flag) {
                    valid_flag = true;
                    temp = 0;
                }
                // append char
                temp += 1;
            }
        }
        return temp;
    }
};
// @lc code=end

