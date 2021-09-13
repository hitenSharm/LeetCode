// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

void preorder(TreeNode* root, map<int,int>&mp, int level)
{
    if(root==NULL) return;
    level++;
    if(mp.count(level)==0)// first time
    mp[level]=root->val;
    else    
    mp[level]+=root->val;
    
    preorder(root->left,mp,level);
    preorder(root->right,mp,level);
}


class Solution {
public:
   int maxLevelSum(TreeNode* root) {
        if(root==NULL) return 0;
        map<int,int>mp; // the key store the level and the value stores the sum at
                            // that level
       int level=0; 
       preorder(root,mp,level);
       
       int ans;
       int maxa=INT_MIN;
       for(auto x: mp)
       {
           if(x.second>maxa)
           {
               maxa=x.second;
               ans=x.first;
           }
       }
       
       return ans;
      
    }
};