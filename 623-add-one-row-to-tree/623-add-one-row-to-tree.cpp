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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* newVal=new TreeNode(val);
            newVal->left=root;
            return newVal;
        }
        int d=1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty() and d!=depth)
        {
            int len=q.size();
            for(int i=0;i<len;++i)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(!curr)continue;
                if(d==depth-1)
                {
                    TreeNode* newValLeft=new TreeNode(val);
                    TreeNode* newValRight=new TreeNode(val);
                    TreeNode* realChildLeft=curr->left;
                    TreeNode* realChildRight=curr->right;
                    curr->left=newValLeft;
                    curr->right=newValRight;
                    newValLeft->left=realChildLeft;
                    newValRight->right=realChildRight;
                }
                else
                {
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
            d++;
        }
        return root;
    }
};