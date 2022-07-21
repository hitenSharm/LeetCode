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
    
    ListNode* reversing(ListNode* head,int r,int cnt)
    {                
        ListNode* curr=head->next;
        ListNode* prev=head;
        while(cnt<r)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            cnt++;
        }
        head->next=curr;
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* curr=head;
        ListNode* prev=dummy;
        int cnt=1;
        while(cnt<left)
        {
            cnt++;
            curr=curr->next;
            prev=prev->next;
        }
        prev->next=reversing(curr,right,cnt);
        return dummy->next;
    }
};