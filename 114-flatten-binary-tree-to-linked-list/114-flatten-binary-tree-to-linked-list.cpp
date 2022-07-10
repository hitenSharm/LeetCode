class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)return ;
        flatten(root->left);
        flatten(root->right);
        if(root->left and root->right)
        {
        	TreeNode* temp=root->right;
        	root->right=root->left;     
        	TreeNode* curr=root->right;   	
        	while(curr->right)
        	{
        		curr=curr->right;
                curr->left=nullptr;
        	}
        	curr->right=temp;
            curr->left=nullptr;
            root->left=nullptr;
            return ;
        }
        if(root->left)
        {
        	root->right=root->left;
            root->left=nullptr;
        }
    }
};