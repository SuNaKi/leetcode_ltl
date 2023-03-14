/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return nums.size();
        }
        int curD = 0;
        int preD = 0;
        int res = 1;
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            curD = nums[i + 1] - nums[i];
            if ((curD > 0 && preD <= 0) || (preD >= 0 &&
                                            curD < 0))
            {
                res++;
                preD = curD;
            }
        }
        return res;
    }
};
// @lc code=end
