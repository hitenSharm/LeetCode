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
        TreeNode* temp=root->right;
        root->right=root->left;
        root->left=nullptr;
        TreeNode* iter=root;
        while(iter and iter->right){
            iter->left=nullptr;
            iter=iter->right;            
        }
        if(iter)
        iter->right=temp;
    }
};