// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

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

    TreeNode* makeTree(vector<int>& arr,int l,int r)
    {
        if(l>r || l<0 || r>=arr.size())return NULL;
        int m=l+(r-l)/2;
        TreeNode* root=new TreeNode(arr[m]);
        root->left=makeTree(arr,l,m-1);
        root->right=makeTree(arr,m+1,r);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>arr;
        while(head)
        {
            arr.push_back(head->val);
            head=head->next;
        }
        TreeNode* root=makeTree(arr,0,arr.size()-1);
        return root;
    }
};