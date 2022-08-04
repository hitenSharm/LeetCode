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
    
    vector<vector<int>> ans;
    
    int traverse(TreeNode* root)
    {
        //base case is leaf node
        if(!root)return 0;
        if(!root->left and !root->right)
        {
            if(ans.size()==0)ans.push_back({root->val});
            else
                ans[0].push_back(root->val);
            
            return 1;
        }
        
        int leftVal=traverse(root->left);
        int rytVal=traverse(root->right);
        int levelValue=max(leftVal,rytVal);
        
        if(ans.size()<=levelValue)ans.push_back({root->val});
        else
            ans[levelValue].push_back(root->val);
        
        return levelValue+1;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {        
        traverse(root);
        return ans;
    }
};