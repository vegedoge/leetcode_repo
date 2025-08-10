/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) {
            nums1 = nums2;
            return;
        } else if (n == 0) {
            return;
        } 

        int right_1 = m-1;
        int right_2 = n-1;
        int right = m + n - 1;

        while (right_2 >= 0 && right_1 >= 0) {
            int temp_1 = nums1[right_1];
            int temp_2 = nums2[right_2];

            if (temp_1 > temp_2) {
                nums1[right] = temp_1;
                right_1--;
            } else {
                nums1[right] = temp_2;
                right_2--; 
            }
            
            right--;
        }

        if (right_2 >= 0) {
            for (int i = right_2; i >= 0; i--) {
                nums1[i] = nums2[i];
            }
        }

    }
};
// @lc code=end

