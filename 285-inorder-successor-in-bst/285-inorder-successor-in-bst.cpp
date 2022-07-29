/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        //brute force methods hai
        TreeNode* ans=nullptr;
        //inorder succ is a node that is just greater than target node
        //so any value less than it is not the ans 
        //the last value that u can visits that is greater than it is the answer(cant be equalt to node p)
        
        while(root)
        {
            if(root->val<=p->val)//means inorder traversal mein uske peeche hoga
            {
                root=root->right;
            }
            else
            {
                ans=root;
                root=root->left;
            }
        }
        return ans;
        
    }
};