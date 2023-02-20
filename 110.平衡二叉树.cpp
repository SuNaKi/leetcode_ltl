/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int getH(TreeNode* root){
        if (nullptr == root) return 0;
        
        int lh = 0, rh = 0;
        lh = getH(root->left);
        if (-1 == lh) return -1;
        
        rh = getH(root->right);
        if (-1 == rh) return -1;

        if (abs(rh - lh) > 1) return -1;
        else return 1 + max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        int h = getH(root);
        if (-1 == h)
        {
            return false;
        }
        return true;
        
    }
};
// @lc code=end

