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
    
    bool valid(ListNode* h,int k)
    {
        ListNode* t=h;
        while(k>0 and t)
        {
            t=t->next;
            k--;
        }
        return k==0;
    }
    
    ListNode* traverse(ListNode* h,int k)
    {
        if(!valid(h,k))return h;
        
        ListNode* fa=h->next;
        ListNode* sl=h;
        int tk=k;
        while(k>1) //as k nodes means k-1 reverals
        {
            ListNode* temp=fa->next;
            fa->next=sl;
            sl=fa;
            fa=temp;
            k--;
        }
        h->next=traverse(fa,tk);
        return sl;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=traverse(head,k);
        return dummy->next;
    }
};