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

    ListNode* getMiddle(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode* l,ListNode* r)
    {
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;
        while(l and r)
        {
            if(l->val<r->val)
            {
                tail->next=l;
                l=l->next;
            }
            else
            {
                tail->next=r;
                r=r->next;
            }
            tail=tail->next;
        }
        while(l)
        {
            tail->next=l;
            l=l->next;
            tail=tail->next;
        }
        while(r)
        {
            tail->next=r;
            r=r->next;
            tail=tail->next;
        }
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)return head;
        
        ListNode* left=head;
        ListNode* right=getMiddle(head);
        ListNode* temp=right->next;//2nd half start
        right->next=nullptr;
        right=temp;//2nd half
        
        left=sortList(left);
        right=sortList(right);
        
        return merge(left,right);
    }
};