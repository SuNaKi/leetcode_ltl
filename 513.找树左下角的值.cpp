/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int mdepth = INT_MIN;
    int res;
    void dfs(TreeNode* root,int depth){
        if (root->left == nullptr && root->right == nullptr)
        {
            if (depth > mdepth)
            {
                mdepth = depth;
                res = root->val;
            }
            
        }
        if (root->left)
        {
            dfs(root->left,depth + 1);
        }
         if (root->right)
        {
            dfs(root->right,depth + 1);
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root,0);
        return res;
    }
};
// @lc code=end

