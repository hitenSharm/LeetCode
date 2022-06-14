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
    map<pair<TreeNode*,int>,int>ump;
    int recu(TreeNode* r,int took)
    {
        if(!r)return 0;
        if(ump.find({r,took})!=ump.end())return ump[{r,took}];
        if(took==1)
        {
            return (recu(r->left,0)+recu(r->right,0));
        }
        int t1=r->val+recu(r->left,1)+recu(r->right,1);
        int t2=recu(r->left,0)+recu(r->right,0);
        return ump[{r,took}]=max(t1,t2);
    }
    int rob(TreeNode* root) {
        return recu(root,0);
    }
};