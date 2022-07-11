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
    unordered_map<int,int>ump;
    
    TreeNode* builder(vector<int>& preorder,vector<int>& inorder,int preStart,int preEnd,int inStart,int inEnd)
    {
        if(preStart > preEnd || inStart>inEnd)return nullptr;
        
        TreeNode* newRoot=new TreeNode(preorder[preStart]);
        int inIndex=ump[preorder[preStart]];//where does it lie on the inorder array
        int numsOnLeft = inIndex-inStart;
        
        newRoot->left=builder(preorder,inorder,preStart+1,preStart+numsOnLeft,inStart,inIndex-1);
        newRoot->right=builder(preorder,inorder,preStart+numsOnLeft+1,preEnd,inIndex+1,inEnd);
        
        return newRoot;
    }
    //pre is root left right and in is left root ritgh
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)ump[inorder[i]]=i;
        
        TreeNode* root= builder(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
        return root;
    }
};