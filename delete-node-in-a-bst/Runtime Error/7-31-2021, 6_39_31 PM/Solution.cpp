// https://leetcode.com/problems/delete-node-in-a-bst

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

    void deletion(TreeNode* root,TreeNode* parent)
    {
        if(!root->left and !root->right)
        {
            if(parent->left==root)parent->left=nullptr;
            if(parent->right==root)parent->right=nullptr;
            return ;
        }
        if(!root->left)
        {
            if(parent->left==root)parent->left=root->right;
            if(parent->right==root)parent->right=root->right;
            return ;
        }
        if(!root->right)
        {
            if(parent->left==root)parent->left=root->left;
            if(parent->right==root)parent->right=root->left;
            return ;
        }
        if(parent->left==root)
        {
            TreeNode* temp=root;
            parent->left=temp->right;
            root=parent->left;
            root->left=temp->left;
            return ;
        }
        if(parent->right==root)
        {
            TreeNode* temp=root;
            parent->right=temp->right;
            root=parent->right;
            root->right=temp->right;
            return ;
        }
    }

    bool search(TreeNode* root,TreeNode* parent,int& key)
    {
        if(!root)return false;
        if(root->val==key)
        {
            deletion(root,parent);
            return true;
        }
        if(root->val>key)
        {
            search(root->left,root,key);
        }
        if(root->val<key)
        {
            search(root->right,root,key);
        }
        return false;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        search(root,nullptr,key);
        return root;
    }
};