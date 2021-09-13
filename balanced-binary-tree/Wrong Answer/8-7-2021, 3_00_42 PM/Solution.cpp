// https://leetcode.com/problems/balanced-binary-tree

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
    
    int lvlOrder(TreeNode* root)
    {
        if(!root)return 1;
        int level=1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int len=q.size();
            for(int i=0;i<len;i++)
            {
                TreeNode* temp=q.front();q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            level++;
        }
        return level;
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        int left=lvlOrder(root->left);
        int ryt=lvlOrder(root->right);
        if(abs(left-ryt)<=1)return true;
        
        return false;
    }
};