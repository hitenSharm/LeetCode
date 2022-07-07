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

	int traverse(TreeNode* root,int& ans)
	{
		if(!root)return 0;
		int l=traverse(root->left,ans);
		int r=traverse(root->right,ans);        
		ans=max(ans,l+r);
		return max(l+1,r+1);
	}

    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        traverse(root,ans);
        return ans;
    }
};