/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool dfs(TreeNode* root, int targetSum) {
        if (root->left == nullptr && root->right == nullptr && targetSum == 0)
        {
            /* code */
            return true;
        }
         if (root->left == nullptr && root->right == nullptr && targetSum != 0)
        {
            /* code */
            return false;
        }
        if (root->left)
        {
            /* code */
            bool r = dfs(root->left, targetSum - root->left->val);
            if (r)
            {
                return true;
            }
            
        }
          if (root->right)
        {
            /* code */
            bool r = dfs(root->right, targetSum - root->right->val);
            if (r)
            {
                return true;
            }
        }
        
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
        {
            return false;
        }
        return dfs(root, targetSum - root->val);
    }
};
// @lc code=end

