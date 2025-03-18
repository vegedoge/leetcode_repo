/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Remove extra spaces
        removeSpace(s);
        
        // Step 2: Reverse the entire string
        reverse(s, 0, s.size() - 1);
        
        // Step 3: Reverse each word in the reversed string
        int word_start = 0;
        for (int i = 0; i <= s.size(); ++i) { // 注意这里的<=，确保处理到最后一个单词
            if (i == s.size() || s[i] == ' ') {
                reverse(s, word_start, i - 1);
                word_start = i + 1;
            }
        }
        
        return s;
    }

private:
    void removeSpace(string& s) {
        int slow = 0;
        bool lastIsSpace = true;
        for (int fast = 0; fast < s.size(); ++fast) {
            if (s[fast] != ' ') {
                if (lastIsSpace && slow != 0) {
                    s[slow++] = ' '; // Add one space before new word
                }
                lastIsSpace = false;
                s[slow++] = s[fast];
            } else {
                lastIsSpace = true;
            }
        }
        s.resize(slow); // Resize to remove trailing spaces
    }

    void reverse(string& s, int start, int end) {
        while (start < end) {
            swap(s[start++], s[end--]);
        }
    }
};
// @lc code=end

