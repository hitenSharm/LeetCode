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
    int index=0;
    TreeNode* makeTree(vector<int>& preorder,int ub)
    {
        if(index>=preorder.size() || preorder[index]>=ub)return nullptr;
        TreeNode* root=new TreeNode(preorder[index]);
        index++;
        root->left=makeTree(preorder,preorder[index-1]);
        root->right=makeTree(preorder,ub);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {        
        int ub=INT_MAX;
        return makeTree(preorder,ub);
    }
};