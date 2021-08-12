#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Solution {
public: 

    TreeNode* makeTree(ListNode* head,ListNode* tail)
    {
        if(head==tail)return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* mid;
        while(fast!=tail and fast->next!=tail)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        mid=slow;
        TreeNode* root = new TreeNode(mid->val);
        root->left=makeTree(head,mid);
        root->right=makeTree(mid->next,tail);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* tail=head;
        if(!head)return nullptr;
        while(tail)
        {
            tail=tail->next;
        }
        TreeNode* ans=makeTree(head,tail);
        return ans;
    }
};