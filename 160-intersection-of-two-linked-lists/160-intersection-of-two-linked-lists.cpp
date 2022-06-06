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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=0,len2=0;
		ListNode* a=headA;
		ListNode* b=headB;
		while(a)
		{
			len1++;
			a=a->next;
		}
		while(b)
		{
			len2++;
			b=b->next;
		}
		a=headA;b=headB;
		while(len1!=len2)
		{
			if(len1>len2)
			{
				a=a->next;
				len1--;
			}
			else
			{
				b=b->next;len2--;
			}
		}
		while(a and b)
		{
			if(a==b)
			return a;
			a=a->next;b=b->next;
		}
		return NULL;
    }
};