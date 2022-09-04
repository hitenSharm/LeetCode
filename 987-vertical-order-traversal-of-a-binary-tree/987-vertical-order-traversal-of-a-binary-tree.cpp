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
    
    void insertInMap(unordered_map<int,multiset<int>>& tmp,map<int,vector<int>>& mp)
    {
        for(auto it:tmp)
        {
            multiset<int>& temp=it.second;
            for(auto itr:temp)
                mp[it.first].push_back(itr);
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});
        map<int,vector<int>>mp;
        while(!q.empty())
        {
            int len=q.size();
            unordered_map<int,multiset<int>>tmp;
            while(len--)
            {
                pair<int,TreeNode*>p=q.front();
                q.pop();            
                if(p.second->left)q.push({p.first-1,p.second->left});
                if(p.second->right)q.push({p.first+1,p.second->right});
                tmp[p.first].insert(p.second->val);//level and line sorting
            }
            insertInMap(tmp,mp);
        }
        vector<vector<int>> ans;        
        for(auto it:mp)
        {                      
            ans.push_back(it.second);
        }
        return ans;
    }
};