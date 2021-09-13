// https://leetcode.com/problems/linked-list-cycle-ii

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        while(slow!=nullptr and fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {                
                ListNode* ans=head;
                while(ans!=slow)
                {
                    ans=ans->next;
                    slow=slow->next;
                }
                return ans;
            }            
        }
        return nullptr;
    }
};