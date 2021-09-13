// https://leetcode.com/problems/subtree-of-another-tree

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
    
    bool inorder(TreeNode* root,TreeNode* subRoot,TreeNode* ogsub)
    {
        if(!root and !subRoot)return true;
        if(!root || !subRoot)return false;
        if(root->val==subRoot->val)
        {
            return (inorder(root->left,subRoot->left,ogsub) and inorder(root->right,subRoot->right,ogsub));
        }
        return (inorder(root->left,ogsub,ogsub) || inorder(root->right,ogsub,ogsub));
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return inorder(root,subRoot,subRoot);
    }
};