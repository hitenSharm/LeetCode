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
        ListNode* s=h;
        ListNode* f=s->next;
        while(f and f->next)
        {
            f=f->next->next;
            if(!f)break;
            s=s->next;
        }
        return s->next;        
    }
    
    ListNode* reversal(ListNode* c)
    {
        ListNode* prev=nullptr;
        while(c)
        {
            ListNode* temp=c->next;
            c->next=prev;
            prev=c;
            c=temp;
        }
        return prev;
    }
    //1 2 3 2 1
    //1 2 2 1
    bool isPalindrome(ListNode* head) {
        //get to middle        
        ListNode* midPrev=getMid(head);        
        //reverse from mid        
        ListNode* p2=reversal(midPrev);
        //check        
        while(p2)
        {
            if(head->val!=p2->val)return false;
            head=head->next;
            p2=p2->next;
        }
        return true;
    }
};