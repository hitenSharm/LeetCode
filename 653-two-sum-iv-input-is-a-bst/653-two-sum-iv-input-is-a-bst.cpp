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
    stack<TreeNode*>stl;
    stack<TreeNode*>str;
    
    void init(TreeNode* root)
    {
        TreeNode* temp=root;
        while(temp){
            stl.push(temp);
            temp=temp->left;
        }
        temp=root;
        while(temp)
        {
            str.push(temp);
            temp=temp->right;
        }
    }
    
    void moveNext()
    {
        TreeNode* temp=stl.top();
        stl.pop();
        temp=temp->right;
        while(temp)
        {
            stl.push(temp);
            temp=temp->left;
        }
    }
    void moveBack()
    {
        TreeNode* temp=str.top();
        str.pop();
        temp=temp->left;
        while(temp)
        {
            str.push(temp);
            temp=temp->right;
        }
    }  
    
    bool findTarget(TreeNode* root, int k) {
        //o(n) & o(n) is obvious
        //o(n) & o(h) space using bst iterator is better
        init(root);
        while(stl.top()!=str.top())
        {
            if(stl.top()->val+str.top()->val==k){
                return true;
            }
            if(stl.top()->val+str.top()->val<k){
                moveNext();
            }
            else
                moveBack();
        }
        return false;
    }
};