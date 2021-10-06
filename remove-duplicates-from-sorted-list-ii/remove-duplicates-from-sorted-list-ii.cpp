class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next)return head;
        int value=head->val;
        ListNode* nxt=head->next;
        if(nxt->val!=value)
        {
            head->next=deleteDuplicates(nxt);
            return head;
        }
        else
        {
            while(nxt and value==nxt->val)
            {
                nxt=nxt->next;
            }
            return deleteDuplicates(nxt);
        }        
    }
};