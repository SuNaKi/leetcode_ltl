/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(int n, int k, int startIndex){
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; i++)
        {
            path.push_back(i);
            dfs(n, k, i+1);
            path.pop_back();
        }
        
        
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return res;
    }
};
// @lc code=end

