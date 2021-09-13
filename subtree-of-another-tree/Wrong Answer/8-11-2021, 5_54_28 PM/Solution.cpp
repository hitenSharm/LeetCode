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
    
    bool isSame(TreeNode* s,TreeNode*t)
    {
        if(!s and !t)return true;
        if(!s || !t)return false;
        return (s->val==t->val) and (inorder(s->left,t->left) and inorder(s->right,t->right));
    }
    
    bool inorder(TreeNode* root,TreeNode* subRoot)
    {
        if(!subRoot and !root)return true;
        if(!root || !subRoot)return false;
        return isSame(root,subRoot)||(inorder(root->left,subRoot) || inorder(root->right,subRoot));
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return inorder(root,subRoot);
    }
};