// https://leetcode.com/problems/merge-two-sorted-lists

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(INT_MIN);
        ListNode* prev=&dummy;
        while(l1 and l2)
        {
            if(l1->val<=l2->val)
            {
                prev->next=l1;
                l1=l1->next;
            }
            else
            {
                prev->next=l2;
                l2=l2->next;
            }
            prev=prev->next;
        }
        if(l1)prev->next=l1;
        else 
            prev->next=l2;
        return dummy.next;
    }
};