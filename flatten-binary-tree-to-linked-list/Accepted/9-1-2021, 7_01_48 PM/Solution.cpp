// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

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

    void flatten(TreeNode* root) {
        if(!root)return ;          
        flatten(root->left);
        flatten(root->right);
        if(root->left and root->right)
        {            
            TreeNode* temp=root->right;            
            root->right=root->left;            
            TreeNode* t2=root->right;
            while(t2->right)
            {
                t2=t2->right;
                t2->left=nullptr;
            }
            t2->right=temp;
            t2->left=nullptr;
            root->left=nullptr;            
        }
        else if(root->left)
        {
            root->right=root->left;
            root->left=nullptr;
        }
        
    }
};