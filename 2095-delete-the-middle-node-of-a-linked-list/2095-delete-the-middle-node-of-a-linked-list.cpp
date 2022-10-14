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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next)return nullptr;
        ListNode* sl=head;
        ListNode* fa=head->next;
        while(fa)
        {
            if(!fa->next)break;
            fa=fa->next->next;
            if(!fa){
                break;
            }else{
                sl=sl->next;
            }
        }
        ListNode* t=sl->next;
        sl->next=t->next;t->next=nullptr;
        delete t;
        return head;
    }
};