// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

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
    
    map<int,int>mp;
    
    void lvlByLvl(TreeNode* root , int lvl)
    {
        if(!root)
        return ;
        
        int ld= (!root->left ? -1 : root->left->val);
        int rd= (!root->right ? -1 : root->right->val); 
        if(ld==-1 && rd!=-1)
            mp[lvl]+=rd;    
        if(ld!=-1 && rd==-1)
            mp[lvl]+=ld;   
        if(ld!=-1 &&rd !=-1)
            mp[lvl]+=ld+rd;
                      
        lvlByLvl(root->left,lvl+1);
        lvlByLvl(root->right,lvl+1);
        
    }

    int maxLevelSum(TreeNode* root) {
        int lvl=1;
        int m=root->val;
        int mlvl=1;
        mp[lvl]=m;
        lvlByLvl(root,lvl+1);
        
        for(auto it: mp)
        {
            if(m<it.second)
            {
                m=it.second;
                mlvl=it.first;
            }
        }
        
        return mlvl;
    }
};