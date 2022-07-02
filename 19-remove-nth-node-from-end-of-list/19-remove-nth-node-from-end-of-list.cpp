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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return head;
        
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && n--)
        {
            fast=fast->next;
        }
        //cout<<fast->val<<" ";
        if(n>0)
            return head->next;
        while(fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* del=slow->next;
        slow->next=del->next;
        delete del;
        return head;
    }
};