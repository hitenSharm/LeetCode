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

    bool recu(long long mini,long long maxi,TreeNode* r)
    {
        if(!r)return true;
        if(r->val<maxi and r->val>mini)
        {
            return (recu(mini,r->val,r->left) && recu(r->val,maxi,r->right));
        }
        return false;
    }

    bool isValidBST(TreeNode* root) {
        if(!root)return true;        
        return (recu(LLONG_MIN,root->val,root->left) && recu(root->val,LLONG_MAX,root->right));
    }
};