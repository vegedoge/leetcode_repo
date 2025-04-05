/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int max_len = 0;
        for (auto num: num_set) {
            if (num_set.find(num-1) == num_set.end()) {
                int local_len = 0;
                while (num_set.find(num) != num_set.end()) {
                    local_len++;
                    num++;
                }
                max_len = max(max_len, local_len);
            }
        }
        return max_len;
    }
};
// @lc code=end

