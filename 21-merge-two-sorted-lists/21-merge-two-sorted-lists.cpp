/**
 * Definition for singly-linked list->
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)return list2;
        if(!list2)return list1;
        ListNode* head = (list1->val<=list2->val ? new ListNode(list1->val) : new ListNode(list2->val));
        if(head->val==list1->val)
            list1=list1->next;
        else
            list2=list2->next;
        ListNode* curr=head;
        while(list2 and list1)
        {
            curr->next = (list1->val<=list2->val ? new ListNode(list1->val) : new ListNode(list2->val));
            if(curr->next->val==list1->val)
                list1=list1->next;
            else
                list2=list2->next; 
            curr=curr->next;
        }
        while(list1)
        {
            curr->next=new ListNode(list1->val);
            curr=curr->next;
            list1=list1->next;
        }
        while(list2)
        {
            curr->next=new ListNode(list2->val);
            curr=curr->next;
            list2=list2->next;
        }
        return head;
    }
};