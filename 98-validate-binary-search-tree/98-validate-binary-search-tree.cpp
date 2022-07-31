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
    bool isValidBST(TreeNode* root) {
        bool ans=true;
        long long curr=LLONG_MIN;
        while(root)
        {
            if(!root->left)
            {
                if(root->val<=curr)ans=false;
                curr=root->val;
                root=root->right;
            }
            else
            {
                TreeNode* temp=root->left;
                while(temp->right and temp->right!=root)
                {
                    temp=temp->right;
                }
                if(!temp->right)
                {
                    temp->right=root;
                    root=root->left;
                }
                else
                {
                    temp->right=nullptr;
                    if(root->val<=curr)ans=false;
                    curr=root->val;
                    root=root->right;
                }
            }
        }
        return ans;
    }
};