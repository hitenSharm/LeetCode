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
    map<int,int>ump;
    
    void traverse(TreeNode* root,int curr)
    {
        if(!root)return ;
        ump[curr]=root->val;
        traverse(root->left,curr+1);
        traverse(root->right,curr+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        traverse(root,0);
        for(auto it:ump)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};