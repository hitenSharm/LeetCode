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
    
    void deletingNode(ListNode* prev,ListNode* curr)
    {
        prev->next=curr->next;
        curr->next=nullptr;        
    }
    
    void insertingAtTail(ListNode* curr_tail,int value)
    {
        ListNode* curr_next=curr_tail->next;
        ListNode* newNode=new ListNode(value);
        curr_tail->next=newNode;
        newNode->next=curr_next;
    }
    
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* curr_tail=dummy;
        ListNode* curr=head;
        while(curr and curr->val<x)
        {
            curr_tail=curr;
            curr=curr->next;
        }
        //reached x start deleting and inserting at tail
        ListNode* prev=curr;
        //cout<<curr->val;
        while(curr)
        {
            if(curr->val<x)
            {
                int valueDeleted=curr->val;
                deletingNode(prev,curr);
                insertingAtTail(curr_tail,valueDeleted);
                curr_tail=curr_tail->next;
                curr=prev->next;
                continue ;
            }
            prev=curr;
            curr=curr->next;
        }
        return dummy->next;
    }
};