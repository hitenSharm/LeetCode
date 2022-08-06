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
        if(!head->next || !head)return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        while(n>0 and fast)
        {
            fast=fast->next;
            n--;
        }
        if(!fast)return head->next;
        while(fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }        
        ListNode* temp=slow->next;
        slow->next=temp->next;
        temp->next=nullptr;
        delete temp;
        return head;
    }
};