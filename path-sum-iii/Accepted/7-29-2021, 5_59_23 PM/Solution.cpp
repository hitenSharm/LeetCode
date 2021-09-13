// https://leetcode.com/problems/path-sum-iii

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
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
    
    int getVals(TreeNode* root,int& target,int value)
    {
        if(!root)return 0;
        value=value+root->val;
        if(value==target)
        {
            return (1+getVals(root->left,target,value)+getVals(root->right,target,value));
        }
        
        return (getVals(root->left,target,value)+getVals(root->right,target,value));
    }
    
    int solve(TreeNode* root,int& target)
    {
        if(!root) return 0;
        int ans=0;
        ans=ans+getVals(root,target,0);
        ans=ans+solve(root->left,target);
        ans=ans+solve(root->right,target);
        return ans;
    }
    
    int pathSum(TreeNode* root, int sum) {
        int cnt=0;
        cnt=solve(root,sum);
        return cnt;
    }
};