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
        int curr;
        //inorder traversal mein bst is sorted so if we do a morris traversal we can get linear time
        //constant space
        bool ans=true;
        bool init=false;
        while(root)
        {
            if(!root->left)
            {
                if(root->val<=curr and init)ans=false;
                curr=root->val;
                if(!init)init=true;
                root=root->right;                
            }
            else
            {
                TreeNode* temp=root->left;
                while(temp->right and temp->right!=root)
                {
                    temp=temp->right;
                }
                if(temp->right==root)
                {
                    temp->right=nullptr;
                    if(root->val<=curr and init)ans = false;
                    curr=root->val;
                    if(!init)init=true;
                    root=root->right;
                }
                else
                {
                    temp->right=root;
                    root=root->left;
                }
            }            
        }
        return ans;
    }
};