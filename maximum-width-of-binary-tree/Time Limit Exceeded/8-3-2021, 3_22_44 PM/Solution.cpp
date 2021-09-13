// https://leetcode.com/problems/maximum-width-of-binary-tree

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

    int level(TreeNode* root)
    {
        if(!root)return 0;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty())
        {
            int len=q.size();
            for(int i=0;i<len;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            level++;
        }
        return level;
    }
    
    int cntVal(vector<int>& arr)
    {
        int i=0,j=arr.size()-1;
        
        while(arr[i]==-101)
        i++;
        
        while(arr[j]==-101)
        j--;
        
        return (j-i+1);
    }

    int widthOfBinaryTree(TreeNode* root) {
        vector<int>arr;
        queue<TreeNode*>q;
        q.push(root);
        int lvl=0;
        int h=level(root);
        int maxi=0;        
        while(!q.empty() and lvl<h)
        {
            int len=q.size();
            vector<int>arr;
            for(int i=0;i<len;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(!temp)
                {
                    arr.push_back(-101);
                    q.push(nullptr);
                    q.push(nullptr);
                    continue ;
                }
                arr.push_back(temp->val);
                if(!temp->left)q.push(nullptr);
                if(temp->left)q.push(temp->left);
                if(!temp->right)q.push(nullptr);
                if(temp->right)q.push(temp->right);
            }
            maxi=max(maxi,cntVal(arr));
            lvl++;
        }
        return maxi;
    }
};