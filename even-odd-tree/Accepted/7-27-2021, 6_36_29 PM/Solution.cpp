// https://leetcode.com/problems/even-odd-tree

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
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
    bool isEvenOddTree(TreeNode* root) {
        if(!root)return true;
        int lvl=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int curr=0;
            if(lvl%2!=0)curr=INT_MAX;
            int len=q.size();
            for(int i=0;i<len;i++)
            {
                TreeNode* temp=q.front();q.pop();
                if(lvl%2==0)
                {
                    if(temp->val%2==0 || temp->val<=curr)return false;
                    curr=temp->val;
                    if(temp->left)q.push(temp->left);
                    if(temp->right)q.push(temp->right);
                }
                else
                {
                    if(temp->val%2!=0 || temp->val>=curr)return false;
                    curr=temp->val;
                    if(temp->left)q.push(temp->left);
                    if(temp->right)q.push(temp->right);
                }
            }
            lvl++;
        }
        return true;
    }
};