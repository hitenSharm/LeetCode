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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,1});
        unsigned long long ans=0;
        while(!q.empty())
        {
            unsigned long long len=q.size();
            unsigned long long mini=q.front().second;
            unsigned long long maxi;
            while(len--)
            {
                pair<TreeNode*,unsigned long long>p=q.front();
                q.pop();                                             
                maxi=p.second;
                if(p.first->left)
                q.push({p.first->left,2*p.second});
                if(p.first->right)
                q.push({p.first->right,(2*p.second)+1});
                ans=max(maxi-mini+1,ans);
            }                      
        }
        return ans;
    }
};