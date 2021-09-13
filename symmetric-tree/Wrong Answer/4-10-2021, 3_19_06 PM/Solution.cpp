// https://leetcode.com/problems/symmetric-tree

class Solution {
public:
    
    void makeTaverse(TreeNode* root,string &s)
    {
        if(!root)
        {
            int data;            
            s+=to_string(data);
            return ;
        }
        
        makeTaverse(root->left,s);
        
        int data=root->val;
        if(!root)
            data=101;
        s+=to_string(data);
        
        makeTaverse(root->right,s);
    }

    bool isSymmetric(TreeNode* root) {
        string s="";
        makeTaverse(root,s);
        //cout<<s;
        for(int i=0;i<s.length()/2;i++){
            if(s[i]!=s[s.length()-1-i])
            return false;
        }
        
        return true;
    }
};