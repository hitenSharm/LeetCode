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
	
	int traverse(TreeNode* root)
	{
		if(!root)return 0;

		int lh=traverse(root->left);
		int rh=traverse(root->right);

		if(abs(lh-rh)>1){			
			return -10000;
		}
		return max(lh+1,rh+1);
	}

    bool isBalanced(TreeNode* root) {
        int ans = traverse(root);
        if(ans<0)return false;

        return true;
    }
};