/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class myq
{
public:
    deque<int> q;

    void push(int val){
        while ( !q.empty() && val > q.back()){
            q.pop_back();
        }
        q.push_back(val);
    }

    void pop(int val){
        if (!q.empty()&& val == q.front())
        {
            q.pop_front();
        }
        
    }

    int getMax(){
        return q.front();
    }
};



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        myq q;
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            q.push(nums[i]);
        }
        res.push_back(q.getMax());
        for (int i = k; i < nums.size(); i++) {
            q.pop(nums[i - k]);
            q.push(nums[i]); 
            res.push_back(q.getMax()); 
        }
        return res;
    }
};
// @lc code=end

