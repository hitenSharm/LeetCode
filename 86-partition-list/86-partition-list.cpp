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
    
//     void deletingNode(ListNode* prev,ListNode* curr)
//     {
//         prev->next=curr->next;
//         curr->next=nullptr;        
//     }
    
//     void insertingAtTail(ListNode* curr_tail,int value)
//     {
//         ListNode* curr_next=curr_tail->next;
//         ListNode* newNode=new ListNode(value);//this solution in worst case is o(n) space
//         curr_tail->next=newNode;
//         newNode->next=curr_next;
//     }
    
//     void o(n) solution{
//         ListNode* dummy=new ListNode(-1);
//         dummy->next=head;
//         ListNode* curr_tail=dummy;
//         ListNode* curr=head;
//         while(curr and curr->val<x)
//         {
//             curr_tail=curr;
//             curr=curr->next;
//         }
//         //reached x start deleting and inserting at tail
//         ListNode* prev=curr;        
//         while(curr)
//         {
//             if(curr->val<x)
//             {
//                 int valueDeleted=curr->val;
//                 deletingNode(prev,curr);
//                 insertingAtTail(curr_tail,valueDeleted);
//                 curr_tail=curr_tail->next;
//                 curr=prev->next;
//                 continue ;
//             }
//             prev=curr;
//             curr=curr->next;
//         }
//         return dummy->next;
//     }
    
    ListNode* partition(ListNode* head, int x) {
        //simpler soltuon is to make another list with all elements smaller than x
        //and another list with all elements greater than x
        //then merge them when we create a list pointer and do mergin in end its o(1) as it invloves pointer manipulation
        ListNode* l1=new ListNode(-1);
        ListNode* dummyHead=l1;
        ListNode* l2=new ListNode(-1);
        ListNode* l2head=l2;
        while(head)
        {
            if(head->val<x)
            {
                l1->next=head;
                l1=l1->next;
            }
            else
            {
                l2->next=head;
                l2=l2->next;
            }
            head=head->next;
        }
        l1->next=l2head->next;
        l2->next=nullptr;
        return dummyHead->next;
    }
};