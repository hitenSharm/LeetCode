// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree

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
    int maxi=0;
    void traverse(TreeNode* root)
    {
        if(!root)return ;
        traverse(root->right);
        maxi+=root->val;
        root->val=maxi;
        traverse(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);
        return root;
    }
};