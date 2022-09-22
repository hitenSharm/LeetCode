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
    ListNode* reverseList(ListNode* head) {
        if(!head)return head;
        ListNode* h=head;
        ListNode* nxt=h->next;
        h->next=nullptr;
        while(nxt)
        {
            ListNode* temp=nxt->next;
            nxt->next=h;
            h=nxt;
            nxt=temp;
        }
        return h;
    }
};