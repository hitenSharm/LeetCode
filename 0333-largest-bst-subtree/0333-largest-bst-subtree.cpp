class Solution {
public:

    vector<int> traverse(TreeNode* root)
    {
        if(!root)
        {
            return {0,INT_MAX,INT_MIN};
        }
        vector<int>l=traverse(root->left);
        vector<int>r=traverse(root->right);
        //left ka max se bda and ryt ke min se chota
        
        if(root->val>l[2] and root->val<r[1])
        {
            int nodes=l[0]+r[0]+1;
            int mini=max(root->val,r[2]);
            int maxi=min(root->val,l[1]);
            return {nodes,maxi,mini};
        }
        return {max(l[0],r[0]),INT_MIN,INT_MAX};
    }

    int largestBSTSubtree(TreeNode* root) {
        vector<int>ans=traverse(root);
        return ans[0];
    }
};