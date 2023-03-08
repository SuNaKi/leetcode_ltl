/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int> &nums, vector<bool> &used)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (used[i] == true)
            {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        dfs(nums, used);
        return res;
    }
};
// @lc code=end
