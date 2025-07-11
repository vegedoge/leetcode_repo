/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
private:
    int getKthElement(const vector<int>& nums1, int idx1,
                    const vector<int>& nums2, int idx2,
                    int k) 
    {
        int m = nums1.size();
        int n = nums2.size();

        // 边界条件, m或者n被排除完了
        if (m == idx1) {
            return nums2[idx2 + k - 1];
        }

        if (n == idx2) {
            return nums1[idx1 + k - 1];
        }

        // 边界k == 1, 找最小
        if (k == 1) {
            return std::min(nums1[idx1], nums2[idx2]);
        }

        // 递归
        int new_idx1 = std::min(idx1 + k / 2, m) - 1;
        int new_idx2 = std::min(idx2 + k / 2, n) - 1;

        int pivot1 = nums1[new_idx1];
        int pivot2 = nums2[new_idx2];

        if (pivot1 <= pivot2) {
            return getKthElement(nums1, new_idx1 + 1, nums2, idx2, k - (new_idx1 - idx1 + 1));
        } else {
            return getKthElement(nums1, idx1, nums2, new_idx2 + 1, k - (new_idx2 - idx2 + 1));
        }
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int length = m + n;
        if (length % 2 == 0) {
            int mid1 = getKthElement(nums1, 0, nums2, 0, length / 2);
            int mid2 = getKthElement(nums1, 0, nums2, 0, length / 2 + 1);
            return static_cast<double>(mid1 + mid2) / 2.0;
        } else {
            return getKthElement(nums1, 0, nums2, 0, length / 2 + 1);
        }
    }
};
// @lc code=end

