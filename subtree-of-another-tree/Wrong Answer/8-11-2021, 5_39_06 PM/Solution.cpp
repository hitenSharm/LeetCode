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
    
    void inorder(TreeNode* root,string& s)
    {
        if(!root)return ;
        inorder(root->left,s);
        s.push_back(root->val);
        inorder(root->right,s);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s1="";
        inorder(root,s1);
        string s2="";
        inorder(subRoot,s2);
        if(s1.find(s2)!=string::npos)
        {
            return true;
        }
        return false;
    }
};