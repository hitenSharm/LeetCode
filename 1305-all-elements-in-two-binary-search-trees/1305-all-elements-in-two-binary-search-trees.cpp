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
    vector<int>t1;
    vector<int>t2;
    void traverse(TreeNode* r,int fl)
    {
        if(!r)return ;
        traverse(r->left,fl);
        fl == 1 ? t1.push_back(r->val) : t2.push_back(r->val);
        traverse(r->right,fl);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        traverse(root1,1);
        traverse(root2,2);
        vector<int>ans;
        int i=0,j=0;
        while(i<t1.size() and j<t2.size())
        {
            if(t1[i]<t2[j])
            {
                ans.push_back(t1[i]);
                i++;
            }
            else if(t1[i]>t2[j])
            {
                ans.push_back(t2[j]);
                j++;
            }
            else if(t1[i]==t2[j])
            {
                ans.push_back(t1[i]);
                ans.push_back(t1[i]);
                i++;j++;
            }
        }
        while(i<t1.size())
        {
            ans.push_back(t1[i]);
            i++;
        }
        while(j<t2.size())
        {
            ans.push_back(t2[j]);
            j++;
        }
        return ans;
    }
};