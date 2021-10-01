class Solution {
public:
    long long mod=1000000007;
    long long sumTree(TreeNode* root)
    {
        if(!root)return 0;
        root->val=root->val+sumTree(root->left)+sumTree(root->right);
        return root->val;
    }
    
    void inorder(TreeNode* root,long long& ans,long long& s)
    {
        if(!root)return ;
        if(root->left)
        {
            ans=max(ans,((s-root->left->val)*root->left->val));
        }
        if(root->right)
        {
            ans=max(ans,((s-root->right->val)*root->right->val));
        }
        inorder(root->left,ans,s);
        inorder(root->right,ans,s);
    }
    
    long long maxProduct(TreeNode* root) {
        long long s = sumTree(root);
        long long ans=0;
        inorder(root,ans,s);
        return ans%mod;
    }
};