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
    
    ListNode* getMid(ListNode* h)
    {
        ListNode* slow=h;
        ListNode* fast=h->next;
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* mid=getMid(head);             
        ListNode* comp=reverse(mid->next);        
        mid->next=nullptr;//partiotion the lists
        while(head and comp)
        {            
            if(head->val!=comp->val)return false;
            head=head->next;
            comp=comp->next;
        }        
        int nodes=0;
        while(head)
        {            
            nodes++;
            head=head->next;
        }
        return nodes<=1;
    }
};