/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> cnt1;
        for (int x: nums1) {
            cnt1[x]++;
        }
        vector<int> result;
        for (int x : nums2) {
            if (cnt1[x] > 0) {
                result.push_back(x);
                cnt1[x]--;
            }
        }
        return result;
    }
};
// @lc code=end

