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
    string str;
    bool ans=false;
    
    string compare(TreeNode* r)
    {
        if(!r)return "@";
        string l=compare(r->left);
        string ryt=compare(r->right);
        string curr=to_string(r->val)+l+ryt;
        if(curr==str)ans=true;
        return curr;
    }
    
    string makeString(TreeNode* r)
    {
        if(!r)return "@";
        string l=makeString(r->left);
        string ryt=makeString(r->right);
        return to_string(r->val)+l+ryt;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        str=makeString(subRoot);
        //cout<<str;
        string s=compare(root);
        if(s==str)ans=true;
        return ans;
    }
};