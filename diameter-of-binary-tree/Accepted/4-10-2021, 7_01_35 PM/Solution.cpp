// https://leetcode.com/problems/diameter-of-binary-tree

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
    
    int switchNodes(TreeNode* root,int &d)
    {
        if(!root)
        {
          return 0;   
        }
        int ld=switchNodes(root->left,d);
        int rd=switchNodes(root->right,d);
        
        d=max(ld+rd,d);
        
        return max(ld+1,rd+1);
        
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        int ans=switchNodes(root,d);
        return d;
    }
};