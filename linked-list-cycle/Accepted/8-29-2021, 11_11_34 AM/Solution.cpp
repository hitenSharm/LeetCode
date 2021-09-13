// https://leetcode.com/problems/linked-list-cycle

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
    bool hasCycle(ListNode *head) {
        if(!head)return false;
        while(head)
        {
            head->val=INT_MIN;
            if(head->next and head->next->val==INT_MIN)return true;
            head=head->next;
        }
        return false;
    }
};