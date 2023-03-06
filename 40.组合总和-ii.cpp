/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void dfs(vector<int>& candidates, int target,int sum, int startIndex, vector<bool>& used){
        if (sum == target) {
            res.push_back(path);
            return;
        }
        for (size_t i = startIndex; i < candidates.size() &&  sum + candidates[i] <= target; i++)
        {
            if (i > 0 && candidates[i] == candidates[i -1] && used[i - 1] == false){
                continue;
            }
            
               sum += candidates[i];
               path.push_back(candidates[i]);
               used[i] = true;
               dfs(candidates,target,sum,i+1,used);
               used[i] = false;
               sum -= candidates[i];
               path.pop_back();
            
            
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(),false);
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0,0,used);
        return res;
    }
};
// @lc code=end

