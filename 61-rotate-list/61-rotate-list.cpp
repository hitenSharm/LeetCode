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
    
    int getLen(ListNode* h)
    {
        int l=0;
        while(h)
        {
            l++;
            h=h->next;
        }
        return l;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0)return head;
        int len=getLen(head);
        k=k%len;
        if(k==0)return head;
        ListNode* s=head;
        ListNode* f=head;
        while(k-- > 0)
        {
            f=f->next;
        }
        
        while(f->next)
        {
            f=f->next;
            s=s->next;
        }
        ListNode* newHead=s->next;
        s->next=nullptr;
        f->next=head;
        return newHead;
    }
};