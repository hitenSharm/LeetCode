// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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