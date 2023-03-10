/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
   int getHeight(TreeNode* n){
        if (n == nullptr)
        {
            return 0;
        }
        int lh = getHeight(n->left);
        int rh = getHeight(n->right);
        if (n->left == nullptr && n->right != nullptr)
        {
            /* code */
            return 1 + rh;
        }
        else if (n->left != nullptr && n->right == nullptr)
        {
            /* code */
            return 1 + lh;
        }
        return 1 + min(lh,rh);
        
    }
    int minDepth(TreeNode* root) {
        return getHeight(root);
    }
 
};
// @lc code=end

