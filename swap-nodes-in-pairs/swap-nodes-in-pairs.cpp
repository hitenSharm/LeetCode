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
    ListNode* h=nullptr;
    
    void recu(ListNode* sl,ListNode* sln,int fl)
    {
        if(!sl || !sln)return ;
        if(fl==0)
        {
            ListNode* tmp=sl;
            sl->next=sln->next;
            sln->next=tmp;  
            if(!h)h=sln;
            recu(sl,sl->next,1);
        }
        else
        {            
            ListNode* tmp=sl->next;
            if(!sln->next)return ;
            sl->next=sln->next;
            recu(tmp,sln->next,0);
        }
    }
    
    ListNode* swapPairs(ListNode* head) {
        if(!head)return head;
        ListNode* slow=head;
        ListNode* slowNext=head->next;
        recu(slow,slowNext,0);
        if(!h)h=head;
        return h;
    }
};