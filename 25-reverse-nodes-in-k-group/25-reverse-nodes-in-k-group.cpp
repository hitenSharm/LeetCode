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
    
    bool kNodes(ListNode* h,int k)
    {
        if(!h)return false;
        while(k>0 and h)
        {
            h=h->next;
            k--;
        }
        return (k==0);
    }
    
    ListNode* recu(ListNode* head,int& k)
    {
        if(!kNodes(head,k) || !head->next)return head;        
        ListNode* newHead=head;        
        ListNode* headCurr=head->next;
        // cout<<headCurr->val<<" ";
        int tk=1;
        while(tk<=k-1)
        {
            ListNode* temp=headCurr->next;
            //cout<<temp->val<<" tmpp val ";
            headCurr->next=head;
            head=headCurr;
            headCurr=temp;
            tk++;
        }
        //cout<<head->val<<" ";
        newHead->next=recu(headCurr,k);
        return head;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        dummy->next=recu(dummy->next,k);
        return dummy->next;
    }
};