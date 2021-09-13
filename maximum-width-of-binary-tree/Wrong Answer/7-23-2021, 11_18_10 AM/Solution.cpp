// https://leetcode.com/problems/maximum-width-of-binary-tree

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
    int widthOfBinaryTree(TreeNode* root) {
        queue<TreeNode*>q;
        int ans=1;
        q.push(root);
        while(!q.empty())
        {
            int len=q.size();
            int nonCnt=0;
            int normCnt=0;            
            for(int i=0;i<len;i++)
            {
                TreeNode* temp=q.front();                
                q.pop();
                if(temp->val==101)nonCnt++;
                if(temp->val!=101)normCnt++;
                if(normCnt>1 and temp->val!=101)
                {                    
                    normCnt+=nonCnt;
                    nonCnt=0;
                }
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                if(temp->left==NULL)
                {
                    TreeNode* t2=new TreeNode(101);
                    q.push(t2);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }                
                if(temp->right==NULL)
                {
                    TreeNode* t3=new TreeNode(101);
                    q.push(t3);
                }
            }
            if(normCnt==0 and nonCnt>0)break;
            ans=max(ans,normCnt);
        }
        return ans;
    }
};