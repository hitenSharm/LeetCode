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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int temp=(l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        ListNode* ans = new ListNode(temp%10);
        int extra = temp/10;        
        ListNode* curr=ans;
        l1= (l1 ? l1->next : nullptr);
        l2= (l2 ? l2->next : nullptr);
        while(l1 || l2 || extra>0)
        {
            int newValue= (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;            
            curr->next=new ListNode(newValue%10);
            extra=newValue/10;
            curr=curr->next;
            l1= (l1 ? l1->next : nullptr);
            l2= (l2 ? l2->next : nullptr);
        }
        return ans;
    }
};