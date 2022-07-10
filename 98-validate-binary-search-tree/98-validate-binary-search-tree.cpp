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

	bool recu(TreeNode* root,long long mini,long long maxi)
	{
		if(!root)return true;        
		if(root->val>mini and root->val<maxi)
		{            
			return (recu(root->left,mini,root->val) and recu(root->right,root->val,maxi));
		}
		else
			return false;
	}

    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        return (recu(root->left,LLONG_MIN,root->val) and recu(root->right,root->val,LLONG_MAX));
    }
};