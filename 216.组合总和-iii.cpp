/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(int target, int k, int sum, int startIndex){
        if (sum > target)
            return;
        if (path.size() == k)
        {                   
            if(target == sum){
            res.push_back(path);
            return;
            }      
        }
        //for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++)
        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++)
        {
            path.push_back(i);
            sum += i;
            dfs(target, k, sum, i+1);
            sum -= i;
            path.pop_back();
        }
        
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(n,k,0,1);
        return res;
    }
};
// @lc code=end

