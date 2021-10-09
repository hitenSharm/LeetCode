class Solution {
public:
    bool recu(TreeNode* root,TreeNode* subRoot)
    {
        if(!root || !subRoot)return (subRoot==NULL && root==NULL);
        
        if(root->val==subRoot->val)
        {
            return (recu(root->right,subRoot->right) && recu(root->left,subRoot->left));
        }
        else
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)return false;
        if(!subRoot)return true;
        if(recu(root,subRoot))return true;
        
        return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
        
    }
};