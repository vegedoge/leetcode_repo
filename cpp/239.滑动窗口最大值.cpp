/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include<deque>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
private:
    class IncreaseQueue {
    public:
        std::deque<int> dq;
        void push(int input) {
            while(!dq.empty() && input > dq.back()) {
                dq.pop_back();
            }
            dq.push_back(input);
        }

        void pop(int input) {
            if (!dq.empty() && input == dq.front()) {
                dq.pop_front();
            }
        }

        int front() {
            return dq.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        IncreaseQueue myQueue;
        vector<int> results;

        for (int i = 0; i < k; i++) {
            myQueue.push(nums[i]);
        }
        results.push_back(myQueue.front());

        for (int i = k; i < nums.size(); i++) {
            myQueue.pop(nums[i-k]);
            myQueue.push(nums[i]);
            results.push_back(myQueue.front());
        }

        return results;
    }
};
// @lc code=end

