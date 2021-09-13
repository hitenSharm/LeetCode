// https://leetcode.com/problems/maximum-depth-of-binary-tree

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
    int maxi=1;
    void recu(TreeNode* root,int d)
    {
        if(!root)
        {
            maxi=max(maxi,d);
            return ;            
        }
        recu(root->left,d+1);
        recu(root->right,d+1);
    }
    int maxDepth(TreeNode* root) {
        recu(root,0);
        if(!root)maxi=0;
        return maxi;
    }
};