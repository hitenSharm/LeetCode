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

    bool recu(TreeNode* r1,TreeNode* r2)
    {
        if(!r1 and !r2)return true;
        if(!r1 || !r2 || r1->val!=r2->val)return false;
        return (recu(r1->left,r2->right) && recu(r1->right,r2->left));
    }

    bool isSymmetric(TreeNode* root) {
        return recu(root->left,root->right);
    }
};