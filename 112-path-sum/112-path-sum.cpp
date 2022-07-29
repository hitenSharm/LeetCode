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
    
    // bool traverse(TreeNode* root,int t,int curr)
    // {    
    //     if(!root)return false;
    //     curr+=root->val;
    //     if(!root->left and !root->right){
    //         if(curr==t)return true;
    //         return false;
    //     }
    //     return (traverse(root->left,t,curr) || traverse(root->right,t,curr));
    // }
    
    bool hasPathSum(TreeNode* root, int targetSum) {    
        if(!root)return false;
        
        targetSum-=root->val;
        if(!root->left and !root->right){
            if(targetSum==0)return true;
            return false;
        }
        return (hasPathSum(root->left,targetSum) || hasPathSum(root->right,targetSum));
    }
};