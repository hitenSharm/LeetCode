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

    ListNode* getMid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head)
    {
        if (!head)return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    void merge(ListNode* h1, ListNode* h2)
    {
        while(h2)
        {
            ListNode* temp=h1->next;
            h1->next=h2;
            ListNode* temp2=h2->next;
            h2->next=temp;
            h1=temp;
            h2=temp2;
        }
    }

    void reorderList(ListNode* head) {
        //get mid and cut into 2 halves
        //reverse from mid
        //merge the 2
        ListNode* mid = getMid(head);
        ListNode* head2 = reverseList(mid->next);        
        mid->next = nullptr;//cut the list  
        ListNode* temp=head;
        merge(temp, head2);        
    }
};