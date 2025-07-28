/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */
#include<vector>
#include<unordered_map>
using namespace std;
// @lc code=start
class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> val_2_idx_table;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (val_2_idx_table.find(val) != val_2_idx_table.end()) {
            return false;
        } else {
            val_2_idx_table[val] = nums.size();
            nums.push_back(val);
            return true;
        }
        
    }
    
    bool remove(int val) {
        if (val_2_idx_table.find(val) == val_2_idx_table.end()) {
            return false;
        } else {
            int idx = val_2_idx_table[val];

            swap(nums[idx], nums.back());
            nums.pop_back();

            // update index 
            val_2_idx_table[nums[idx]] = idx;
            val_2_idx_table.erase(val);

            return true;
        }
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

