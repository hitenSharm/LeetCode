/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int fl=0;
    
    void recu(TreeNode* r,stack<TreeNode*>& qt,TreeNode* target)
    {
        if(fl==1 || !r)return ;
        if(r==target)fl=1;                 
        qt.push(r);
        recu(r->left,qt,target);        
        recu(r->right,qt,target);
        if(fl==0)qt.pop();
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        stack<TreeNode*>qt;
        recu(root,qt,target);
        vector<int>ans;
        TreeNode* prev=nullptr;
        int lvl=0;
        // while(!qt.empty())
        // {
        //     cout<<qt.top()->val<<endl;
        //     qt.pop();
        // }
        while(!qt.empty() and k-lvl>=0)
        {
            TreeNode* curr=qt.top();
            queue<TreeNode*>q;
            q.push(curr);
            int d=0;
            int goToDepth=k-lvl;
            while(!q.empty())
            {
                int len=q.size();
                for(int i=0;i<len;++i)
                {
                    TreeNode* tmp=q.front();q.pop();
                    if(tmp==prev || !tmp)continue ;
                    if(d==goToDepth)ans.push_back(tmp->val);
                    else
                    {
                        q.push(tmp->left);
                        q.push(tmp->right);
                    }                    
                }
                d++;
            }
            lvl++;
            prev=curr;
            qt.pop();
        }
        return ans;
    }
};