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
    
    int ans=0;
    
    vector<int> path(TreeNode* root)
    {
        if(!root)
            return {0,0};//inc,dec
        //at each node i stroe the lingest inc below me and the longest dec below me
        int inc=1,dec=1;
        if(root->left)
        {
            vector<int>l=path(root->left);//left vector
            if(root->val == root->left->val+1)//dec seq
            {
                dec=l[1]+1;
            }
            else if(root->val==root->left->val-1)//inc seq on the lef
            {
                inc=l[0]+1;
            }
        }
        if(root->right)
        {
            vector<int>r=path(root->right);//left vector
            if(root->val == root->right->val+1)//dec seq
            {
                dec=max(dec,r[1]+1);
            }
            else if(root->val==root->right->val-1)//inc seq on the lef
            {
                inc=max(inc,r[0]+1);
            }
        }
        ans=max(ans,inc+dec-1);
        return {inc,dec};
    }
    
    int longestConsecutive(TreeNode* root) {
        path(root);
        return ans;
    }
};