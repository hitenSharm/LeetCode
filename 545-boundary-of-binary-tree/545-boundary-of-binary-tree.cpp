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
    
    bool isLeaf(TreeNode* r)
    {
        if(!r->left and !r->right)return true;
        return false;
    }
    
    void leftTraverse(vector<int>& ans,TreeNode* r)
    {
        while(r)
        {
            if(!isLeaf(r))ans.push_back(r->val);
            if(r->left)r=r->left;
            else
                r=r->right;
        }
    }
    
    void addLeaves(TreeNode* r,vector<int>&ans)
    {
        if(!r)return ;
        if(isLeaf(r))ans.push_back(r->val);
        addLeaves(r->left,ans);
        addLeaves(r->right,ans);
    }
    
    void rightTraverse(TreeNode* r,vector<int>&ans)
    {
        //push in reverse here
        vector<int>temp;
        while(r)
        {
            if(!isLeaf(r))temp.push_back(r->val);
            if(r->right)
                r=r->right;
            else
                r=r->left;
        }
        reverse(temp.begin(),temp.end());
        for(auto i:temp)
            ans.push_back(i);
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int>ans;
        if(!isLeaf(root))
        ans.push_back(root->val);
        leftTraverse(ans,root->left);
        addLeaves(root,ans);
        rightTraverse(root->right,ans);
        return ans;
    }
};