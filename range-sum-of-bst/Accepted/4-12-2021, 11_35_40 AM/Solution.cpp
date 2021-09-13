// https://leetcode.com/problems/range-sum-of-bst

class Solution {
public:
    

    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
        int ans=0;
        if(root->val<low)
          return ans+=rangeSumBST(root->right,low,high);
        if(root->val>high)
           return ans+=rangeSumBST(root->left,low,high);
        return ans=ans+root->val+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
    }
};