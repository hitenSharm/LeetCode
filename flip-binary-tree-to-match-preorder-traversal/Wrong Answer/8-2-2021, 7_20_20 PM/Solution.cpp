// https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal

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

    int index=0;

    void dfs(TreeNode* root,TreeNode* parent,vector<int>& ans,vector<int>& path)
    {
        if(index>=path.size() || !root)return ;        
        if(path[index]==root->val)
        {
            index++;
            dfs(root->left,root,ans,path);
            dfs(root->right,root,ans,path);
        }
        else
        {
            if(!parent)
            {
                ans.push_back(-1);
                return ;
            }
            else
            {
                if(ans.size()>0 and ans[ans.size()-1]==parent->val)
                {
                    ans.clear();
                    ans.push_back(-1);
                    return ;
                }
                else
                {
                    ans.push_back(parent->val);                    
                    TreeNode* temp=parent->left;
                    parent->left=parent->right;
                    parent->right=temp;                                         
                    index--;
                    dfs(parent,parent,ans,path);
                }
            }
        }
    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int>ans;
        dfs(root,nullptr,ans,voyage);
        return ans;
    }
};