class Solution {
public:
    int fl=0;
	int recu(TreeNode* root)
	{
		if(!root || fl==1)return 0;
		int l=1+recu(root->left);
		int r=1+recu(root->right);
		if(abs(l-r)>1)fl=1;
		return max(l,r);
	}

    bool isBalanced(TreeNode* root) {
        recu(root);
		if(fl==1)return false;
		return true;
    }
};