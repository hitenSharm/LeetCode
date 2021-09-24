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

    void traverse(TreeNode* root,int& val)
    {
        if(root->left and root->val>val)
        {
            traverse(root->left,val);
        }
        if(root->right and root->val<val)
        {
            traverse(root->right,val);
        }
        if(!root->left and root->val>val)
        {
            TreeNode* tmp=new TreeNode(val);
            root->left=tmp;
            return ;
        }
        if(!root->right and root->val<val)
        {
            TreeNode* tmp=new TreeNode(val);
            root->right=tmp;
            return ;
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)return (new TreeNode(val));
        traverse(root,val);
        return root;
    }
};