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
    
    ListNode* recu(ListNode* prev,ListNode* curr)
    {
        if(!curr)return prev;
        ListNode* temp=curr->next;
        curr->next=prev;
        return recu(curr,temp);
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* curr=head;
        
        return recu(prev,curr);        
        // while(curr)
        // {
        //     ListNode* temp=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=temp;
        // }
        // return prev;
    }
};