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
    
    TreeNode* makeTree(int l,int r,int& index,vector<int>&preorder)
    {
        if(l>r || r<0)return nullptr;
        if(l==r)
        {
            return new TreeNode(preorder[index++]);
        }
        TreeNode* node=new TreeNode(preorder[index]);
        //generate a new range
        int indexInorder=ump[preorder[index]];
        index++;
        node->left=makeTree(l,indexInorder-1,index,preorder);
        node->right=makeTree(indexInorder+1,r,index,preorder);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int l=0;
        int r=inorder.size()-1;
        int index=0;        
        
        for(int i=0;i<inorder.size();i++)
            ump[inorder[i]]=i;
        
        return makeTree(l,r,index,preorder);
    }
};