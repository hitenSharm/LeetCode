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
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        int lastElement = -1;
        while (root)
        {
            if (!root->left)
            {
                if (lastElement == -1)lastElement = root->val;
                else
                {
                    ans = min(ans, abs(lastElement - root->val));
                }
                lastElement = root->val;
                root = root->right;
            }
            else
            {
                TreeNode* temp = root->left;
                while (temp->right and temp->right != root)
                {
                    temp = temp->right;
                }
                if (temp->right == root)
                {
                    //connection exists
                    temp->right = nullptr;
                    //inorder part
                    if (lastElement == -1)lastElement = root->val;
                    else
                    {
                        ans = min(ans, abs(lastElement - root->val));
                    }
                    lastElement = root->val;
                    root = root->right;
                }
                else
                {
                    temp->right = root;
                    root = root->left;
                }
            }
        }
        return ans;
    }
};