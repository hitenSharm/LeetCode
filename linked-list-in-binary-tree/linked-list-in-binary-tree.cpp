class Solution {
public:
    
    bool isSame(TreeNode* root,ListNode* head)
    {
        if(!head->next)return true;
        if(!root)return false;
        bool ans=false;
        if(root->left and root->left->val==head->next->val)ans=ans||isSame(root->left,head->next);
        if(root->right and root->right->val==head->next->val)ans=ans||isSame(root->right,head->next);
        return ans;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head)return true;
        if(!root)return false;
        bool ans=false;
        if(root->val==head->val)ans=ans||(isSame(root,head));
        if(ans)return ans;
        ans=ans||(isSubPath(head,root->left) || isSubPath(head,root->right));
        return ans;
        
    }
};