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
    
    TreeNode* makeTree(vector<int>& nums,int l,int r)
    {
        if(l>r)return nullptr;
        if(l==r)return (new TreeNode(nums[l]));
        int m=l+(r-l)/2;
        TreeNode* root=new TreeNode(nums[m]);
        root->left=makeTree(nums,l,m-1);
        root->right=makeTree(nums,m+1,r);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {        
        TreeNode* root=makeTree(nums,0,nums.size()-1);
        
        return root;
    }
};