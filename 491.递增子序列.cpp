/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int> &nums, int startIndex)
    {
        if (path.size() > 1)
        {
            res.push_back(path);
        }
        unordered_set<int> uset;
        for (size_t i = startIndex; i < nums.size(); i++)
        {
            if ((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end())
            {
                continue;
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        dfs(nums, 0);
        return res;
    }
};
// @lc code=end
