/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class mycmp
{   
    public:

    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
};
class Solution {
public:


    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycmp> q;

        for (unordered_map<int,int>::iterator it = map.begin(); it != map.end(); it++)
        {
            q.push(*it);
            if (q.size()>k)
            {
                q.pop();
            }
            
        }
        vector<int> res(k);
        for (int i = k-1; i >=0 ; i--)
        {
            res[i] = q.top().first;
            q.pop();
        }
        
        return res;
    }
};
// @lc code=end

