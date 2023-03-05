/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs (vector<int>& candidates, int target, int sum, int starIndex){
        if (sum > target)
        {
            /* code */return;
        }else if (sum == target)
        {
            /* code */res.push_back(path);
            return;
        }
        for (size_t i = starIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
            /* code */path.push_back(candidates[i]);
            sum += candidates[i];
            dfs(candidates,target,sum,i);
            sum -= candidates[i];
            path.pop_back();
        }
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates,target,0,0);  
        return res;
    }
};
// @lc code=end

