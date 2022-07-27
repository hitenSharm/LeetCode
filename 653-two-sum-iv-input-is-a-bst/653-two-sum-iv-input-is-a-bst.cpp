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
    
    stack<TreeNode*>sti;
    stack<TreeNode*>stj;
    
    void initialise(TreeNode* root)
    {
        TreeNode* temp=root;
        while(temp){
            sti.push(temp);
            temp=temp->left;
        }
        temp=root;
        while(temp){
            stj.push(temp);
            temp=temp->right;//this is to get the reverse inorder array 
        }
    }
    
    void moveNext()
    {
        if(sti.empty())return ;
        TreeNode* temp=sti.top();
        sti.pop();
        if(temp->right){
            temp=temp->right;
            while(temp){
                sti.push(temp);
                temp=temp->left;
            }
        }        
    }
    
    void moveBack()
    {
        if(stj.empty())return ;
        TreeNode* temp=stj.top();
        stj.pop();
        if(temp->left){
            temp=temp->left;
            while(temp){
                stj.push(temp);
                temp=temp->right;
            }
        }
    }
    
    bool findTarget(TreeNode* root, int k) {
       //to do in o(n) and o(h) make next and before using stacks like in bst iterator 
        initialise(root);
        while(!sti.empty() and !stj.empty() and sti.top()!=stj.top())
        {
            if(sti.top()->val+stj.top()->val<k){
                moveNext();
            }else if(sti.top()->val+stj.top()->val>k){
                moveBack();
            }else if(sti.top()->val+stj.top()->val==k)
                return true;
        }
        return false;
    }
};