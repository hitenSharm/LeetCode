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
    int ans = 0;

    void traverse(TreeNode* root,int res)
    {
        if (!root)return;

        res = res * 10 + root->val;

        if (!root->left and !root->right)
        {
            ans += res;
            return;
        }
        traverse(root->left, res);
        traverse(root->right, res);
    }

    int sumNumbers(TreeNode* root) {
        traverse(root,0);
        return ans;
    }
};