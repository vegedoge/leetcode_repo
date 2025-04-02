/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k);
        }

    int quickSelect(vector<int>& nums, int k) {
        vector<int> smaller, equal, greater;
        // random init pivot
        int pivot = nums[rand() % nums.size()];

        for (int num: nums) {
            if (num > pivot)
                greater.push_back(num);
            else if (num < pivot)
                smaller.push_back(num);
            else
                equal.push_back(num);
        }

        if (k <= greater.size()) {
            return quickSelect(greater, k);
        }

        if (k > greater.size() + equal.size()) {
            return quickSelect(smaller, k - greater.size() - equal.size());
        }

        return pivot;
    }
};
// @lc code=end

