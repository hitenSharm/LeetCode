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
    vector<int>ans;
    int maxDepth=-1;
    void traverse(TreeNode* r,int d)
    {
        if(!r)return ;
        if(d>maxDepth){
            maxDepth=d;
            ans.push_back(INT_MIN);
        }
        ans[d]=max(ans[d],r->val);
        traverse(r->left,d+1);
        traverse(r->right,d+1);
    }
    
    vector<int> largestValues(TreeNode* root) {
        traverse(root,0);
        return ans;
    }
};