/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int middle;

        while (right > left)
        {
            middle = left + (right - left) / 2;

            if (nums[middle] == target) {
                return middle;
            }
            else if (nums[middle] > target) {
                right = middle;
            } else {
                left = middle + 1; //左闭右开
            }
        }
        return -1;
    }

    // int search(vector<int>& nums, int target) {
    //     int left = 0;
    //     int right = nums.size() - 1;
    //     int middle;

    //     while (left <= right) {      // 闭区间
    //         middle = left + (right - left) / 2;

    //         if (nums[middle] == target) {
    //             return middle;
    //         } 
    //         else if (nums[middle] > target) {
    //             right = middle - 1; //左右都闭
    //         } else {
    //             left = middle + 1;
    //         }
    //     }
    //     return -1;
    // }
};

// @lc code=end
