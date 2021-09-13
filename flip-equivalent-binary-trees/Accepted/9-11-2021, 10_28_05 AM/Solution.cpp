// https://leetcode.com/problems/flip-equivalent-binary-trees

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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 and !root2)return true;
        if(!root1 || !root2 || (root1->val!=root2->val))return false;  
        int r1R=(root1->right?root1->right->val:-1);
        int r2R=(root2->right?root2->right->val:-1);
        int r1L=(root1->left?root1->left->val:-1);
        int r2L=(root2->left?root2->left->val:-1);
        if(r1L==r2R and r1R==r2L)
        {
            return (flipEquiv(root1->left,root2->right)&&flipEquiv(root1->right,root2->left));
        }
        if(r1L==r2L and r1R==r2R)
        {
            return (flipEquiv(root1->left,root2->left)&&flipEquiv(root1->right,root2->right));
        }
        return false;
    }
};