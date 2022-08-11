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
    int index = 0;

    TreeNode* makeTree(int mini, int maxi, vector<int>& preorder)
    {
        if (index>=preorder.size() || preorder[index]<mini || preorder[index]>maxi)return nullptr;//out of range of valid bst
        TreeNode* root = new TreeNode(preorder[index]);
        index++;
        root->left = makeTree(mini, root->val, preorder);
        root->right = makeTree(root->val, maxi, preorder);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        TreeNode* root = new TreeNode(preorder[index]);
        index++;
        root->left = makeTree(mini, root->val, preorder);
        root->right = makeTree(root->val, maxi, preorder);

        return root;
    }
};