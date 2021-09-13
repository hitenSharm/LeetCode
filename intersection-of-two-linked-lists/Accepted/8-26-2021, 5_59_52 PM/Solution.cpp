// https://leetcode.com/problems/intersection-of-two-linked-lists

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp=headA;
        int cntA=0;
        while(temp)
        {
            cntA++;
            temp=temp->next;
        }
        int cntB=0;
        temp=headB;
        while(temp)
        {
            cntB++;
            temp=temp->next;
        }
        while(cntB!=cntA)
        {
            if(cntA>cntB)
            {
                headA=headA->next;
                cntA--;
            }
            if(cntB>cntA)
            {
                headB=headB->next;
                cntB--;
            }
        }
        while(headB!=nullptr and headA!=nullptr)
        {
            if(headA==headB)return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return nullptr;
    }
};