#
# @lc app=leetcode.cn id=15 lang=python3
#
# [15] 三数之和
#

# @lc code=start
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        if n < 3:
            return []
        # sort函数返回None，直接改变目标的顺序
        nums.sort()
        # 排序＋双指针移动
        i = 0
        results = []
        
        while i < n - 2:
            # 提高效率
            if nums[i] > 0:
                return results
            if i > 0 and nums[i] == nums[i-1]:
                i += 1
                continue
            j = i + 1
            k = n - 1
            
            while j < k:
                sum = nums[i] + nums[j] + nums[k]
                if sum < 0:
                    j += 1
                elif sum > 0:
                    k -= 1
                else:
                    array = [nums[i], nums[j], nums[k]]
                    results.append(array)
                    # 去重
                    while j < k and nums[j] == nums[j+1]:
                        j += 1
                    while j < k and nums[k] == nums[k-1]:
                        k -= 1
                    # 指针移动
                    j += 1
                    k -= 1
            i += 1
                
        return results
            
        
# @lc code=end

